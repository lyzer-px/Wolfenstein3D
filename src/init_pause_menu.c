/*
** EPITECH PROJECT, 2024
** name
** File description:
** init_pause_menu.c
*/

#include "libgraphic.h"

static void add_button_to_menu(scene_t *scene, button_tab_t button_def)
{
    button_t *button = create_button(&button_def);

    if (button == NULL)
        return;
    add_element_to_scene(button, display_button, destroy_button,
        &scene->layer->composant);
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
