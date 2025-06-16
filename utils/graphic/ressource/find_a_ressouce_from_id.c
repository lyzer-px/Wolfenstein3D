/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** find_a_ressouce_from_id.c
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "struct.h"

ressource_t *find_a_ressouce_from_id(ressource_t *begin, char *id)
{
    while (begin != NULL && strcmp(begin->id, id) != 0)
        begin = begin->next;
    if (begin == NULL)
        dprintf(STDERR_FILENO, "Error: ressource \"%s\" not found\n", id);
    return begin;
}
