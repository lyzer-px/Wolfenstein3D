/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** create_button.c
*/

#include <SFML/Graphics.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "libgraphic.h"

static void create_texture(button_t **button, char *texture_path)
{
    (*button)->texture[OFF] = sfTexture_createFromFile(texture_path, NULL);
    (*button)->sprite[OFF] = sfSprite_create();
    if ((*button)->texture[OFF] == NULL || (*button)->sprite[OFF] == NULL) {
        if ((*button)->sprite[OFF] != NULL)
            sfSprite_destroy((*button)->sprite[OFF]);
        if ((*button)->texture[OFF] != NULL)
            sfTexture_destroy((*button)->texture[OFF]);
        free((*button));
        (*button) = NULL;
        return;
    }
}

static button_t *create_a_button(char *texture_path, sfIntRect rect,
    sfVector2f *pos)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    create_texture(&button, texture_path);
    if (button == NULL)
        return NULL;
    sfSprite_setTexture(button->sprite[OFF], button->texture[OFF], sfTrue);
    button->area = rect;
    sfSprite_setTextureRect(button->sprite[OFF], rect);
    button->pos = pos;
    sfSprite_setPosition(button->sprite[OFF], (sfVector2f){pos->x, pos->y});
    return button;
}

button_t **create_button_tab(button_tab_t *tab_button)
{
    int len = SIZE_TAB_BUTTON;
    button_t **buttons = malloc(sizeof(button_t *) * (len + 1));

    if (buttons == NULL)
        return NULL;
    for (int i = 0; tab_button[i].path_sprite != NULL; i++)
        buttons[i] = create_a_button(tab_button[i].path_sprite,
            tab_button[i].rect, &tab_button[i].pos);
    buttons[len] = NULL;
    return buttons;
}
