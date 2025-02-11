#ifndef SHOT_
#define SHOT_
#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include "GameObject.h"
#include "Game.h"
#include "Spaceship.h"
#ifdef __cplusplus
extern "C"
#endif
using namespace std;
void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
class Shot : public GameObject {
private:
	int pos_x;
	int pos_y;
	SDL_Surface* shotbmp;
	Game* game;
	int hit;
	double animation_delay;
public:
	Shot(Game* g, int x, int y);
	friend void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
	void update();
	void render();
	friend class Spaceship;

};

#endif