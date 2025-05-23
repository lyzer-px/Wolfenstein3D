/*
** EPITECH PROJECT, 2024
** Wolf3Ds
** File description:
** init_pause_menu.c
*/

#include <stdlib.h>
#include "libgraphic.h"
#include "macro.h"

void handle_pause_menu_event(game_t *g)
{
    if (is_button_clicked(&button_pause_menu[EXIT],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        sfRenderWindow_close(g->window->window);
    if (is_button_clicked(&button_pause_menu[CONTINUE],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        change_scene(g, GAME);
    if (is_button_clicked(&button_pause_menu[SETTING_BUTTON],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        change_scene(g, SETTING);
    if (is_button_clicked(&button_pause_menu[SETTING_BUTTON],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        change_scene(g, SAVE_SCENE);
}

void init_pause_menu(scene_t *scene)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f));

    if (pos == NULL)
        return;
    create_layer(scene);
    for (int i = 0; button_pause_menu[i].path_sprite != NULL; i++)
        add_button_to_menu(scene, button_pause_menu[i]);
    scene->function_event = handle_pause_menu_event;
    create_layer(scene);
    pos->x = 0;
    pos->y = 0;
    add_sprite_to_scene(pos, scene, wallpaper_pause, "bg_pause");
}
