/*
** EPITECH PROJECT, 2025
** Woof3D
** File description:
** create_game_scene.c
*/

#include <stdlib.h>
#include <string.h>
#include "type_id.h"
#include "libgraphic.h"
#include "rendering.h"
#include "struct.h"

const sfColor sfNightSky = {11, 2, 64, 255};
const sfColor sfNightGround = {4, 64, 2, 255};

static void create_game_retangles(game_t *game, sfVector2f *size,
    sfVector2f *pos_bottom, sfVector2f *pos_top)
{
    sfRectangleShape *background_top = sfRectangleShape_create();
    sfRectangleShape *background_bottom = sfRectangleShape_create();

    create_ressource_link(&(game->ressource), "game_background_top",
        (void *)background_top, RECTANGLESHAPE);
    create_ressource_link(&(game->ressource), "game_background_bottom",
        (void *)background_bottom, RECTANGLESHAPE);
    sfRectangleShape_setSize(background_top, *size);
    sfRectangleShape_setSize(background_bottom, *size);
    sfRectangleShape_setFillColor(background_top, sfNightSky);
    sfRectangleShape_setFillColor(background_bottom, sfNightGround);
    add_a_component_to_layer(create_component(pos_top,
        find_a_ressouce_from_id(game->ressource, "game_background_top")),
        game->tab_scene[GAME], game->tab_scene[GAME]->layer->id);
    add_a_component_to_layer(create_component(pos_bottom,
        find_a_ressouce_from_id(game->ressource, "game_background_bottom")),
        game->tab_scene[GAME], game->tab_scene[GAME]->layer->id);
}

void create_game_scene(game_t *game)
{
    sfVector2f *size = calloc(1, sizeof(sfVector2f));
    sfVector2f *pos_top = calloc(1, sizeof(sfVector2f));
    sfVector2f *pos_bottom = calloc(1, sizeof(sfVector2f));

    game->tab_scene[GAME]->id_music = strdup(ID_MUSIC_MENU);
    if (pos_bottom == NULL || pos_top == NULL || size == NULL)
        return;
    size->x = DIM_X;
    size->y = DIM_Y / 2 + 30;
    pos_top->x = 0;
    pos_top->y = 0;
    pos_bottom->x = 0;
    pos_bottom->y = DIM_Y / 2 - 30;
    create_layer(game->tab_scene[GAME]);
    game->tab_scene[GAME]->function_event = tick_game;
    create_game_retangles(game, size, pos_bottom, pos_top);
    create_heart(game);
    init_text(game, "100%                                     6");
    free(size);
}
