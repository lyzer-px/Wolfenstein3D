/*
** EPITECH PROJECT, 2024
** wolf3d
** File description:
** loop.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "project_funct.h"
#include "macro.h"

int loop(window_t *win, int **map)
{
    if (win->window == NULL)
        return EPI_FAIL;
    while (sfRenderWindow_isOpen(win->window)) {
        if (sfClock_getElapsedTime(win->clock).microseconds <= ELAPSED_TIME)
            continue;
        handle_event(win);
        sfRenderWindow_clear(win->window, sfBlack);
        draw_floor_and_ceiling(win->window);
        sfRenderWindow_display(win->window);
        sfClock_restart(win->clock);
    }
    return EPI_SUCESS;
}
