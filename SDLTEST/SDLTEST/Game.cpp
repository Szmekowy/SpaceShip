#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include <vector>
#include <queue>
#include "Game.h"
#include "Spaceship.h"
#include "Shot.h"
#define SCREEN_WIDTH	1920
#define SCREEN_HEIGHT	1080

using namespace std;
Game::Game() 
{
	int rc;
	rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0,&window, &renderer);
	if (rc != 0) {
		SDL_Quit();
		printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
	};
	screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,SCREEN_WIDTH, SCREEN_HEIGHT);
	t2 = 0;
	delta = 0;
	t1 = SDL_GetTicks();
	frames = 0;
	fpsTimer = 0;
	fps = 0;
	quit = 0;
	worldTime = 0;
	distance = 0;
	etiSpeed = 1;
	czarny = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	zielony = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	czerwony = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	niebieski = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
	charset = SDL_LoadBMP("./cs8x8.bmp");
	eti = SDL_LoadBMP("./eti.bmp");
	change_position = 0;
	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 64; j++)
			array[i][j] = 0;
}
Game::~Game()
{
	SDL_FreeSurface(charset);
	SDL_FreeSurface(eti);
	SDL_FreeSurface(screen);
	SDL_DestroyTexture(scrtex);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}
void Game::init_game()
{
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_SetWindowTitle(window, "COSMIC ADVENTURE");
	SDL_ShowCursor(SDL_DISABLE);

	if (charset == NULL) {
		printf("SDL_LoadBMP(cs8x8.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	};
	SDL_SetColorKey(charset, true, 0x000000);
	if (eti == NULL) {
		printf("SDL_LoadBMP(eti.bmp) error: %s\n", SDL_GetError());
		SDL_FreeSurface(charset);
		SDL_FreeSurface(screen);
		SDL_DestroyTexture(scrtex);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	};
	SDL_FillRect(screen, NULL, czarny);

}
void Game::run(Spaceship& spaceship)
{
	while (!quit) {
		handle_event( spaceship);
		update();
		render();
	}
}
void Game::update()
{
	t2 = SDL_GetTicks();
	delta = (t2 - t1) * 0.001;
	t1 = t2;
	worldTime += delta;
	distance += etiSpeed * delta;
	fpsTimer += delta;
	if (fpsTimer > 0.5) {
		fps = frames * 2;
		frames = 0;
		fpsTimer -= 0.5;
	};
	frames++;
	for (auto obj : objects) {
		obj->update(); 
	}
	for (auto sh : shoots) {
		sh->update();
	}
}
void Game::handle_event(Spaceship &spaceship)
{
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
		///	else if (event.key.keysym.sym == SDLK_UP) {
			///	Shot* shot = new Shot(this,spaceship.pos_x,spaceship.pos_y+20);  // Tworzymy nowy obiekt Shot
			///	add_object(shot);
			///}
			///else if (event.key.keysym.sym == SDLK_RIGHT) change_position = 1;
			///else if (event.key.keysym.sym == SDLK_LEFT) change_position = -1;
			break;
		case SDL_KEYUP:
			etiSpeed = 1.0;
			break;
		case SDL_QUIT:
			quit = 1;
			break;
		};
		const Uint8* state = SDL_GetKeyboardState(NULL);
		if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_LCTRL]) {
			Shot* shot = new Shot(this, spaceship.pos_x, spaceship.pos_y + 20);  // Tworzymy nowy obiekt Shot
			add_object(shot);
			change_position = -1;
		}
		else if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_LCTRL])
		{
			Shot* shot = new Shot(this, spaceship.pos_x, spaceship.pos_y + 20);  // Tworzymy nowy obiekt Shot
			add_object(shot);
			change_position = 1;
		}
		else if (state[SDL_SCANCODE_RIGHT])
		{
			change_position = 1;
		}
		else if (state[SDL_SCANCODE_LEFT])
		{
			change_position = -1;
		}
		else if (state[SDL_SCANCODE_LCTRL])
		{
			Shot* shot = new Shot(this, spaceship.pos_x, spaceship.pos_y + 20);  // Tworzymy nowy obiekt Shot
			add_object(shot);
		}
		else
			change_position = 0;

	};
}
void Game :: render()
{
		SDL_FillRect(screen, NULL, czarny);
		for (auto obj : objects) {
			obj->render(); 
		}
		for (auto sh : shoots) {
			sh->render();
		}
		DrawRectangle(screen, 4, 4, SCREEN_WIDTH - 8, 36, czerwony, niebieski);
		sprintf(text, "Szablon drugiego zadania, czas trwania = %.1lf s  %.0lf klatek / s", worldTime, fps);
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 10, text, charset);
		sprintf(text, "Esc - wyjscie, \030 - przyspieszenie, \031 - zwolnienie");
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 26, text, charset);
		SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
		SDL_RenderCopy(renderer, scrtex, NULL, NULL);
		SDL_RenderPresent(renderer);
}
void Game::add_object(GameObject* object)
{
	objects.push_back(object);
}
void Game::shoot_s(GameObject* object)
{
	shoots.push_back(object);
}
void Game::remove_shot(GameObject* shot) {
	auto it = std::find(shoots.begin(), shoots.end(), shot);
	if (it != shoots.end()) {
		delete* it; 
		shoots.erase(it);  
	}
}

