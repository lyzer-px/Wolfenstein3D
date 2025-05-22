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
#include "libgraphic.h"


#include <stdio.h>

int loop(game_t *g)
{
    if (g->window->window == NULL)
        return EPI_FAIL;
    while (sfRenderWindow_isOpen(g->window->window)) {
        if (sfClock_getElapsedTime(g->window->clock).microseconds
            <= ELAPSED_TIME)
            continue;
        if (g->tab_scene[g->actual_scene]->hide_cursor == true) {
            sfRenderWindow_setMouseCursorVisible(g->window->window, sfTrue);
        } else {
            sfRenderWindow_setMouseCursorVisible(g->window->window, sfFalse);
        }
        sfRenderWindow_clear(g->window->window, sfBlack);
        draw_component_of_scene(g->window->window,
            g->tab_scene[g->actual_scene]);
        handle_event(g);
        sfRenderWindow_display(g->window->window);
        sfClock_restart(g->window->clock);
    }
    return EPI_SUCCESS;
}
