/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** clean_game.c
*/

#include "struct.h"
#include "libgraphic.h"

void clean_game(game_t *game)
{
    for (int i = 0; i < game->nb_scene; i++)
        destroy_scene(game->tab_scene[i]);
    destroy_window(game->window);
    return;
}
