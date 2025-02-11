#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include "Coin.h"
#include "Game.h"
#include <SDL_mixer.h>

using namespace std;

Coin::Coin(Game* gameO, int x, int y) {
	game = gameO;
	pos_x = x;
	pos_y = y;
	coinbmp = SDL_LoadBMP("./coin.bmp");
	hit = 0;
	animation_delay = 0.5;
}
void Coin::update() {
	pos_y++;
	if (pos_y > 1100)
	{
		game->i++;
		game->remove_shot(this);
	}
	else
	{
		for (int k = pos_x - 15; k < pos_x + 15; k++)
		{
			game->array[int(pos_y / 30)][k] += 4;
			if (game->array[int(pos_y / 30)][k] == 7)
			{
				Mix_Chunk* soundEffect = Mix_LoadWAV("money.wav");
				if (soundEffect == nullptr) {
					printf("Nie uda³o siê za³adowaæ efektu dŸwiêkowego: %s\n", Mix_GetError());
				}
				Mix_PlayChannel(-1, soundEffect, 0);
				game->money += 50;
				game->i++;
				game->remove_shot(this);
				return;
			}
		}
	}
}
void Coin::render()
{
	DrawSurface(game->screen, coinbmp, pos_x, pos_y);
}
