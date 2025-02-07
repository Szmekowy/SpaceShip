#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include "Spaceship.h"
#include "Game.h"

using namespace std;

Spaceship::Spaceship(Game *g)
{
	game = g;
	spaceshipbmp = SDL_LoadBMP("./spaceship.bmp");
	pos_x = 1000;
	pos_y = 1065;
}
void Spaceship::update()
{
	pos_x += game->change_position;
}
void Spaceship::render()
{
	DrawSurface(game->screen, spaceshipbmp, pos_x, pos_y);
}
