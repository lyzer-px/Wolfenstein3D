/*
** EPITECH PROJECT, 2024
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
    composant_t *tmp;

    if (layer->composant == NULL)
        return;
    while (layer->composant != NULL) {
        tmp = layer->composant;
        layer->composant = layer->composant->next;
        destroy_composant(&(tmp));
    }
    return;
}
