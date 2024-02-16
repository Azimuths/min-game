/*
** Cat card game
** game
** File description:
** init file
*/

#include <SDL2/SDL.h>/* macOS- and GNU/Linux-specific */
#include <errno.h>
#include <stdio.h>
#include "defines.h"
#include "game.h"


SDL_Window *init_window(void)
{
    SDL_Window *window = NULL;
    window = SDL_CreateWindow("SDL Example", /* Title of the SDL window */
                  SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
                  SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
                  WIDTH, /* Width of the window in pixels */
                  HEIGHT, /* Height of the window in pixels */
                  0); /* Additional flag(s) */
    if (window == NULL) {
      fprintf(stderr, "SDL window failed to initialise: %s\n", SDL_GetError());
      return NULL;
    }
    return window;
}

game_t *init(void)
{
    game_t *game = malloc(sizeof(game_t));
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return NULL;
    }
    game->window = init_window();
    return game;
}
