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
	std::cout << "Nowy shot: " << this << '\n';
}
void Shot::update() {
	pos_y--;  
	if (pos_y < 90) {
		game->remove_shot(this);  
	}
	else
	{
		
		game->array[int((pos_y) / 30)][int(pos_x / 30)]++;
	//	if (game->array[int(pos_y / 30)][int(pos_x / 30)] ==2)
		//	game->remove_shot(this);
	}
}
void Shot::render()
{
	DrawSurface(game->screen, shotbmp, pos_x, pos_y);
}
