/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** destroy_all_music.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include "libgraphic.h"

void destroy_all_music(game_t *game)
{
    music_t *tmp = game->music;

    while (game->music != NULL) {
        game->music = game->music->next;
        destroy_a_music(tmp);
        tmp = game->music;
    }
}
