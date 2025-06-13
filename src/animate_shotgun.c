/*
** EPITECH PROJECT, 2024
** Woof3D
** File description:
** animate_shotgun.c
*/

#include <stdio.h>
#include "rendering.h"
#include "struct.h"

void shotgun_move(game_t *game)
{
    if (sfClock_getElapsedTime(game->player->clock).microseconds >= 200000) {
        sfClock_restart(game->player->clock);
        game->player->shotgun->rect.left += 90;
        game->player->shotgun->rect.left %= 180;
        sfSprite_setTextureRect(game->player->shotgun->sprite,
            game->player->shotgun->rect);
    }
}

// static void shotgun_update_frame(game_t *game)
// {
//     game->player->shotgun->rect.left += 70;
//     game->player->shotgun->rect.left %= 500;
//     sfSprite_setTextureRect(game->player->shotgun->sprite,
//         game->player->shotgun->rect);
//     sfRenderWindow_drawSprite(game->window->window,
//         game->player->shotgun->sprite, NULL);
// }

// void shotgun_shoot(game_t *game)
// {
//     float distance = cast_single_ray(game->player, game);
//     float scale = 1 / (distance / 1.5);

//     scale = scale > 1 ? 1 : scale;
//     game->player->firing = true;
//     game->player->shotgun->rect.left = 230;
//     if (sfClock_getElapsedTime(game->player->clock).microseconds >= 200000) {
//         sfClock_restart(game->player->clock);
//         shotgun_update_frame(game);
//         sfSprite_setScale(game->player->impact->sprite,
//             (sfVector2f){scale, scale});
//         sfRenderWindow_drawSprite(game->window->window,
//             game->player->impact->sprite, NULL);
//     }
//     game->player->shotgun->rect.left = 0;
//     game->player->firing = false;
// }
