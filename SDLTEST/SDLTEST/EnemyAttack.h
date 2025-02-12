#ifndef ENEMYATTACK_
#define ENEMYATTACK_
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
class EnemyAttack : public GameObject {
private:
	int pos_x;
	int pos_y;
	SDL_Surface* enemyattackbmp;
	Game* game;
public:
	EnemyAttack(Game* g, int x, int y);
	friend void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
	void update();
	void render();

};

#endif