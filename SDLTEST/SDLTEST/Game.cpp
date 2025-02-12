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
#include "Enemy.h"
#include "InfoScreen.h"
#include "Shop.h"
#include <SDL_mixer.h>
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
	delay = 0.1;
	i = 1;
	number_of_enemy = 10;
	money = 0;
	type_of_ammo = 1;
	game_area();
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
		if(quit!=1)
		game_area();
		end_level();
	}
}
void Game::update()
{
	t2 = SDL_GetTicks();
	delta = (t2 - t1) * 0.001;
	t1 = t2;
	worldTime += delta;
	delay += delta;
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

	for (i; i <= number_of_enemy; i++) {
		objects[i]->update();
	}
	i = 1;

	
}
void Game::handle_event(Spaceship &spaceship)
{
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
		
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
			shoot(spaceship);
			change_position = -1;
		}
		else if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_LCTRL])
		{
			shoot(spaceship);
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
			shoot(spaceship);
			change_position = 0;
		}
		else
			change_position = 0;

	};
}
void Game::shoot(Spaceship& spaceship)
{
	if (delay > 0.1)
	{
		if (type_of_ammo == 1)
		{
			Shot* shot = new Shot(this, spaceship.pos_x, spaceship.pos_y - 40); 
			add_object(shot);
		}
		else if (type_of_ammo == 2)
		{
			Shot* shot1 = new Shot(this, spaceship.pos_x - 20, spaceship.pos_y - 40); 
			add_object(shot1);
			Shot* shot2 = new Shot(this, spaceship.pos_x +20, spaceship.pos_y - 40);  
			add_object(shot2);
		}
		else if (type_of_ammo == 3)
		{
			Shot* shot1 = new Shot(this, spaceship.pos_x - 20, spaceship.pos_y - 40);
			add_object(shot1);
			Shot* shot2 = new Shot(this, spaceship.pos_x + 20, spaceship.pos_y - 40);
			add_object(shot2);
			Shot* shot3 = new Shot(this, spaceship.pos_x, spaceship.pos_y - 40);
			add_object(shot3);
		}
		else if (type_of_ammo == 4)
		{
			Shot* shot1 = new Shot(this, spaceship.pos_x - 10, spaceship.pos_y - 40); 
			add_object(shot1);
			Shot* shot2 = new Shot(this, spaceship.pos_x + 10, spaceship.pos_y - 40);  
			add_object(shot2);
			Shot* shot3 = new Shot(this, spaceship.pos_x - 20, spaceship.pos_y - 40);  
			add_object(shot3);
			Shot* shot4 = new Shot(this, spaceship.pos_x + 20, spaceship.pos_y - 40); 
			add_object(shot4);
		}
		delay = 0;
		Mix_Chunk* soundEffect = Mix_LoadWAV("laser.wav");
		if (soundEffect == nullptr) {
			printf("Nie udało się załadować efektu dźwiękowego: %s\n", Mix_GetError());
		}
		Mix_PlayChannel(-1, soundEffect, 0);
	
	}
}
void Game :: render()
{
		SDL_FillRect(screen, NULL, czarny);
		for (auto obj : objects) {
			obj->render(); 
		}
		
		DrawRectangle(screen, 4, 4, SCREEN_WIDTH - 8, 36, czerwony, niebieski);
		sprintf(text, "Kosmiczna podróż czas trwania = %.1lf s  %.0lf klatek / s", worldTime, fps);
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 10, text, charset);
		sprintf(text, "Stan konta %.1lf zl", money);
		DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 26, text, charset);
		SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
		SDL_RenderCopy(renderer, scrtex, NULL, NULL);
		SDL_RenderPresent(renderer);
}
void Game::add_object(GameObject* object)
{
	objects.push_back(object);
}
void Game::remove_shot(GameObject* shot) {
	auto it = std::find(objects.begin(), objects.end(), shot);
	if (it != objects.end()) {
		delete* it;
		objects.erase(it);
	}
	
}
void Game::game_area()
{
	for (int i = 0; i < 36; i++)
		for (int j = 0; j < 1920; j++)
			array[i][j] = 0;
}
void Game::init_enemy()
{
	int x = 160;
	for (int i = 0; i < number_of_enemy/2; i++)
	{
		Enemy* enemy = new Enemy(this, x, 300);
		add_object(enemy);
		x += 75;
	}
	x = 190;
	for (int i = 0; i < number_of_enemy / 2; i++)
	{
		Enemy* enemy = new Enemy(this, x, 500);
		add_object(enemy);
		x += 75;
	}
}
void Game::end_level()
{
	if (number_of_enemy == 0)
	{
		SDL_FillRect(screen, NULL, czarny);
		char news[128] =  "Brawo ukonczyles poziom, nacisnij spacje aby kontynuowac" ;
		InfoScreen* level = new InfoScreen(this, news);
		level->update();
		SDL_FillRect(screen, NULL, czarny);
		Shop* shop = new Shop(this);
		shop->update();
		for (int j = objects.size() - 1; j > 0; j--) {
			delete objects[j];  
			objects.erase(objects.begin() + j);  
		}
		i = 1;
		number_of_enemy = 10;
		init_enemy();
		delete level;
		delete shop;
	}
}
