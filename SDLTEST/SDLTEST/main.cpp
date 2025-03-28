﻿#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>
#include<string.h>

#include <SDL.h>
#include <SDL_main.h>
#include "Game.h"
#include "Spaceship.h"
#include "Shot.h"
#include "Enemy.h"
#include "InfoScreen.h"
#include <SDL_mixer.h>


#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480

void DrawString(SDL_Surface* screen, int x, int y, const char* text,
	SDL_Surface* charset) {
	int px, py, c;
	SDL_Rect s, d;
	s.w = 8;
	s.h = 8;
	d.w = 8;
	d.h = 8;
	while (*text) {
		c = *text & 255;
		px = (c % 16) * 8;
		py = (c / 16) * 8;
		s.x = px;
		s.y = py;
		d.x = x;
		d.y = y;
		SDL_BlitSurface(charset, &s, screen, &d);
		x += 8;
		text++;
	};
};

void DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y) {
	SDL_Rect dest;
	dest.x = x - sprite->w / 2;
	dest.y = y - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
};

void DrawPixel(SDL_Surface* surface, int x, int y, Uint32 color) {
	int bpp = surface->format->BytesPerPixel;
	Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;
	*(Uint32*)p = color;
};

void DrawLine(SDL_Surface* screen, int x, int y, int l, int dx, int dy, Uint32 color) {
	for (int i = 0; i < l; i++) {
		DrawPixel(screen, x, y, color);
		x += dx;
		y += dy;
	};
};


void DrawRectangle(SDL_Surface* screen, int x, int y, int l, int k,
	Uint32 outlineColor, Uint32 fillColor) {
	int i;
	DrawLine(screen, x, y, k, 0, 1, outlineColor);
	DrawLine(screen, x + l - 1, y, k, 0, 1, outlineColor);
	DrawLine(screen, x, y, l, 1, 0, outlineColor);
	DrawLine(screen, x, y + k - 1, l, 1, 0, outlineColor);
	for (i = y + 1; i < y + k - 1; i++)
		DrawLine(screen, x + 1, i, l - 2, 1, 0, fillColor);
};

#ifdef __cplusplus
extern "C"
#endif
int main(int argc, char** argv) {
	
	

	
	printf("konfiguracyjne okno\n");
	printf("printf output goes here\n");

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		return 1;
	}

	Game game;
	Spaceship spaceshipObj(&game);
//	Enemy *enemy1 = new Enemy(&game, 200, 300);
//	Enemy* enemy2 = new Enemy(&game, 500, 300);
//	Enemy* enemy3 = new Enemy(&game, 1000, 400);
//	Enemy* enemy4 = new Enemy(&game, 200, 500);
	//Shot shoot(&game, 1100, 580);
	//game.shoot_s(&shoot);
	game.add_object(&spaceshipObj);
	//game.add_object(&shoot);
	
	game.init_game();
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cerr << "Błąd inicjalizacji SDL_mixer: " << Mix_GetError() << std::endl;
		SDL_Quit();
		return -1;
	}
	Mix_Music* music = Mix_LoadMUS("cosmic.mp3");  // Upewnij się, że plik muzyczny jest w tym samym folderze co .exe
	if (!music) {
		std::cerr << "Błąd ładowania pliku muzycznego: " << Mix_GetError() << std::endl;
		Mix_CloseAudio();
		SDL_Quit();
	}
	Mix_PlayMusic(music, -1);
	char news[128] = "Nacisnij spacje aby rozpoczac";
	InfoScreen* start = new InfoScreen(&game, news);
	start->update();
	delete start;
	game.init_enemy();
//	game.add_object(enemy1);
//	game.add_object(enemy2);
//	game.add_object(enemy3);
//	game.add_object(enemy4);
	game.run(spaceshipObj);
	for (int i = 0; i < 36; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			printf("%d ", game.array[i][j]);
		}
		printf("\n ");
	}

	SDL_Quit();
	return 0;
};
