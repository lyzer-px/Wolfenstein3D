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

static void shotgun_fire_frame(game_t *game)
{
    game->player->shotgun->rect.left += 70;
    game->player->shotgun->rect.left %= 500;
    sfSprite_setTextureRect(game->player->shotgun->sprite,
        game->player->shotgun->rect);
    sfRenderWindow_drawSprite(game->window->window,  game->player->shotgun->sprite, NULL);
}


void shotgun_fire(game_t *game)
{
    game->player->firing = true;
    game->player->shotgun->rect.left = 230;
    if (sfClock_getElapsedTime(game->player->clock).microseconds >= 500000) {
        sfClock_restart(game->player->clock);
        for (size_t i = 0; i != 3; i++)
            shotgun_fire_frame(game);
    }
    game->player->shotgun->rect.left = 0;
    game->player->firing = false;
}
