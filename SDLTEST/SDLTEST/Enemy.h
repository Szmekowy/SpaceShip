#ifndef Enemy_
#define Enemy_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include "GameObject.h"
#include "Game.h"
#ifdef __cplusplus
extern "C"
#endif
using namespace std;
void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
class Enemy : public GameObject {
private:
	int pos_x;
	int pos_y;
	SDL_Surface* enemybmp;
	Game* game;
public:
	Enemy(Game* g, int x, int y);
	friend void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
	void update();
	void render();
};

#endif