/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** draw_composant_of_scene.c
*/

#include "struct.h"

void draw_composant_of_scene(sfRenderWindow *window, scene_t *scene)
{
    composant_t *begin = scene->begin;

    if (scene == NULL)
        return;
    while (begin != NULL) {
        begin->function_display(window, begin->element, NULL);
        begin = begin->next;
    }
}
