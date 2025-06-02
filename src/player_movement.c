/*
** EPITECH PROJECT, 2024
** bstrapwoof
** File description:
** bs.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "rendering.h"

sfBool is_wall(int x, int y)
{
    if ((x < 0 || y < 0) || (x > MAP_WIDTH || y > MAP_HEIGHT))
        return sfFalse;
    return map[y][x];
}

static void sync_angle(player_t *player)
{
    sfVector2f old_dir = player->dir;
    sfVector2f old_plane = player->camera_plane;

    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        player->dir.x = player->dir.x * cosf(-ROTATION_SPEED) -
            player->dir.y * sinf(-ROTATION_SPEED);
        player->dir.y = old_dir.x * sinf(-ROTATION_SPEED) +
            player->dir.y * cosf(-ROTATION_SPEED);
        player->camera_plane.x = player->camera_plane.x * cosf(-ROTATION_SPEED) -
            player->camera_plane.y * sinf(-ROTATION_SPEED);
        player->camera_plane.y = old_plane.x * sinf(-ROTATION_SPEED) +
            player->camera_plane.y * cosf(-ROTATION_SPEED);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        player->dir.x = player->dir.x * cosf(ROTATION_SPEED) -
            player->dir.y * sinf(ROTATION_SPEED);
        player->dir.y = old_dir.x * sinf(-ROTATION_SPEED) +
            player->dir.y * cosf(ROTATION_SPEED);
        player->camera_plane.x = player->camera_plane.x * cosf(ROTATION_SPEED) -
            player->camera_plane.y * sinf(ROTATION_SPEED);
        player->camera_plane.y = old_plane.x * sinf(ROTATION_SPEED) +
            player->camera_plane.y * cosf(ROTATION_SPEED);
    }
    player->angle = player->angle > 360 ? 0 : player->angle;
    player->angle = player->angle < 0 ? 360 : player->angle;
}

void player_fwd(player_t *player, game_t *game)
{
    player->direction = (sfVector2f){sinf(RAD(player->angle)),
        cosf(RAD(player->angle))};

    if (player == NULL)
        return;
    if (sfMouse_isButtonPressed(sfMouseLeft) && !player->running)
        shotgun_shoot(game);
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            shotgun_move(game);
        player->pos.x += player->direction.x * PLAYER_SPEED;
        player->pos.y += player->direction.y * PLAYER_SPEED;
    } else if (sfKeyboard_isKeyPressed(sfKeyS)) {
            shotgun_move(game);
        player->pos.x -= player->direction.x * PLAYER_SPEED;
        player->pos.y -= player->direction.y * PLAYER_SPEED;
    }
    sync_angle(player);
}

void player_repel(player_t *player, game_t *game)
{
    sfVector2f direction = {- sinf(RAD(player->angle)),
        cosf(RAD(player->angle))};

    if (player == NULL)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        shotgun_move(game);
        player->pos.x -= direction.x * PLAYER_SPEED;
        player->pos.y -= direction.y * PLAYER_SPEED;
    } else if (sfKeyboard_isKeyPressed(sfKeyS)) {
        shotgun_move(game);
        player->pos.x += direction.x * PLAYER_SPEED;
        player->pos.y += direction.y * PLAYER_SPEED;
    }
}
