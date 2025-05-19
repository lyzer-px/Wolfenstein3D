/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** add_composant_to_layer.c
*/

#include "../struct.h"
#include "../libgraphic.h"

void add_a_composant_to_layer(composant_t *composant, scene_t *scene, int id)
{
    layer_t *layer = scene->layer;

    while (layer != NULL) {
        if (layer->id == id) {
            rev_composant(&(layer->composant));
            composant->next = layer->composant;
            layer->composant = composant;
            rev_composant(&(layer->composant));
        }
        layer = layer->next;
    }
    return;
}
