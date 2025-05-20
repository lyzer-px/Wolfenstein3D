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
/*
static sfRectangleShape *create_rect(sfVector2f pos,
    sfVector2f size, sfColor *color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, *color);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOutlineColor(rect, (sfColor){200, 150, 0, 255});
    sfRectangleShape_setOutlineThickness(rect, 10);
    return rect;
}

static void init_menu(scene_t *scene, sfColor *color)
{
    composant_t *tmp;
    sfRectangleShape *rect_tmp = NULL;

    for (int y = 1; y < 4; y++) {
        create_layer(scene);
        for (int i = 0; i < 3; i++) {
            rect_tmp = create_rect((sfVector2f){50 * (i + y), 50 * (i + y)},
                (sfVector2f){40 * (i + y), 40 * (i + y)}, color);
            add_element_to_scene(rect_tmp, sfRenderWindow_drawRectangleShape,
                sfRectangleShape_destroy, &scene->layer->composant);
        }
    }
}*/

static void create_scenes(game_t *game)
{
    create_error_scene(game);
    init_pause_menu(game->tab_scene[PAUSE_MENU]);
    init_start_menu(game->tab_scene[MENU]);
}

int init_scene(game_t *game)
{
    int status = 0;

    create_scenes(game);
    if (status == EPI_SUCCESS)
        status = loop(game);
    return status;
}
