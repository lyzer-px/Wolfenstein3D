/*
** EPITECH PROJECT, 2024
** Wolf3D
** File description:
** init_start_menu.c
*/

#include <stdlib.h>
#include "libgraphic.h"
#include "macro.h"

static sprite_rect_t *get_rect(int total_width, int total_height,
    int sprite_height, sfSprite *sprite)
{
    sprite_rect_t *sprite_rect = malloc(sizeof(sprite_rect_t));
    sfIntRect rect;

    if (sprite_rect == NULL)
        return NULL;
    rect.top = 0;
    rect.left = 0;
    rect.width = total_width;
    rect.height = sprite_height;
    sfSprite_setTextureRect(sprite, rect);
    sprite_rect->offset = sprite_height;
    sprite_rect->max_value = total_height;
    sprite_rect->rect = rect;
    return sprite_rect;
}

void handle_start_menu_event(game_t *g)
{
    ressource_t *fire_line = find_a_ressouce_from_id(g->ressource,
        "fire_line");
    sprite_rect_t *rect = get_rect(FIRE_LINE_WIDTH,
        FIRE_LINE_HEIGHT, FIRE_LINE_SPRITE_HEIGHT,
        (sfSprite *)fire_line->element);

    if (is_button_clicked(&button_start_menu[EXIT_FROM_MENU],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        sfRenderWindow_close(g->window->window);
    if (is_button_clicked(&button_start_menu[START],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        change_scene(g, GAME);
    if (is_button_clicked(&button_start_menu[SETTING_BUTTON_FROM_MENU],
        sfMouse_getPositionRenderWindow(g->window->window), &g->window->event))
        change_scene(g, SETTING);
    if (fire_line != NULL) {
            update_sprite_rect((sfSprite *)fire_line->element, rect,
            g->window->clock, 1);
    }

}

void init_start_menu(game_t *game)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f));
    scene_t *scene = game->tab_scene[MENU];
    ressource_t *ressource;

    if (pos == NULL)
        return;
    create_layer(scene);
    for (int i = 0; button_start_menu[i].path_sprite != NULL; i++)
        add_button_to_menu(scene, button_start_menu[i]);
    scene->function_event = handle_start_menu_event;
    pos->x = 0;
    pos->y = DIM_Y;
        if (create_ressource_for_sprite(game, fire_line, "fire_line")
        == EPI_SUCCESS) {
        ressource = find_a_ressouce_from_id(game->ressource, "fire_line");
        add_sprite_to_scene(pos, scene, 1, ressource);
    }
    create_layer(scene);
    pos->x = 0;
    pos->y = 0;
        if (create_ressource_for_sprite(game, wallpaper_start, "bg_start")
        == EPI_SUCCESS) {
        ressource = find_a_ressouce_from_id(game->ressource, "bg_start");
        add_sprite_to_scene(pos, scene, 2, ressource);
    }
}
