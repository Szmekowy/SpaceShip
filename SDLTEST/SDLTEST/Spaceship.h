#ifndef SPACESHIP_
#define SPACESHIP_
#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include "GameObject.h"
#include "Game.h"
#ifdef __cplusplus
extern "C"
#endif
using namespace std;
void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
class Shot;
class Spaceship : public GameObject {
private:
	SDL_Surface* spaceshipbmp;
	Game *game;
public:
	int pos_x;
	int pos_y;
	Spaceship(Game *g);
	friend void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
	 void update();
	 void render();

	 friend class Shot;


};

#endif