/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** destroy_component.c
*/

#include <stdlib.h>
#include "struct.h"
#include "libgraphic.h"

void destroy_component(component_t *component)
{
    if (component == NULL)
        return;
    if (component->pos)
        free(component->pos);
    component->ressource = NULL;
    free(component);
}
