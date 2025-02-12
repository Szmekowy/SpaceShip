#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include <cstring>
#include "InfoScreen.h"
#include "Game.h"
#include <SDL_mixer.h>

using namespace std;

InfoScreen::InfoScreen(Game* gameO, char *tab)
{
    for (int i = 0; i < 128; i++)
    {
        news[i] = tab[i];
        text[i] = ' ';
    }
	game = gameO;
}
void InfoScreen::update() {

    DrawString(game->screen, (game->screen->w / 2 - strlen(text) * 8 / 2)-500, 540, text, game->charset);
    sprintf(text, news);
    render();
    int test=1;
    while (test) {
        while (SDL_PollEvent(&game->event)) {
            if (game->event.type == SDL_QUIT) {
                exit(0);
            }

            if (game->event.type == SDL_KEYDOWN) {
                if (game->event.key.keysym.sym == SDLK_SPACE) {
                    test = 0; 
                }
            }
        }

        SDL_Delay(16); 
    }
}
void InfoScreen::render()
{
    SDL_UpdateTexture(game->scrtex, NULL, game->screen->pixels, game->screen->pitch);
    SDL_RenderCopy(game->renderer, game->scrtex, NULL, NULL);
    SDL_RenderPresent(game->renderer);
}

