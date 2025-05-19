/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** add_an_element_to_scene.c
*/

#include <stdlib.h>
#include "../struct.h"
#include "../libgraphic.h"

void add_element_to_scene(sfVector2f *pos, ressource_t *ressource,
    composant_t **begin)
{
    composant_t *new_composant = malloc(sizeof(composant_t));

    if (new_composant == NULL)
        return;
    rev_composant(begin);
    new_composant->next = *begin;
    new_composant->ressource = ressource;
    new_composant->pos = pos;
    *begin = new_composant;
    rev_composant(begin);
    return;
}
