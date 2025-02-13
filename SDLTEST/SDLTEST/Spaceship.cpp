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
	if (game->change_position == -1)
	{
		if (pos_x > 150)
			pos_x--;
	}
	else if(game->change_position == 1)
	{
		if (pos_x < 1830)
			pos_x++;
	}
	for (int k = pos_x - 15; k < pos_x + 15; k++)
	game->array[int(pos_y / 30)][k]+=3;

}
void Spaceship::render()
{
	DrawSurface(game->screen, spaceshipbmp, pos_x, pos_y);
}

