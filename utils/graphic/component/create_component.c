/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** create_component.c
*/

#include <stdlib.h>
#include "struct.h"

component_t *create_component(sfVector2f *pos, ressource_t *ressource)
{
    component_t *new_component = malloc(sizeof(component_t));

    if (new_component == NULL)
        return NULL;
    new_component->next = NULL;
    new_component->pos = pos;
    new_component->ressource = ressource;
    return new_component;
}
