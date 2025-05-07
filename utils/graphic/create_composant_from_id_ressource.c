/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** create_composant_from_id_ressource.c
*/

#include "struct.h"
#include "libgraphic.h"

composant_t *create_composant_from_id_ressource(ressource_t *begin, char *id,
    sfVector2f *pos)
{
    ressource_t *ressource = find_a_ressouce_from_id(begin, id);
    composant_t *new_composant;

    if (ressource == NULL)
        return NULL;
    new_composant = create_composant(pos, ressource);
    return new_composant;
}
