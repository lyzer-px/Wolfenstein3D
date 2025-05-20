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
    sfRectangleShape *background_top = sfRectangleShape_create();
    sfRectangleShape *background_bottom = sfRectangleShape_create();
    sfVector2f *size = calloc(1, sizeof(sfVector2f));
    sfVector2f *pos_top = calloc(1, sizeof(sfVector2f));
    sfVector2f *pos_bottom = calloc(1, sizeof(sfVector2f));

    // *tile_size = (sfVector2f){TILE_SIZE, TILE_SIZE};
    size->x = DIM_X;
    size->y = DIM_Y / 2;
    pos_top->x = 0;
    pos_top->y = 0;
    pos_bottom->x = 0;
    pos_bottom->y = DIM_Y / 2;


    create_ressource_link(&(game->ressource), "game_background_top",
        (void *)background_top, RECTANGLESHAPE);
    create_ressource_link(&(game->ressource), "game_background_bottom",
        (void *)background_bottom, RECTANGLESHAPE);

    sfRectangleShape_setSize(background_top, *size);
    sfRectangleShape_setSize(background_bottom, *size);

    sfRectangleShape_setFillColor(background_top, sfCyan);
    sfRectangleShape_setFillColor(background_bottom, sfGreen);
    add_a_component_to_layer(create_component(pos_top, find_a_ressouce_from_id(game->ressource, "game_background_top")), game->tab_scene[GAME], game->tab_scene[GAME]->layer->id);
    add_a_component_to_layer(create_component(pos_bottom, find_a_ressouce_from_id(game->ressource, "game_background_bottom")), game->tab_scene[GAME], game->tab_scene[GAME]->layer->id);
}

void create_game_scene(game_t *game)
{
    create_layer(game->tab_scene[GAME]);
    game->tab_scene[GAME]->function_event = update_player;
    create_game_retangles(game);
}