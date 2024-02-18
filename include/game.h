/*
** Cat card game
** game
** File description:
** game structure and functions
*/

#pragma once
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include "card.h"

typedef struct game_s game_t;

typedef struct game_s {
    SDL_Window *window;
    SDL_Renderer *renderer;
    card_t *cards;
    SDL_Rect rectangle;
    void (*draw_card) (game_t *game, struct card_s *card, int x, int y);
} game_t;
