/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** draw_composant_of_scene.c
*/

#include "struct.h"

void draw_composant_of_scene(sfRenderWindow *window, scene_t *scene)
{
    layer_t *layer = scene->layer;
    composant_t *composant = NULL;

    if (scene == NULL)
        return;
    while (layer != NULL) {
        composant = layer->composant;
        while (composant != NULL) {
            composant->function_display(window, composant->element, NULL);
            composant = composant->next;
        }
        layer = layer->next;
    }
}
