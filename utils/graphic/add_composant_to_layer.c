/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** add_composant_to_layer.c
*/

#include "struct.h"
#include "libgraphic.h"

void add_a_composant_to_layer(composant_t *composant, scene_t *scene, int id)
{
    layer_t *layer = scene->layer;

    while (layer->id != id)
        layer = layer->next;
    if (layer == NULL)
        return;
    rev_composant(&(layer->composant));
    composant->next = layer->composant;
    composant->id = composant->next == NULL ? 1 : composant->next->id + 1;
    layer->composant = composant;
    rev_composant(&(layer->composant));
    return;
}
