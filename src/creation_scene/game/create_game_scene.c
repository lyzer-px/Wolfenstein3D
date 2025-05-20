/*
** EPITECH PROJECT, 2024
** Woof3D
** File description:
** create_game_scene.c
*/

#include <stdlib.h>
#include "type_id.h"
#include "libgraphic.h"
#include "rendering.h"
#include "struct.h"

static void create_game_retangles(game_t *game)
{
    sfRectangleShape *background = sfRectangleShape_create();
    sfRectangleShape *tile = sfRectangleShape_create();
    sfVector2f size = {DIM_X, DIM_Y / 2};

    create_ressource_link(&(game->ressource), "game_background",
        (void *)background, RECTANGLESHAPE);
    create_ressource_link(&(game->ressource), "game_tile",
        (void *)background, RECTANGLESHAPE);
    sfRectangleShape_setSize(background, size);
    sfRectangleShape_setSize(tile, (sfVector2f){TILE_SIZE, TILE_SIZE});
    sfRectangleShape_setFillColor(background, sfCyan);
    sfRectangleShape_setFillColor(tile, sfBlack);
    game->tab_scene[GAME]->layer->component = create_component(&(sfVector2f){0, 0}, find_a_ressouce_from_id(game->ressource, "game_background"));
}

void create_game_scene(game_t *game)
{
    create_layer(game->tab_scene[GAME]);
    // game->tab_scene[GAME]->function_event = update_player;
    create_game_retangles(game);
}