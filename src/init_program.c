/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_program.c
*/

#include <stdlib.h>
#include <string.h>
#include "macro.h"
#include "struct.h"
#include "project_funct.h"
#include "libgraphic.h"

static void create_scenes(game_t *game)
{
    create_game_scene(game);
    create_error_scene(game);
    init_pause_menu(game);
    init_start_menu(game);
    for (size_t i = 0; i < NB_SCENE; i++)
        if (game->tab_scene[i]->id_music == NULL)
            game->tab_scene[i]->id_music = strdup(ID_MUSIC_MENU);
}

int init_scene(game_t *game)
{
    int status = EPI_SUCCESS;

    create_scenes(game);
    if (status == EPI_SUCCESS)
        status = loop(game);
    return status;
}
