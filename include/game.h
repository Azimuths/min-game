/*
** Cat card game
** game
** File description:
** game structure and functions
*/

#pragma once
#include <SDL2/SDL.h>
#include "card.h"

typedef struct game_s {
    SDL_Window *window;
    SDL_Renderer *renderer;
    card_t *cards;
} game_t;
