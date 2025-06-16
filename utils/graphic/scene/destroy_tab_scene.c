/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** destroy_tab_scene.c
*/

#include <stdlib.h>
#include "struct.h"
#include "libgraphic.h"

void free_tab_scene(game_t *game)
{
    for (int i = 0; i < game->nb_scene; i++)
        destroy_scene(game->tab_scene[i]);
    free(game->tab_scene);
    return;
}
