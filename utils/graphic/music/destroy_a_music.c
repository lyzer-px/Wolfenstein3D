/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** destroy_a_music.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"

void destroy_a_music(music_t *music)
{
    free(music->id);
    sfMusic_destroy(music->music);
}
