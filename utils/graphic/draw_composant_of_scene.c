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
        while (composant != NULL && layer->view == true) {
            composant->ressource->setposition(composant->ressource,
                *composant->pos);
            composant->ressource->display(window,
                composant->ressource->element, NULL);
            composant = composant->next;
        }
        layer = layer->next;
    }
    return;
}
