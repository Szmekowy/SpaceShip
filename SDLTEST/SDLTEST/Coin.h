#ifndef COIN_
#define COIN_
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
class Coin : public GameObject {
private:
	int pos_x;
	int pos_y;
	SDL_Surface* coinbmp;
	Game* game;
	int hit;
	double animation_delay;
public:
	Coin(Game* g, int x, int y);
	friend void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
	void update();
	void render();
};

#endif