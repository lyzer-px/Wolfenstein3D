/*
** EPITECH PROJECT, 2024
** Wolf3D
** File description:
** init_start_menu.c
*/

#include <stdlib.h>
#include "project_funct.h"
#include "libgraphic.h"
#include "macro.h"

void handle_start_menu_event(game_t *g)
{
    if (is_button_clicked(&button_start_menu[EXIT_FROM_MENU],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        sfRenderWindow_close(g->window->window);
    if (is_button_clicked(&button_start_menu[START],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        g->actual_scene = GAME;
    if (is_button_clicked(&button_start_menu[SETTING_BUTTON_FROM_MENU],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        g->actual_scene = SETTING;
    if (is_button_clicked(&button_start_menu[LOAD_SAVE],
        sfMouse_getPositionRenderWindow(g->window->window),
        &g->window->event)) {
        if (load_save("1.save", g) == EPI_SUCCESS) {
            g->actual_scene = GAME;
        } else {
            //g->actual_scene = ERROR_SCENE;
            g->actual_scene = GAME;
        }
        }
}

void init_start_menu(scene_t *scene)
{
    create_layer(scene);
    for (int i = 0; button_start_menu[i].path_sprite != NULL; i++)
        add_button_to_menu(scene, button_start_menu[i]);
    scene->function_event = handle_start_menu_event;
}
