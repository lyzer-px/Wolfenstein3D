/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** draw_component_of_scene.c
*/

#include "struct.h"

static void put_element_on_window(sfRenderWindow *window, component_t *compo)
{
    if (compo->ressource->setposition != NULL && compo->pos != NULL &&
            compo->ressource->element != NULL)
        compo->ressource->setposition(compo->ressource->element, compo->pos);
    if (compo->ressource->display != NULL && compo->ressource->element != NULL)
        compo->ressource->display(window, compo->ressource->element, NULL);
}

void draw_component_of_scene(sfRenderWindow *window, scene_t *scene)
{
    layer_t *layer = scene->layer;
    component_t *component = NULL;

    if (scene == NULL || window == NULL)
        return;
    while (layer != NULL) {
        component = layer->component;
        while (component != NULL && layer->view == true) {
            put_element_on_window(window, component);
            component = component->next;
        }
        layer = layer->next;
    }
    return;
}
