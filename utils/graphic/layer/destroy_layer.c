/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** destoy_layer.c
*/

#include <stdlib.h>
#include "libgraphic.h"
#include "struct.h"

void destroy_layer(layer_t *layer)
{
    clean_layer(layer);
    free(layer);
    return;
}
