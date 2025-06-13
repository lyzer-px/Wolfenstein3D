/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** draw_button.c
*/

#include "libgraphic.h"

void draw_buttons(sfRenderWindow *window, button_t **buttons)
{
    int i = 0;

    if (window == NULL || buttons == NULL)
        return;
    while (buttons[i] != NULL) {
        sfSprite_setTextureRect(buttons[i]->sprite[OFF], buttons[i]->area);
        sfRenderWindow_drawSprite(window, buttons[i]->sprite[OFF], NULL);
        i++;
    }
}
