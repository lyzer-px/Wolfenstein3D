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
    composant_t *tmp = NULL;

    while ((*scene)->begin != NULL) {
        tmp = (*scene)->begin;
        (*scene)->begin = (*scene)->begin->next;
        tmp->function_destroy(tmp->element);
        free(tmp);
    }
    free(*scene);
}

void free_tab_scene(game_t *game)
{
    for (int i = 0; i < game->nb_scene; i++)
        free_scene(&(game->tab_scene[i]));
    free(game->tab_scene);
}
