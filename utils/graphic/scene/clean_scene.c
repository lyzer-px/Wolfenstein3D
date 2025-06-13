/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** clean_scene.c
*/

#include "struct.h"
#include "libgraphic.h"

void clean_scene(scene_t *scene)
{
    layer_t *layer = scene->layer;

    while (layer != NULL) {
        clean_layer(layer);
        layer = layer->next;
    }
    return;
}
