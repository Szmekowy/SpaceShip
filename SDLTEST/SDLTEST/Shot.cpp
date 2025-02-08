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
void Shot::update() {
	pos_y--;  // Pocisk porusza si� w g�r�
	if (pos_y < 0) {  // Je�li przekroczy� g�rn� kraw�d�
		game->remove_shot(this);  // Powiadomienie `Game` o usuni�ciu
	}
	else 
	game->array[int((pos_y) / 30)][int(pos_x / 30)]++;
}
void Shot::render()
{
	DrawSurface(game->screen, shotbmp, pos_x, pos_y);
}
