/*
** EPITECH PROJECT, 2025
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

static void shotgun_update_frame(game_t *game, double scale)
{
    game->player->shotgun->rect.left += 70;
    game->player->shotgun->rect.left %= 500;
    sfSprite_setTextureRect(game->player->shotgun->sprite,
        game->player->shotgun->rect);
    sfRenderWindow_drawSprite(game->window->window,
        game->player->shotgun->sprite, NULL);
    sfSprite_setScale(game->player->impact->sprite,
        (sfVector2f){scale, scale});
    sfRenderWindow_drawSprite(game->window->window,
        game->player->impact->sprite, NULL);
}

void shotgun_shoot(game_t *game)
{
    double cam_x = 2 * ((double)SCREEN_WIDTH / 2) / (double)SCREEN_WIDTH - 1;
    hit_info_t hit = cast_single_ray(game, cam_x, SCREEN_WIDTH / 2, false);
    double distance = hit.p_dist;
    float scale = (1 / distance) * 2.5 > 1 ? 1 : (1 / distance) * 2.5;

    game->player->firing = true;
    game->player->shotgun->rect.left = 230;
    game->map->map[hit.y][hit.x] = game->map->map[hit.y][hit.x] == 2 ?
        0 : game->map->map[hit.y][hit.x];
    if (sfClock_getElapsedTime(game->player->clock).microseconds >= 200000) {
        shotgun_update_frame(game, scale);
        sfClock_restart(game->player->clock);
    }
    game->player->shotgun->rect.left = 0;
    sfSprite_setTextureRect(game->player->shotgun->sprite,
        game->player->shotgun->rect);
    game->player->firing = false;
}
