/*
** Cat card game
** game
** File description:
** card structure and functions
*/

#pragma once

typedef enum card_type_e {
    TYPE1,
    TYPE2
} card_type_t;

typedef struct card_s {
    int value;
    char *name;
    card_type_t type;
} card_t;
