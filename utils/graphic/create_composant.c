/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** create_composant.c
*/

#include <stdlib.h>
#include "struct.h"

composant_t *create_composant(void *element,
    void (*function_display)(sfRenderWindow *, void *, sfRenderStates *),
    void (*function_destroy)(void *))
{
    composant_t *new_composant = malloc(sizeof(composant_t));

    if (new_composant == NULL)
        return NULL;
    new_composant->next = NULL;
    new_composant->id = 0;
    new_composant->element = element;
    new_composant->function_display = function_display;
    new_composant->function_destroy = function_destroy;
    return new_composant;
}
