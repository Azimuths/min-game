/*
** Cat card game
** game
** File description:
** card structure and functions
*/

#pragma once
#include "game.h"

typedef struct game_s game_t;
typedef enum card_type_e {
    TYPE1,
    TYPE2
} card_type_t;

typedef struct card_s {
    int value;
    int card_x;
    int card_y;
    char *name;
    card_type_t type;
} card_t;

void draw_card(game_t *game, card_t card, float size);
void draw_all_cards(game_t *game, int pos_x, int pos_y);
float mouse_in_card(card_t card, int pos_x, int pos_y, int size);
