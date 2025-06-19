/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** init_game.c
*/

#include <stdlib.h>
#include <stdio.h>
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
    game->actual = SCENE_START;
    game->tab_scene = init_tab_scene(game->nb_scene);
}

static void *nfree(void *ptr)
{
    free(ptr);
    return NULL;
}

static void init_settings(game_t *game)
{
    game->settings = malloc(sizeof(settings_t));
    if (game->settings == NULL)
        return;
    game->settings->fxaudio_nb = 100;
    game->settings->music_nb = 100;
    game->settings->fxaudio_played = true;
    game->settings->music_played = true;
    return;
}

static void init_for_raycast(game_t *game)
{
    game->mini_map = init_map(game);
    if (game->mini_map == NULL || game->mini_map[0] == NULL)
        return;
    game->player = calloc(1, sizeof(player_t));
    init_player(game->player);
    init_ray(game->player);
    fill_fields(game);
    return;
}

game_t *init_game(char **argv)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return NULL;
    game->window = create_window();
    game->ressource = NULL;
    game->music = NULL;
    game->id_music = NULL;
    if (game->window == NULL)
        return nfree(game);
    if (map_load(argv[1], game) == -1)
        return nullptr;
    init_for_raycast(game);
    init_settings(game);
    if (game->tab_scene == NULL) {
        destroy_window(game->window);
        return nfree(game);
    }
    game->tab_scene[game->nb_scene] = NULL;
    return game;
}
