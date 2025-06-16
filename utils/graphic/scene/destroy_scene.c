/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** destroy_scene.c
*/

#include <stdlib.h>
#include "libgraphic.h"
#include "struct.h"

void destroy_scene(scene_t *scene)
{
    layer_t *layer;

    if (scene == NULL)
        return;
    while (scene->layer != NULL) {
        layer = scene->layer;
        scene->layer = scene->layer->next;
        destroy_layer(layer);
    }
    if (scene->id_music != NULL) {
        free(scene->id_music);
    }
    free(scene);
    return;
}
