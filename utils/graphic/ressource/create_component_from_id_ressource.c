/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** create_component_from_id_ressource.c
*/

#include "struct.h"
#include "libgraphic.h"

component_t *create_component_from_id_ressource(ressource_t *begin, char *id,
    sfVector2f *pos)
{
    ressource_t *ressource = find_a_ressouce_from_id(begin, id);
    component_t *new_component;

    if (ressource == NULL)
        return NULL;
    new_component = create_component(pos, ressource);
    return new_component;
}
