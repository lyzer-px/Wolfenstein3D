/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** init_tab_scene.c
*/

#include <stdlib.h>
#include "struct.h"

static void void_function(window_t *window)
{
    (void)window;
    return;
}

scene_t **init_tab_scene(int nb_scene)
{
    scene_t **tab = malloc(sizeof(scene_t *) * (nb_scene + 1));

    if (tab == NULL)
        return NULL;
    for (int i = 0; i < nb_scene; i++) {
        tab[i] = malloc(sizeof(scene_t));
        if (tab[i] == NULL)
            return NULL;
        tab[i]->begin = NULL;
        tab[i]->function_event = void_function;
        tab[i]->id_scene = i + 1;
        tab[i]->pause = true;
    }
    tab[nb_scene - 1]->pause = false;
    return tab;
}
