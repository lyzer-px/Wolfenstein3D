/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** add_an_element_to_scene.c
*/

#include <stdlib.h>
#include "struct.h"
#include "libgraphic.h"

void add_element_to_scene(sfVector2f *pos, ressource_t *ressource,
    component_t **begin)
{
    component_t *new_component = malloc(sizeof(component_t));

    if (new_component == NULL)
        return;
    rev_component(begin);
    new_component->next = *begin;
    new_component->ressource = ressource;
    new_component->pos = pos;
    *begin = new_component;
    rev_component(begin);
    return;
}
