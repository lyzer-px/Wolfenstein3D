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
    (*button)->texture = sfTexture_createFromFile(texture_path, NULL);
    (*button)->sprite = sfSprite_create();
    if ((*button)->texture == NULL || (*button)->sprite == NULL) {
        if ((*button)->sprite != NULL)
            sfSprite_destroy((*button)->sprite);
        if ((*button)->texture != NULL)
            sfTexture_destroy((*button)->texture);
        free((*button));
        (*button) = NULL;
        return;
    }
}

static button_t *create_button(char *texture_path, sfIntRect rect,
    sfVector2i pos)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    create_texture(&button, texture_path);
    if (button == NULL)
        return NULL;
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    button->area = rect;
    sfSprite_setTextureRect(button->sprite, rect);
    button->pos = pos;
    sfSprite_setPosition(button->sprite, (sfVector2f){pos.x, pos.y});
    return button;
}

button_t **create_button_tab(void)
{
    int len = SIZE_TAB_BUTTON;
    button_t **buttons = malloc(sizeof(button_t *) * (len + 1));

    if (buttons == NULL)
        return NULL;
    for (int i = 0; tab_button[i].path_sprite != NULL; i++)
        buttons[i] = create_button(tab_button[i].path_sprite,
            tab_button[i].rect, tab_button[i].pos);
    buttons[len] = NULL;
    return buttons;
}
