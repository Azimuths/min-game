/*
** Cat card game
** game
** File description:
** card header
*/

#include <SDL2/SDL_mouse.h>
#include <stdio.h>
#include "game.h"
#include "defines.h"

void draw_card(game_t *game, card_t card, float size)
{
    SDL_Rect rectangle = {card.card_x, card.card_y, CARD_WIDTH*size, CARD_HEIGHT*size};
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(game->renderer, &rectangle);
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(game->renderer, &rectangle);
    SDL_RenderPresent(game->renderer);
}


void draw_all_cards(game_t *game, int pos_x, int pos_y)
{
    float size = 1;
    for(int index_card = 0 ; index_card < MAX_CARD ; index_card++){
        size = mouse_in_card(game->cards[index_card], pos_x, pos_y, size);
        game->draw_card(game, game->cards[index_card], size);
    }
}

float mouse_in_card(card_t card, int pos_x, int pos_y, int size)
{
    if(pos_x > card.card_x && pos_x < card.card_x+CARD_WIDTH*size
    && pos_y > card.card_y && pos_y < card.card_y+CARD_HEIGHT*size)
        return 1.5;
    return 1;
}