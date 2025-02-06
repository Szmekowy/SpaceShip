#ifndef SPACESHIP_
#define SPACESHIP_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include "GameObject.h"
#include "Game.h"
#ifdef __cplusplus
extern "C"
#endif
using namespace std;

class Spaceship : public GameObject {
private:
	int pos_x;
	int pos_y;
	Game* game;
public:
	 Spaceship(Game* gameInstance);
	 void update() override;
	 void render() override;

};

#endif