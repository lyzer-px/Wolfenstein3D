/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** sprite.c
*/

#include <SFML/Graphics.h>

void set_position_sprite(void *sprite, sfVector2f *position)
{
    sfSprite_setPosition((sfSprite *)sprite, *position);
}

void draw_sprite(sfRenderWindow *window, void *sprite, sfRenderStates *states)
{
    sfRenderWindow_drawSprite(window, (sfSprite *)sprite, states);
}

void destroy_sprite(void *sprite)
{
    sfSprite_destroy((sfSprite *)sprite);
}
