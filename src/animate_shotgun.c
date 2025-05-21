/*
** EPITECH PROJECT, 2024
** Woof3D
** File description:
** animate_shotgun.c
*/

#include <stdio.h>
#include "struct.h"

void shotgun_move(game_t *game)
{
    if (sfClock_getElapsedTime(game->player->clock).microseconds >= 200000) {
        sfClock_restart(game->player->clock);
        game->player->shotgun->rect.left += 90;
        game->player->shotgun->rect.left %= 180;
        sfSprite_setTextureRect(game->player->shotgun->sprite,
            game->player->shotgun->rect);
        printf("FORWARD\n");
    }
}

void shotgun_fire(game_t *game)
{
    game->player->shotgun->rect.left = 220;

    for (size_t i = 0; i != 2; i++) {
        if (sfClock_getElapsedTime(game->player->clock).microseconds >= 200000) {
            sfClock_restart(game->player->clock);
            game->player->shotgun->rect.left += 90;
            game->player->shotgun->rect.left %= 450;
            sfSprite_setTextureRect(game->player->shotgun->sprite,
                game->player->shotgun->rect);
            printf("FIRE!\n");
        }
    }
}
