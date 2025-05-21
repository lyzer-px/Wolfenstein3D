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
    if (component->pos != NULL)
        free(component->pos);
    if (component->ressource != NULL)
        destroy_ressource(&(component->ressource));
    free(component);
    return;
}
