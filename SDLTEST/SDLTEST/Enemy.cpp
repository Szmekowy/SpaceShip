#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include "Enemy.h"
#include "Game.h"
#include <cstdlib>
#include <SDL_mixer.h>
#include <ctime>
#include "Coin.h"
#include "EnemyAttack.h"

using namespace std;

Enemy::Enemy(Game* gameO, int x, int y) {
	game = gameO;
	pos_x = x;
	pos_y = y;
	enemybmp = SDL_LoadBMP("./enemy.bmp");
	move_right = 1;
	move_left = 0;
	move_delay = 0.2;
	shot_delay = 1;
}
void Enemy::update() {
	move();
	for (int k = pos_x - 15; k < pos_x + 15; k++)
	{
		if (game->array[int(pos_y / 30)][k]  == 3 && game->array[int(pos_y / 30)][k] != 1)
		{
			Mix_Chunk* soundEffect = Mix_LoadWAV("explosion.wav");
			if (soundEffect == nullptr) {
				printf("Nie uda³o siê za³adowaæ efektu dŸwiêkowego: %s\n", Mix_GetError());

			}
			Mix_PlayChannel(-1, soundEffect, 0);
			int a = rand() % 10;
			if (a > 5)
				coin();
			game->i++;
			game->number_of_enemy--;
			game->remove_shot(this);
			return;
		}
		else
		{
				game->array[int(pos_y / 30)][k]++;
			
				if (shot_delay > 2)
				{
					shot_delay = 0;
					int p = rand() % 10;
					if (p > 5)
					{
						EnemyAttack* shot = new EnemyAttack(game, pos_x, pos_y + 20);
						game->add_object(shot);
					}
				}
				
		}
	}
	
}
void Enemy::render()
{
	DrawSurface(game->screen, enemybmp, pos_x, pos_y);
}
void Enemy::coin()
{
	Coin* coin = new Coin(game, pos_x, pos_y);
	game->add_object(coin);
}
void Enemy::move()
{
	if (move_delay >= 0.05)
	{
		if (move_right)
		{
			pos_x++;
			move_right++;
		}
		if (move_left)
		{
			pos_x--;
			move_left++;
		}
		if (move_right > 60)
		{
			move_right = 0;
			move_left = 1;
		}
		if (move_left > 60)
		{
			move_right = 1;
			move_left = 0;
		}
		move_delay = 0;
	}
	move_delay += game->delta;
	shot_delay += game->delta;
}
