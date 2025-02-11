#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include "Coin.h"
#include "Game.h"

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
		game->array[int(pos_y / 30)][int(pos_x / 30)] += 6;
		if (game->array[int(pos_y / 30)][int(pos_x / 30)] == 7)
		{
			game->money += 50;
			game->i++;
			game->remove_shot(this);
		}
	}
}
void Coin::render()
{
	DrawSurface(game->screen, coinbmp, pos_x, pos_y);
}
