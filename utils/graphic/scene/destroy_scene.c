/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** destroy_scene.c
*/

#include <stdlib.h>
#include "../libgraphic.h"
#include "../struct.h"

void destroy_scene(scene_t *scene)
{
    layer_t *layer;

    while (scene->layer != NULL) {
        layer = scene->layer;
        scene->layer = scene->layer->next;
        destroy_layer(layer);
    }
    free(scene);
    return;
}
