/*
** EPITECH PROJECT, 2024
** name
** File description:
** init_pause_menu.c
*/

#include <stdlib.h>
#include "libgraphic.h"

void set_button_pos(void *sprite, sfVector2f *pos)
{
    sfSprite_setPosition((sfSprite *)sprite, *pos);
}

static void add_button_to_menu(scene_t *scene, button_tab_t button_def)
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

void handle_pause_menu_event(game_t *g)
{
    if (is_button_clicked(&tab_button[EXIT],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        sfRenderWindow_close(g->window->window);
}

void init_pause_menu(scene_t *scene)
{
    create_layer(scene);
    for (int i = 0; tab_button[i].path_sprite != NULL; i++)
        add_button_to_menu(scene, tab_button[i]);
    scene->function_event = handle_pause_menu_event;
}
