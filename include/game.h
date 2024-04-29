/*
** Cat card game
** game
** File description:
** game structure and functions
*/

#pragma once
#include <stdbool.h> /* bool, true, and false */
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include "card.h"

typedef struct game_s game_t;

typedef struct game_s {
    SDL_Window *window;
    SDL_Renderer *renderer;
    card_t *cards;
    SDL_Rect rectangle;
    void (*draw_card) (game_t *game, card_t card, float size);
} game_t;
