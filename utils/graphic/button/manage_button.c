/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** create_button.c
*/

#include <stdlib.h>
#include "../struct.h"
#include "../libgraphic.h"

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

void display_button(sfRenderWindow *win, void *element, sfRenderStates *states)
{
    button_t *button = (button_t *)element;

    sfRenderWindow_drawSprite(win, button->sprite, states);
}

void destroy_button(void *element)
{
    button_t *button = (button_t *)element;

    sfTexture_destroy(button->texture);
    sfSprite_destroy(button->sprite);
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
    sfFloatRect bounds = get_button_hitbox(*button);

    return sfFloatRect_contains(&bounds, mouse.x, mouse.y) &&
    (event->type == sfEvtMouseButtonPressed &&
    event->mouseButton.button == sfMouseLeft);
}
