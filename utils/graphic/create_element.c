/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** create_element.c
*/

#include <stdio.h>
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
    dprintf(2, "Error: Cannot create the element \"%s\"", filename);
    return NULL;
}
