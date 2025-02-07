#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include "Shot.h"
#include "Game.h"

using namespace std;

Shot::Shot(Game* g, int x, int y)
{
	game = g;
	shotbmp = SDL_LoadBMP("./shot.bmp");
	pos_x = x;
	pos_y = y;
}
void Shot::update()
{
	pos_y++;
	if (pos_y == 1080)
		pos_y = 0;
}
void Shot::render()
{
	DrawSurface(game->screen, shotbmp, pos_x, pos_y);
}
