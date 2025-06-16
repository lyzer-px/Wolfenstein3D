/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** text.c
*/

#include <SFML/Graphics.h>

void set_position_text(void *text, sfVector2f *position)
{
    sfText_setPosition((sfText *)text, *position);
}

void draw_text(sfRenderWindow *window, void *text, sfRenderStates *states)
{
    sfRenderWindow_drawText(window, (sfText *)text, states);
}

void destroy_text(void *text)
{
    sfText_destroy((sfText *)text);
}
