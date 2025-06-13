/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** clean_layer.c
*/

#include <stdlib.h>
#include <stddef.h>
#include "libgraphic.h"
#include "struct.h"

void clean_layer(layer_t *layer)
{
    component_t *tmp;

    if (layer == NULL)
        return;
    while (layer->component != NULL) {
        tmp = layer->component;
        layer->component = layer->component->next;
        destroy_component(tmp);
    }
    return;
}
