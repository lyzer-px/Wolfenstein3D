/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** create_element.c
*/

#include <stdio.h>
#include <unistd.h>
#include "type_id.h"
#include "macro.h"

void *create_element(int type, char *filename)
{
    if (functions_by_type[type].creation != NULL)
        return functions_by_type[type].creation();
    if (type == TEXTURE)
        return sfTexture_createFromFile(filename, NULL);
    if (functions_by_type[type].creation_fromfile != NULL)
        return functions_by_type[type].creation_fromfile(filename);
    dprintf(STDERR_FILENO, "Error: Cannot create the element \"%s\"",
        filename);
    return NULL;
}
