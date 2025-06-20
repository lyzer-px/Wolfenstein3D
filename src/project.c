/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** wolf3d.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "macro.h"
#include "struct.h"
#include "project_funct.h"
#include "libgraphic.h"

int wolf3d(char **argv)
{
    game_t *game = init_game(argv);
    int status = EPI_SUCCESS;

    if (game == nullptr)
        return EPI_FAIL;
    load_config_music(game);
    load_config_file(game);
    status = init_scene(game);
    destroy_game(game);
    return status;
}
