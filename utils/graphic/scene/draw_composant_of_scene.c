/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** draw_composant_of_scene.c
*/

#include "../struct.h"

static void put_element_on_window(sfRenderWindow *window, composant_t *compo)
{
    if (compo->ressource->setposition != NULL && compo->pos != NULL &&
            compo->ressource->element != NULL)
        compo->ressource->setposition(compo->ressource->element, compo->pos);
    if (compo->ressource->display != NULL && compo->ressource->element != NULL)
        compo->ressource->display(window, compo->ressource->element, NULL);
}

void draw_composant_of_scene(sfRenderWindow *window, scene_t *scene)
{
    layer_t *layer = scene->layer;
    composant_t *composant = NULL;

    if (scene == NULL || window == NULL)
        return;
    while (layer != NULL) {
        composant = layer->composant;
        while (composant != NULL && layer->view == true) {
            put_element_on_window(window, composant);
            composant = composant->next;
        }
        layer = layer->next;
    }
    return;
}
