/*
** EPITECH PROJECT, 2024
** wolf3d
** File description:
** init_program.c
*/

#include <stdlib.h>
#include "macro.h"
#include "struct.h"
#include "project_funct.h"
#include "libgraphic.h"

static void create_scenes(game_t *game)
{
    create_game_scene(game);
    create_error_scene(game);
}

int init_scene(game_t *game)
{
    int status = 0;

    create_scenes(game);
    if (status == EPI_SUCESS)
        status = loop(game);
    return status;
}
