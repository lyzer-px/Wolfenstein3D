/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** create_ressource.c
*/

#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "type_id.h"

ressource_t *create_ressource(char *id, void *element, int type)
{
    ressource_t *ressource = malloc(sizeof(ressource_t));

    if (ressource == NULL)
        return NULL;
    ressource->id = strdup(id);
    ressource->element = element;
    ressource->setposition = (functions_by_type[type]).set_position;
    ressource->display = (functions_by_type[type]).display;
    ressource->destroy = (functions_by_type[type]).destroy;
    ressource->next = NULL;
    return ressource;
}
