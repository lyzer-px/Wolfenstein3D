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

int project(void)
{
    window_t *window = malloc(sizeof(window_t));
    sfVector2i dimensions = {DIM_X, DIM_Y};
    int status = EPI_SUCESS;

    if (window == NULL)
        return EPI_FAIL;
    memset(window, 1, sizeof(window_t));
    window->frame = FPS;
    window->clock = sfClock_create();
    window->window = make_window(dimensions, BITS, NAME_WIN, STYLE_WIND);
    window->full_screen = false;
    status = init_program(window);
    sfClock_destroy(window->clock);
    sfRenderWindow_destroy(window->window);
    free(window);
    return status;
}
