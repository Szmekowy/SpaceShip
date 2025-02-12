#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include "EnemyAttack.h"
#include "Game.h"

using namespace std;

EnemyAttack::EnemyAttack(Game* gameO, int x, int y) {
	game = gameO;
	pos_x = x;
	pos_y = y;
	enemyattackbmp = SDL_LoadBMP("./enemyattack.bmp");

}
void EnemyAttack::update() {
	pos_y++;
	if (pos_y > 1080) {
		game->object_iterator++;
		game->remove_shot(this);
	}
	else
	{
			game->array[int((pos_y + 5) / 30)][pos_x] += 3;
	}
	
}
void EnemyAttack::render()
{
	DrawSurface(game->screen, enemyattackbmp, pos_x, pos_y);
}
