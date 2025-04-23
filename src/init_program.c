/*
** EPITECH PROJECT, 2024
** wolf3d
** File description:
** init_program.c
*/

#include <stdlib.h>
#include "macro.h"
#include "struct.h"
#include "project_funct.h"
#include "libgraphic.h"

static sfRectangleShape *create_rect(sfVector2f pos,
    sfVector2f size, sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOutlineColor(rect, (sfColor){200, 150, 0, 255});
    sfRectangleShape_setOutlineThickness(rect, 10);
    return rect;
}

static void init_menu(scene_t *scene, sfColor color)
{
    layer_t *layer = scene->layer;
    layer_t *tmp = NULL;
    sfRectangleShape *rect_tmp = NULL;
    int y = 0;

    for (int y = 0; y < 3; y++) {
        tmp = malloc(sizeof(layer_t));
        if (tmp == NULL)
            return;
        tmp->composant = NULL;
        for (int i = 0; i < 3; i++) {
            rect_tmp = create_rect((sfVector2f){50 * (i + y), 50 * (i + y)},
                (sfVector2f){40 * (i + y), 40 * (i + y)}, color);
            add_element_to_scene(rect_tmp, sfRenderWindow_drawRectangleShape,
                sfRectangleShape_destroy, &tmp->composant);
        }
        tmp->next = layer;
        layer = tmp;
    }
    scene->layer = layer;
}

int init_scene(game_t *game)
{
    int status = 0;

    init_menu(game->tab_scene[0], sfCyan);
    init_menu(game->tab_scene[1], sfGreen);
    if (status == EPI_SUCESS)
        status = loop(game);
    return status;
}
