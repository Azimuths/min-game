/*
** Cat card game
** game
** File description:
** main function file
*/

#include <stdio.h> /* printf and fprintf */
#include <stdbool.h> /* bool, true, and false */
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#include "defines.h" /* general defines */
#include "init.h" /* init functions */
#include "game.h" /* game struct */


int game_loop(game_t *game)
{
    double delta_time = 0;
    unsigned int a = SDL_GetTicks();
    unsigned int b = SDL_GetTicks();
    bool quit = false;

    while (!quit) {
        a = SDL_GetTicks();
        delta_time = a - b;
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
                quit = true;
        }
        if (delta_time > 1000 / 10) {
            b = a;
            game->draw_card(game, &game->cards[0], 0, 0);
        }
    }
    return SUCCESS;
}

int main (int argc, char *argv[])
{
    game_t *game = NULL;
    /*
    * Initialises the SDL video subsystem (as well as the events subsystem).
    * Returns 0 on success or a negative error code on failure using SDL_GetError().
    */
    if (!(game = init())) {
        fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
        return GENERAL_ERROR;
    }
    if (game_loop(game) != SUCCESS) {
        fprintf(stderr, "Game loop failed\n");
        return GENERAL_ERROR;
    }
    SDL_DestroyWindow(game->window);
    SDL_Quit();
    free(game);
    return SUCCESS;
}
