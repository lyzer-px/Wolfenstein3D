/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** rectangleshape.c
*/

#include <SFML/Graphics.h>

void set_position_rectangleshape(void *rectangle, sfVector2f * position)
{
    sfRectangleShape_setPosition((sfRectangleShape *)rectangle, *position);
}

void draw_rectangleshape(sfRenderWindow *window, void *rectangle,
    sfRenderStates *states)
{
    sfRenderWindow_drawRectangleShape(window,
        (sfRectangleShape *)rectangle, states);
}

void destroy_rectangleshape(void *rectangle)
{
    sfRectangleShape_destroy((sfRectangleShape *)rectangle);
}
