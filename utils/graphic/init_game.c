/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** init_game.c
*/

#include <stdlib.h>
#include "struct.h"
#include "macro.h"
#include "libgraphic.h"

game_t *init_game(void)
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
    game->ressource = NULL;
    game->actual_scene = NB_SCENE - 1;
    game->tab_scene = init_tab_scene(game->nb_scene);
    if (game->tab_scene == NULL) {
        destroy_window(game->window);
        free(game);
        return NULL;
    }
    game->tab_scene[game->nb_scene] = NULL;
    return game;
}
