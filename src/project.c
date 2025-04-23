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

static window_t *create_window(void)
{
    window_t *window = malloc(sizeof(window_t));
    sfVector2i dimensions = {DIM_X, DIM_Y};

    if (window == NULL)
        return NULL;
    memset(window, 1, sizeof(window_t));
    window->color = sfBlack;
    window->clock = sfClock_create();
    window->full_screen = false;
    window->frame = FPS;
    window->window = make_window(dimensions, BITS, NAME_WIN, STYLE_WIND);
    sfRenderWindow_setFramerateLimit(window->window, window->frame);
    return window;
}

static void destroy_window(window_t **window)
{
    sfClock_destroy((*window)->clock);
    sfRenderWindow_destroy((*window)->window);
    free((*window));
}

static game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return NULL;
    game->window = create_window();
    if (game->window == NULL) {
        free(game);
        return NULL;
    }
    game->nb_scene = NB_SCENE;
    game->actual_scene = NB_SCENE - 1;
    game->tab_scene = malloc(sizeof(scene_t) * (game->nb_scene + 1));
    if (game->tab_scene == NULL) {
        destroy_window(&game->window);
        free(game);
        return NULL;
    }
    game->tab_scene[game->nb_scene] = NULL;
    return game;
}

static void destroy_game(game_t **game)
{
    destroy_window(&((*game)->window));
    free((*game)->tab_scene);
    free((*game));
}

int project(void)
{
    game_t *game = init_game();
    int status = EPI_SUCESS;

    status = init_scene(game);
    destroy_game(&game);
    return status;
}
