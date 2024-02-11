/*
** Cat card game
** game
** File description:
** game structure and functions
*/

#pragma once
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
#include "card.h"

typedef struct game_s {
    SDL_Window *window;
    SDL_Renderer *renderer;
    card_t *cards;
} game_t;
