/*
** EPITECH PROJECT, 2024
** name
** File description:
** init_pause_menu.c
*/

#include <stdlib.h>
#include "libgraphic.h"
#include "macro.h"

void handle_pause_menu_event(game_t *g)
{
    if (is_button_clicked(&tab_button[EXIT],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        sfRenderWindow_close(g->window->window);
    if (is_button_clicked(&tab_button[CONTINUE],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        g->actual_scene = GAME;
}

void init_pause_menu(scene_t *scene)
{
    create_layer(scene);
    for (int i = 0; tab_button[i].path_sprite != NULL; i++)
        add_button_to_menu(scene, tab_button[i]);
    scene->function_event = handle_pause_menu_event;
}
