/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** change_scene.c
*/

#include <SFML/Audio.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

static music_t *find_music(music_t *begin, char *id)
{
    while (begin != NULL) {
        if (strcmp(begin->id, id) == 0) {
            return begin;
        }
        begin = begin->next;
    }
    return NULL;
}

void change_scene(game_t *game, int new_scene)
{
    music_t *tmp = NULL;

    game->actual = new_scene;
    if (game->id_music == NULL || game->tab_scene[new_scene]->id_music == NULL
        || strcmp(game->id_music, game->tab_scene[new_scene]->id_music)) {
        tmp = find_music(game->music, game->tab_scene[new_scene]->id_music);
        if (tmp == NULL) {
            dprintf(STDERR_FILENO, "Error: didn't find %s\n",
            game->tab_scene[new_scene]->id_music);
            return;
        }
        if (game->music != NULL) {
            sfMusic_pause(game->music->music);
            free(game->id_music);
        }
        if (tmp != NULL && tmp->id != NULL) {
            sfMusic_play(tmp->music);
            game->id_music = strdup(tmp->id);
        }
    }
}
