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

static void set_background(game_t *game, scene_t *scene)
{
    ressource_t *ressource;
    sfVector2f *pos = malloc(sizeof(sfVector2f));
    sfVector2f scale;

    if (pos == NULL)
        return;
    pos->x = 0;
    pos->y = 0;
    scale.x = 0.65;
    scale.y = 0.65;
    if (create_ressource_for_sprite(game, wallpaper_pause, "bg_pause")
        == EPI_SUCCESS) {
        ressource = find_a_ressouce_from_id(game->ressource, "bg_pause");
        add_sprite_to_scene(pos, scene, 2, ressource);
        sfSprite_setScale((sfSprite *)ressource->element, scale);
    }
}

void init_pause_menu(game_t *game)
{
    scene_t *scene = game->tab_scene[PAUSE_MENU];

    create_layer(scene);
    for (int i = 0; button_pause_menu[i].path_sprite != NULL; i++)
        add_button_to_menu(scene, button_pause_menu[i]);
    scene->function_event = handle_pause_menu_event;
    create_layer(scene);
    set_background(game, scene);
}
