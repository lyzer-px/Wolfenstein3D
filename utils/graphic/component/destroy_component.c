/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** destroy_component.c
*/

#include <stdlib.h>
#include "struct.h"

void destroy_component(component_t *component)
{
    if (component->pos != NULL)
        free(component->pos);
    free(component);
    return;
}
