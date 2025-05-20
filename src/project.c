/*
** EPITECH PROJECT, 2024
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

int wolf3d(void)
{
    game_t *game = init_game();
    int status = EPI_SUCCESS;

    load_config_file(game);
    status = init_scene(game);
    destroy_game(game);
    return status;
}
