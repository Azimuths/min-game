/*
** Cat card game
** game
** File description:
** init header
*/

#pragma once
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include "game.h"

game_t *init(void);
SDL_Window *init_window(void);
