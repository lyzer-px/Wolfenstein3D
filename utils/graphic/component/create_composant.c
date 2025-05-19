/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** create_composant.c
*/

#include <stdlib.h>
#include "../struct.h"

composant_t *create_composant(sfVector2f *pos, ressource_t *ressource)
{
    composant_t *new_composant = malloc(sizeof(composant_t));

    if (new_composant == NULL)
        return NULL;
    new_composant->next = NULL;
    new_composant->pos = pos;
    new_composant->ressource = ressource;
    return new_composant;
}
