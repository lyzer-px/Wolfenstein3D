/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** init_tab_scene.c
*/

#include <stdlib.h>
#include "struct.h"

static void void_function(game_t *game)
{
    (void)game;
    return;
}

static bool destroy_tab(scene_t **tab, size_t i)
{
    if (tab[i] == NULL) {
        for (size_t j = 0; j < i; j++)
            free(tab[j]);
        free(tab);
        return true;
    }
    return false;
}

scene_t **init_tab_scene(size_t nb_scene)
{
    scene_t **tab = malloc(sizeof(scene_t *) * (nb_scene + 1));

    if (tab == NULL)
        return NULL;
    for (size_t i = 0; i < nb_scene; i++) {
        tab[i] = malloc(sizeof(scene_t));
        if (destroy_tab(tab, i) == true)
            return NULL;
        tab[i]->layer = NULL;
        tab[i]->function_event = void_function;
        tab[i]->set_positions = void_function;
        tab[i]->id_scene = i + 1;
        tab[i]->pause = true;
        tab[i]->id_music = NULL;
        tab[i]->hide_cursor = false;
    }
    tab[nb_scene - 1]->pause = false;
    return tab;
}
