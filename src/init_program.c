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

int init_scene(game_t *game)
{
    int status = 0;

    if (status == EPI_SUCESS)
        status = loop(game);
    return status;
}
