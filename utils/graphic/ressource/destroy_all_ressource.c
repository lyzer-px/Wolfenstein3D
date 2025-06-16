/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** destroy_all_ressource.c
*/

#include "struct.h"
#include "libgraphic.h"

void destroy_all_ressource(ressource_t **ressource_begin)
{
    ressource_t *tmp;

    if (*ressource_begin == NULL)
        return;
    while (*ressource_begin != NULL) {
        tmp = *ressource_begin;
        (*ressource_begin) = (*ressource_begin)->next;
        destroy_ressource(&tmp);
    }
    return;
}
