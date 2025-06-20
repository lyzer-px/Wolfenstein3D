/*
** EPITECH PROJECT, 2025
** bstrapwoof
** File description:
** bs.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "rendering.h"

bool is_wall(int x, int y, game_t *game)
{
    if ((x < 0 || y < 0) ||
        ((size_t)x > game->map->width || (size_t)y > game->map->height))
        return sfFalse;
    return game->map->map[y][x];
}

static void rotate_vect(sfVector2f *v, float old_x, float angle)
{
    v->x = v->x * cos(angle) - v->y * sin(angle);
    v->y = old_x * sin(angle) + v->y * cos(angle);
}

static void double_rotate(sfVector2f *dir, sfVector2f *plane, float angle)
{
    rotate_vect(dir, dir->x, angle);
    rotate_vect(plane, plane->x, angle);
}

static void player_rotate(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyD))
        double_rotate(&player->dir, &player->plane, -ROTATION_SPEED);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        double_rotate(&player->dir, &player->plane, ROTATION_SPEED);
}

static void player_reload(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyR))
        player->ammo = 1;
}

static void player_hurt(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyH))
        player->hp -= player->hp > 0;
}

void player_fwd(player_t *player, game_t *game)
{
    sfVector2f dir = player->dir;

    if (sfMouse_isButtonPressed(sfMouseLeft) && player->ammo > 0 &&
        sfClock_getElapsedTime(player->clock).microseconds > 20000) {
        shotgun_shoot(game);
        player->ammo -= !!sfClock_restart(player->clock).microseconds;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && DIR_COLLIDE(y, +, x, +)) {
        shotgun_move(game);
        player->pos.x += (dir.x * PLAYER_SPEED);
        player->pos.y += (dir.y * PLAYER_SPEED);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && DIR_COLLIDE(y, -, x, -)) {
        shotgun_move(game);
        player->pos.x -= dir.x * PLAYER_SPEED;
        player->pos.y -= dir.y * PLAYER_SPEED;
    }
    player_rotate(player);
    player_reload(player);
    player_hurt(player);
}
