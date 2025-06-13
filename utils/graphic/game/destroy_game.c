/*
** EPITECH PROJECT, 2025
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
    free(game->settings);
    free_tab_scene(game);
    destroy_all_music(game);
    destroy_all_ressource(&(game->ressource));
    if (game->id_music != NULL)
        free(game->id_music);
    free(game);
    return;
}
