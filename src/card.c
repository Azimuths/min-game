/*
** Cat card game
** game
** File description:
** card header
*/

#include <SDL2/SDL_mouse.h>
#include "game.h"
#include "defines.h"

void draw_card(game_t *game, card_t *card, int x, int y, float size)
{
    SDL_Rect rectangle = {x, y, CARD_WIDTH*size, CARD_HEIGHT*size};
    card->card_x = x;
    card->card_y = y;
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(game->renderer, &rectangle);
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(game->renderer, &rectangle);
    SDL_RenderPresent(game->renderer);
}

bool mouse_in_card(card_t card, Sint32 pos_x, Sint32 pos_y, int size)
{
    return(pos_x > card.card_x && pos_x < card.card_x+CARD_WIDTH*size
    && pos_y > card.card_y && pos_y < card.card_y+CARD_HEIGHT*size);
}