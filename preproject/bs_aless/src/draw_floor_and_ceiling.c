/*
** EPITECH PROJECT, 2024
** bs_aless
** File description:
** draw_floor_and_ceiling.c
*/

#include "project_funct.h"
#include "macro.h"

static sfRectangleShape *create_a_limit_z(sfVector2f position, sfColor color)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    if (shape == NULL)
        return NULL;
    sfRectangleShape_setPosition(shape, position);
    sfRectangleShape_setFillColor(shape, color);
    sfRectangleShape_setSize(shape, (sfVector2f){DIM_X, DIM_Y / 2});
    return shape;
}

void draw_floor_and_ceiling(sfRenderWindow *window)
{
    sfRectangleShape *floor = create_a_limit_z((sfVector2f){0, 0}, sfCyan);
    sfRectangleShape *ceiling = create_a_limit_z((sfVector2f){0, DIM_Y / 2},
        GREY);

    if (floor == NULL || ceiling == NULL) {
        if (floor != NULL) {
            sfRectangleShape_destroy(floor);
        }
        if (ceiling != NULL) {
            sfRectangleShape_destroy(ceiling);
        }
        return;
    }
    sfRenderWindow_drawRectangleShape(window, ceiling, NULL);
    sfRenderWindow_drawRectangleShape(window, floor, NULL);
    sfRectangleShape_destroy(floor);
    sfRectangleShape_destroy(ceiling);
    return;
}
