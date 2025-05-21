/*
** EPITECH PROJECT, 2024
** Wolf3Ds
** File description:
** init_pause_menu.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "libgraphic.h"
#include "libmy.h"
#include "project_funct.h"
#include "macro.h"

static void print_save_result(game_t *g)
{
    mini_dprintf(STDOUT, "Saving game...\n");
    if (save_game(NULL, g) == EPI_SUCCESS) {
        mini_dprintf(STDOUT, "Save done\n");
    } else {
        mini_dprintf(STDERR, "Save failed\n");
    }
}

void handle_pause_menu_event(game_t *g)
{
    if (is_button_clicked(&button_pause_menu[EXIT],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        sfRenderWindow_close(g->window->window);
    if (is_button_clicked(&button_pause_menu[CONTINUE],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        g->actual_scene = GAME;
    if (is_button_clicked(&button_pause_menu[SETTING_BUTTON],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        g->actual_scene = SETTING;
    if (is_button_clicked(&button_pause_menu[SAVE],
        sfMouse_getPositionRenderWindow(g->window->window),
        &g->window->event)) {
        g->actual_scene = SAVE_SCENE;
        print_save_result(g);
        g->actual_scene = MENU;
    }
}

void init_pause_menu(scene_t *scene)
{
    create_layer(scene);
    for (int i = 0; button_pause_menu[i].path_sprite != NULL; i++)
        add_button_to_menu(scene, button_pause_menu[i]);
    scene->function_event = handle_pause_menu_event;
}
