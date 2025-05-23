/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** Draw differents shapes
*/

#include <SFML/Graphics.h>
#include "libgraphic.h"

static void move_rect(sprite_rect_t *sprite_rect)
{
    if (sprite_rect->rect.top >= sprite_rect->max_value) {
        sprite_rect->rect.top = 0;
    } else {
        sprite_rect->rect.top += sprite_rect->offset;
    }
}

void update_sprite_rect(sfSprite *sprite, sprite_rect_t *sprite_rect,
    sfClock *clock, double nb_seconds)
{
    sfTime time;
    double seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > nb_seconds) {
        move_rect(sprite_rect);
        sfClock_restart(clock);
    }
    sfSprite_setTextureRect(sprite, sprite_rect->rect);
}
