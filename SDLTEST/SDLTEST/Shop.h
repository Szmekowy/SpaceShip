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

class InfoScreen : public GameObject {
private:
	Game* game;
	char text[128];
	char news[128];
public:
	InfoScreen(Game* g, char tab[]);
	void update();
	void render();

};

#endif