/*
** EPITECH PROJECT, 2024
** Wolf3D
** File description:
** add_button_to_menu
*/

#include <stdlib.h>
#include "../libgraphic.h"
#include "../macro.h"

void set_button_pos(void *sprite, sfVector2f *pos)
{
    sfSprite_setPosition((sfSprite *)sprite, *pos);
}

void add_button_to_menu(scene_t *scene, button_tab_t button_def)
{
    ressource_t *ressource = malloc(sizeof(ressource_t));
    button_t *button = create_button(&button_def);

    if (button == NULL)
        return;
    if (ressource == NULL) {
        free(button);
        return;
    }
    ressource->destroy = destroy_button;
    ressource->display = display_button;
    ressource->element = button;
    ressource->setposition = set_button_pos;
    add_element_to_scene(&button->pos, ressource, &scene->layer->composant);
}
