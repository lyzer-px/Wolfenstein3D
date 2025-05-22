/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** Draw differents shapes
*/

#include <SFML/Graphics.h>

void draw_rectangle(sfRenderWindow *window, sfVector2f position,
    sfVector2f size)
{
    sfRectangleShape *square = sfRectangleShape_create();

    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setPosition(square, position);
    sfRectangleShape_setFillColor(square, sfBlack);
    sfRenderWindow_drawRectangleShape(window, square, NULL);
    sfRectangleShape_destroy(square);
}

void my_draw_circle(sfRenderWindow *wind, sfVector2f center, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition(circle, center);
    sfRenderWindow_drawCircleShape(wind, circle, NULL);
    sfCircleShape_destroy(circle);
}
