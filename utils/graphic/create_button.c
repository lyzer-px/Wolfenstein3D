/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** create_button.c
*/

#include <stdlib.h>
#include "struct.h"
#include "libgraphic.h"

button_t *create_button(const button_tab_t *def)
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    button->texture = sfTexture_createFromFile(def->path_sprite, NULL);
    if (!button->texture) {
        free(button);
        return NULL;
    }
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, def->rect);
    sfSprite_setPosition(button->sprite, (sfVector2f){def->pos.x, def->pos.y});
    button->area = def->rect;
    button->pos = def->pos;
    return button;
}
