/*
** Cat card game
** game
** File description:
** init file
*/

#include <SDL2/SDL.h>
#include <errno.h>
#include "defines.h"
#include "game.h"

game_t init(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return NULL;
    }
    return SUCCESS;
}

SDL_Window *init_window()
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