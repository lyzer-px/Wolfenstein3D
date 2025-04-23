/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** add_an_element_to_scene.c
*/

#include <stdlib.h>
#include "struct.h"

void add_element_to_scene(void *element,
    void (*function_display)(sfRenderWindow *, void *, sfRenderStates *),
    void (*function_destroy)(void *), composant_t **begin_scene)
{
    composant_t *new_composant = malloc(sizeof(composant_t));

    if (new_composant == NULL)
        return;
    new_composant->id = ((*begin_scene) != NULL ? (*begin_scene)->id + 1 : 0);
    new_composant->element = element;
    new_composant->function_display = function_display;
    new_composant->function_destroy = function_destroy;
    new_composant->next = *begin_scene;
    *begin_scene = new_composant;
}
