/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** create_error_scene.c
*/

#include "struct.h"
#include "macro.h"
#include "libgraphic.h"
#include "type_id.h"
#include "project_funct.h"

static void create_ressource_error_scene(game_t *game)
{
    create_backgound_error_ressource(game);
    create_text_error_ressource(game);
}

static void create_layer_scene_error(scene_t *scene, ressource_t *begin)
{
    sfVector2f middle = {DIM_X / 2, DIM_Y / 2};

    create_layer(scene);
    scene->layer->composant = create_composant(&middle,
        find_a_ressouce_from_id(begin, TEXT_ERROR));
    create_layer(scene);
    scene->layer->composant = create_composant(&middle,
        find_a_ressouce_from_id(begin, BG_ERROR));
}

void create_error_scene(game_t *game)
{
    create_ressource_error_scene(game);
    game->tab_scene[ERROR_SCENE]->id_scene = ERROR_SCENE;
    game->tab_scene[ERROR_SCENE]->pause = true;
    create_layer_scene_error(game->tab_scene[ERROR_SCENE], game->ressource);
    return;
}
