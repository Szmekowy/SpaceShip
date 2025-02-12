#ifndef SHOP_
#define SHOP_
#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include "GameObject.h"
#include "Game.h"
#ifdef __cplusplus
extern "C"
#endif
using namespace std;

class Shop : public GameObject {
private:
	Game* game;
	int prices[4];
public:
	Shop(Game* g);
	void update();
	void render();
};

#endif