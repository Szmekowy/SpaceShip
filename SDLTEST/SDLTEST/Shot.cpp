#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include "Shot.h"
#include "Game.h"

using namespace std;

Shot::Shot(Game* gameO, int x, int y) {
	game = gameO;
	pos_x = x;
	pos_y = y;
	shotbmp = SDL_LoadBMP("./shot.bmp");
	hit = 0;
	animation_delay = 0.5;
}
void Shot::update() {
	pos_y--;  
	if (pos_y < 90) {
		game->remove_shot(this);  
	}
	else
	{
		if(!hit)
		game->array[int((pos_y+5) / 30)][int((pos_x+5) / 30)]+=2;
		if (game->array[int((pos_y + 5) / 30)][int((pos_x + 5) / 30)] % 2 == 1)
		{
			if (!hit)
				animation_delay = 0;
			hit = 1;
		}
		animation_delay += game->delta;
	}
	if (hit)
	{
		if (animation_delay < 0.1)
			shotbmp = SDL_LoadBMP("./bum.bmp");
		else
			shotbmp = SDL_LoadBMP("./empty_shot.bmp");
	}
}
void Shot::render()
{
	DrawSurface(game->screen, shotbmp, pos_x, pos_y);
}
