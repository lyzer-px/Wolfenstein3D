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

int loop(game_t *game)
{
    if (game->window->window == NULL)
        return EPI_FAIL;
    while (sfRenderWindow_isOpen(game->window->window)) {
        if (sfClock_getElapsedTime(game->window->clock).microseconds
            <= ELAPSED_TIME)
            continue;
        handle_event(game);
        sfRenderWindow_clear(game->window->window, sfBlack);
        draw_composant_of_scene(game->window->window,
                game->tab_scene[game->actual_scene]);
        sfRenderWindow_display(game->window->window);
        sfClock_restart(game->window->clock);
    }
    return EPI_SUCESS;
}
