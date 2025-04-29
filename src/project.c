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

static void create_window(window_t *window)
{
    sfVector2i dimensions = {DIM_X, DIM_Y};

    window->clock = sfClock_create();
    window->window = make_window(dimensions, BITS, NAME_WIN, STYLE_WIND);
    window->full_screen = false;
}

static void destroy_window(window_t *window)
{
    sfClock_destroy(window->clock);
    sfRenderWindow_destroy(window->window);
    free(window);
}

int project(void)
{
    window_t *window = malloc(sizeof(window_t));
    int status = EPI_SUCESS;

    if (window == NULL)
        return EPI_FAIL;
    memset(window, 1, sizeof(window_t));
    create_window(window);
    status = init_program(window);
    destroy_window(window);
    return status;
}
