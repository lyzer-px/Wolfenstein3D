/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** destroy_ressource.c
*/

#include <stdlib.h>
#include "struct.h"

void destroy_ressource(ressource_t **ressource)
{
    (*ressource)->destroy((*ressource)->element);
    free((*ressource)->id);
    free(*ressource);
    *ressource = NULL;
    return;
}
