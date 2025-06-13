/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** create_ressource_link.c
*/

#include <stdio.h>
#include <unistd.h>
#include "libgraphic.h"

void create_ressource_link(ressource_t **begin, char *id,
    void *element, int type)
{
    ressource_t *new_ressource = create_ressource(id, element, type);

    if (new_ressource == NULL) {
        dprintf(STDERR_FILENO, "Error: Cannot load the file \"%s\"\n", id);
        return;
    }
    add_ressource(begin, new_ressource);
    return;
}
