#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include "Enemy.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Enemy::Enemy(Game* gameO, int x, int y) {
	game = gameO;
	pos_x = x;
	pos_y = y;
	enemybmp = SDL_LoadBMP("./enemy.bmp");
	move_right = 1;
	move_left = 0;
	move_delay = 0.2;
	srand(time(nullptr));
}
void Enemy::update() {
	if (game->array[int(pos_y / 30)][int(pos_x / 30)] %2==1 && game->array[int(pos_y / 30)][int(pos_x / 30)]!=1)
	{
		game->i++;
		game->number_of_enemy--;
		game->remove_shot(this);
	}
	else
	{
		if (move_delay >= 0.01)
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

		game->array[int(pos_y / 30)][int(pos_x / 30)]++;
	}
}
void Enemy::render()
{
	DrawSurface(game->screen, enemybmp, pos_x, pos_y);
}
