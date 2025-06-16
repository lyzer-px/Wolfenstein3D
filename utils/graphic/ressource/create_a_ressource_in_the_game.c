/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** create_a_ressource_in_the_game.c
*/

#include "struct.h"
#include "libgraphic.h"

void create_a_ressource_in_the_game(game_t *game, char *id,
    void *element, int type)
{
    create_ressource_link(&(game->ressource), id, element, type);
    return;
}
