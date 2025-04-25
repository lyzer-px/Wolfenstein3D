/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** create_layer.c
*/

#include <stdlib.h>
#include "struct.h"

void create_layer(scene_t **scene)
{
    layer_t *new_layer = NULL;

    new_layer = malloc(sizeof(layer_t));
    if (new_layer == NULL)
        return;
    new_layer->composant = NULL;
    new_layer->next = (*scene)->layer;
    new_layer->view = true;
    new_layer->id = new_layer->next == NULL ? 1 : new_layer->next->id + 1;
    (*scene)->layer = new_layer;
}
