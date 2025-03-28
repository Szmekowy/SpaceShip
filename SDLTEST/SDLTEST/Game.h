#ifndef GAME_
#define GAME_
#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include "GameObject.h"
#include <vector>
#include <queue>
#ifdef __cplusplus
extern "C"
#endif
using namespace std;
 void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
 void DrawLine(SDL_Surface* screen, int x, int y, int l, int dx, int dy, Uint32 color);
 void DrawRectangle(SDL_Surface* screen, int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor);
 void DrawPixel(SDL_Surface* surface, int x, int y, Uint32 color);
 void DrawString(SDL_Surface* screen, int x, int y, const char* text, SDL_Surface* charset);
 class Spaceshhip;
class Game {
private:
	int t1, t2, frames;
	double delay;
	double worldTime, fpsTimer, fps, distance, etiSpeed;
	char text[128];
	int czarny;
	int zielony;
	int czerwony;
	int niebieski;
	vector <GameObject*> objects;
	int level;
public:
	double shooting_intensity;
	int quit;
	int life;
	int object_iterator;
	int type_of_ammo;
	double money;
	double delta;
	int array[40][1920];
	int i;
	int number_of_enemy;
	friend void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
	friend void DrawString(SDL_Surface* screen, int x, int y, const char* text, SDL_Surface* charset);
	int change_position;
	SDL_Event event;
	SDL_Surface* screen, * charset;
	SDL_Surface* eti;
	SDL_Surface* heartbmp;
	SDL_Texture* scrtex;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Game();
	~Game();
	void add_object(GameObject*);
	void init_game();
	void update();
	void render();
	void remove_shot(GameObject*);
	friend class Spaceship;
	void handle_event(Spaceship& spaceship);
	void run(Spaceship& spaceship);
	void game_area();
	void shoot(Spaceship& spaceship);
	void init_enemy();
	void end_level();
	void actual_life();
};
#endif