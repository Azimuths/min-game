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
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return NULL;
    }
    game_t *game = malloc(sizeof(game_t));
    if (!game)
        return NULL;
    game->window = init_window();
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (!game->renderer) {
        fprintf(stderr, "SDL renderer failed to initialise: %s\n", SDL_GetError());
        return NULL;
    }
    game->rectangle = (SDL_Rect){0, 0, CARD_WIDTH, CARD_HEIGHT};
    game->draw_card = draw_card;
    return game;
}
