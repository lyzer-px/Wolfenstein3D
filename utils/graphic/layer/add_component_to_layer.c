/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** add_component_to_layer.c
*/

#include "struct.h"
#include "libgraphic.h"

void add_a_component_to_layer(component_t *component, scene_t *scene, int id)
{
    layer_t *layer = scene->layer;

    while (layer != NULL) {
        if (layer->id == id) {
            rev_component(&(layer->component));
            component->next = layer->component;
            layer->component = component;
            rev_component(&(layer->component));
        }
        layer = layer->next;
    }
    return;
}
