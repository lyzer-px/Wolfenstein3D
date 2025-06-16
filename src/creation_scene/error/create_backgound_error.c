/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** create_backgound_error_ressource.c
*/

#include "struct.h"
#include "macro.h"
#include "libgraphic.h"
#include "type_id.h"

void create_backgound_error_ressource(game_t *game)
{
    sfRectangleShape *background = sfRectangleShape_create();
    sfVector2f size = {DIM_X * 5, DIM_Y * 5};

    sfRectangleShape_setSize(background, size);
    sfRectangleShape_setFillColor(background, sfRed);
    create_ressource_link(&(game->ressource), BG_ERROR,
        (void *)background, RECTANGLESHAPE);
    return;
}
