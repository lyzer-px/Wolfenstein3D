/*
** EPITECH PROJECT, 2024
** Woof3D
** File description:
** create_game_scene.c
*/

#include "type_id.h"
#include "struct.h"

static void create_game_retangles(game_t *game)
{
    sfRectangleShape *background = sfRectangleShape_create();
    sfVector2f size = {DIM_X, DIM_Y / 2};

    sfRectangleShape_setSize(background, size);
    sfRectangleShape_setFillColor(background, sfRed);
    create_ressource_link(&(game->ressource), "game_background",
        (void *)background, RECTANGLESHAPE);
}

void create_game_scene(game_t *game)
{
    create_game_background(game);
}