#ifndef GAME_
#define GAME_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
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
class Game {
private:
	int t1, t2, quit, frames;
	double delta, worldTime, fpsTimer, fps, distance, etiSpeed;
	char text[128];
	int czarny;
	int zielony;
	int czerwony;
	int niebieski;
	vector <GameObject*> objects;
	vector <GameObject*> shoots;
public:
	friend void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y);
	friend void DrawString(SDL_Surface* screen, int x, int y, const char* text, SDL_Surface* charset);
	int change_position;
	SDL_Event event;
	SDL_Surface* screen, * charset;
	SDL_Surface* eti;
	SDL_Texture* scrtex;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Game();
	~Game();
	void add_object(GameObject*);
	void init_game();
	void run();
	void handle_event();
	void update();
	void render();
	void shoot_s(GameObject*);
};
#endif