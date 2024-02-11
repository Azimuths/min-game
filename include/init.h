/*
** Cat card game
** game
** File description:
** init header
*/

#pragma once
#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif
#include "game.h"

game_t *init(void);
SDL_Window *init_window(void);
