/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** add_ressource.c
*/

#include "struct.h"

void add_ressource(ressource_t **begin, ressource_t *new_ressource)
{
    new_ressource->next = *begin;
    *begin = new_ressource;
    return;
}
