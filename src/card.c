/*
** Cat card game
** game
** File description:
** card header
*/

#include "game.h"
#include "defines.h"

void draw_card(game_t *game, card_t *card, int x, int y)
{
    SDL_Rect rectangle = {x, y, CARD_WIDTH, CARD_HEIGHT};

    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(game->renderer, &rectangle);
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(game->renderer, &rectangle);
    SDL_RenderPresent(game->renderer);
}