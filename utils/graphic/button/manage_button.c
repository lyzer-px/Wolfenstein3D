/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** create_button.c
*/

#include <stdlib.h>
#include "struct.h"
#include "libgraphic.h"
#include "macro.h"

static size_t set_button_texture(const button_tab_t *def,
    button_t *button)
{
    button->texture[OFF] = sfTexture_createFromFile(def->path_sprite, NULL);
    if (!button->texture[OFF]) {
        free(button);
        return EPI_FAIL;
    }
    return EPI_SUCCESS;
}

button_t *create_button(const button_tab_t *def)
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f *pos = malloc(sizeof(sfVector2f));

    if (button == NULL || pos == NULL)
        return NULL;
    pos->x = def->pos.x;
    pos->y = def->pos.y;
    if (set_button_texture(def, button) == EPI_FAIL)
        return NULL;
    button->sprite[OFF] = sfSprite_create();
    sfSprite_setTexture(button->sprite[OFF], button->texture[OFF], sfTrue);
    sfSprite_setTextureRect(button->sprite[OFF], def->rect);
    sfSprite_setPosition(button->sprite[OFF],
        (sfVector2f){def->pos.x, def->pos.y});
    button->area = def->rect;
    button->pos = pos;
    return button;
}

void display_button(sfRenderWindow *win, void *element, sfRenderStates *states)
{
    button_t *button = (button_t *)element;

    sfRenderWindow_drawSprite(win, button->sprite[OFF], states);
}

void destroy_button(void *element)
{
    button_t *button = (button_t *)element;

    for (size_t i = 0; i < NB_STATE; i++) {
        sfTexture_destroy(button->texture[i]);
        sfSprite_destroy(button->sprite[i]);
    }
    free(button->texture);
    free(button);
}

sfFloatRect get_button_hitbox(button_tab_t button)
{
    sfFloatRect hitbox;

    hitbox.left = (float)button.pos.x;
    hitbox.top = (float)button.pos.y;
    hitbox.width = (float)button.rect.width;
    hitbox.height = (float)button.rect.height;
    return hitbox;
}

bool is_button_clicked(const button_tab_t *button, sfVector2i mouse,
    sfEvent *event)
{
    sfFloatRect mini_map = get_button_hitbox(*button);

    return sfFloatRect_contains(&mini_map, mouse.x, mouse.y) &&
    (event->type == sfEvtMouseButtonPressed &&
    event->mouseButton.button == sfMouseLeft);
}
