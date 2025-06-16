/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** circle.c
*/

#include <SFML/Graphics.h>

void set_position_circle(void *circle, sfVector2f *position)
{
    sfCircleShape_setPosition((sfCircleShape *)circle, *position);
}

void draw_circle(sfRenderWindow *window, void *circle, sfRenderStates *states)
{
    sfRenderWindow_drawCircleShape(window, (sfCircleShape *)circle, states);
}

void destroy_circle(void *circle)
{
    sfCircleShape_destroy((sfCircleShape *)circle);
}
