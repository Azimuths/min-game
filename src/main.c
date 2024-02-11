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

int main (int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
    bool quit = false;
    game_t *game = NULL;
    /*
    * Initialises the SDL video subsystem (as well as the events subsystem).
    * Returns 0 on success or a negative error code on failure using SDL_GetError().
    */
    if (!(game = init())) {
        fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
        return GENERAL_ERROR;
    }
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
                quit = true;
        }
    }
    SDL_DestroyWindow(game->window);
    SDL_Quit();
    free(game);
    return SUCCESS;
}
