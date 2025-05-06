/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** destroy_composant.c
*/

#include <stdlib.h>
#include "struct.h"

void destroy_composant(composant_t *composant)
{
    composant->function_destroy(composant->element);
    free(composant);
    return;
}
