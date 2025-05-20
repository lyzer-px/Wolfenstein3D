/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** destroy_game.c
*/

#include <stdlib.h>
#include "struct.h"
#include "libgraphic.h"

#include <stdio.h>

void destroy_game(game_t *game)
{
    destroy_window(game->window);
    free_tab_scene(game);
    destroy_all_ressource(&(game->ressource));
    free(game);
    return;
}
