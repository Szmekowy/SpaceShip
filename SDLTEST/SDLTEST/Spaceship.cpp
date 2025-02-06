#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include "Spaceship.h"
#include "Game.h"

using namespace std;

Spaceship::Spaceship(Game* gameInstance)
{
	 game = gameInstance;
	pos_x = 1000;
	pos_y = 1065;
}
void Spaceship::update()
{
	pos_y--;
	if (pos_y == 15)
		pos_y = 1000;
}
void Spaceship::render()
{
	DrawSurface(game->screen, game->spaceship, pos_x, pos_y);
}
