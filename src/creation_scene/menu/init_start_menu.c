/*
** EPITECH PROJECT, 2024
** Wolf3D
** File description:
** init_start_menu.c
*/

#include <stdlib.h>
#include "libgraphic.h"
#include "macro.h"

void handle_start_menu_event(game_t *g)
{
    if (is_button_clicked(&button_start_menu[EXIT_FROM_MENU],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        sfRenderWindow_close(g->window->window);
    if (is_button_clicked(&button_start_menu[START],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        change_scene(g, GAME);
    if (is_button_clicked(&button_start_menu[SETTING_BUTTON_FROM_MENU],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        change_scene(g, SETTING);
    //update_sprite_rect();
}

void init_start_menu(scene_t *scene)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f));

    if (pos == NULL)
        return;
    create_layer(scene);
    for (int i = 0; button_start_menu[i].path_sprite != NULL; i++)
        add_button_to_menu(scene, button_start_menu[i]);
    scene->function_event = handle_start_menu_event;
    pos->x = 0;
    pos->y = DIM_Y;
    add_sprite_to_scene(pos, scene, fire_line, "fire_line");
    create_layer(scene);
    pos->x = 0;
    pos->y = 0;
    add_sprite_to_scene(pos, scene, wallpaper_start, "bg_start");
}
