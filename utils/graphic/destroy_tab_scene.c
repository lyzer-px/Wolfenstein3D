/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** destroy_tab_scene.c
*/

#include <stdlib.h>
#include "struct.h"

static void free_scene(scene_t **scene)
{
    layer_t *tmp_layer = NULL;
    composant_t *tmp_comp = NULL;

    while ((*scene)->layer != NULL) {
        tmp_layer = (*scene)->layer;
        while ((*scene)->layer->composant != NULL) {
            tmp_comp = (*scene)->layer->composant;
            (*scene)->layer->composant = (*scene)->layer->composant->next;
            tmp_comp->function_destroy(tmp_comp->element);
            free(tmp_comp);
        }
        (*scene)->layer = (*scene)->layer->next;
        free(tmp_layer);
    }
    free(*scene);
}

void free_tab_scene(game_t *game)
{
    for (int i = 0; i < game->nb_scene; i++)
        free_scene(&(game->tab_scene[i]));
    free(game->tab_scene);
}
