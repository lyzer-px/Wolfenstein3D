/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** init_game.c
*/

#include <stdlib.h>
#include "struct.h"
#include "macro.h"
#include "rendering.h"
#include "libgraphic.h"

static void fill_fields(game_t *game)
{
    game->rect = sfRectangleShape_create();
    if (game->rect == NULL)
        return;
    game->nb_scene = NB_SCENE;
    game->ressource = NULL;
    game->actual_scene = MENU;
    game->tab_scene = init_tab_scene(game->nb_scene);
}

static void *nfree(void *ptr)
{
    free(ptr);
    return NULL;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return NULL;
    game->window = create_window();
    if (game->window == NULL)
        return nfree(game);
    game->bounds = init_map();
    if (game->bounds == NULL)
        return NULL;
    game->player = calloc(1, sizeof(player_t));
    init_player(game->player);
    init_ray(game->player);
    fill_fields(game);
    if (game->tab_scene == NULL) {
        destroy_window(game->window);
        return nfree(game);
    }
    game->tab_scene[game->nb_scene] = NULL;
    return game;
}
