#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include <cstring>
#include "Shop.h"
#include "Game.h"
#include <SDL_mixer.h>

using namespace std;

Shop::Shop(Game* gameO)
{
    game = gameO;
    prices[0] = 200;
    prices[1] = 300;
    prices[2] = 400;
    prices[3] = 500;
}
void Shop::update() {
    char text[128] = { ' ' };
    DrawString(game->screen, (game->screen->w / 2 - strlen(text) * 8 / 2) - 600, 230, text, game->charset);
    sprintf(text, "Aby wybrac wybierz numer na klawiaturze, spacja zakonczy zakup");
    DrawString(game->screen, (game->screen->w / 2 - strlen(text) * 8 / 2) - 500, 330, text, game->charset);
    sprintf(text, "Wyberz przedmioty do kupienia");
    DrawString(game->screen, (game->screen->w / 2 - strlen(text) * 8 / 2) - 500, 380, text, game->charset);
    sprintf(text, "double %d zl", prices[0]);
    DrawString(game->screen, (game->screen->w / 2 - strlen(text) * 8 / 2) - 500, 430, text, game->charset);
    sprintf(text, "triple shot %d zl", prices[1]);
    DrawString(game->screen, (game->screen->w / 2 - strlen(text) * 8 / 2) - 500, 480, text, game->charset);
    sprintf(text, "quad shot %d zl", prices[2]);
    render();
    int test = 1;
    while (test) {
        while (SDL_PollEvent(&game->event)) {
            if (game->event.type == SDL_QUIT) {
                exit(0);
            }

            if (game->event.type == SDL_KEYDOWN) {
                if (game->event.key.keysym.sym == SDLK_SPACE) {
                    test = 0;
                }
                if (game->event.key.keysym.sym == SDLK_q) {
                    if (game->money >= prices[0])
                    {
                        cout << "kupilem";
                        game->money -= prices[0];
                        game->type_of_ammo = 2;
                    }
                }
                if (game->event.key.keysym.sym == SDLK_w) {
                    if (game->money >= prices[1])
                    {
                        game->money -= prices[1];
                        game->type_of_ammo = 3;
                    }
                }
                if (game->event.key.keysym.sym == SDLK_e) {
                    if (game->money >= prices[2])
                    {
                        game->money -= prices[2];
                        game->type_of_ammo = 4;
                    }
                }
            }

        }

        SDL_Delay(16);
    }
}
void Shop::render()
{
    SDL_UpdateTexture(game->scrtex, NULL, game->screen->pixels, game->screen->pitch);
    SDL_RenderCopy(game->renderer, game->scrtex, NULL, NULL);
    SDL_RenderPresent(game->renderer);
}

