#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include "Enemy.h"
#include "Game.h"

using namespace std;

Enemy::Enemy(Game* gameO, int x, int y) {
	game = gameO;
	pos_x = x;
	pos_y = y;
	enemybmp = SDL_LoadBMP("./enemy.bmp");
}
void Enemy::update() {
	if(game->array[int(pos_y / 30)][int(pos_x / 30)]==2)
		game->remove_shot(this);
	game->array[int(pos_y / 30)][int(pos_x / 30)]=1;
}
void Enemy::render()
{
	DrawSurface(game->screen, enemybmp, pos_x, pos_y);
}
