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

bool is_wall(int x, int y)
{
    if ((x < 0 || y < 0) || (x > MAP_WIDTH || y > MAP_HEIGHT))
        return sfFalse;
    return map[y][x];
}

static void rotate_vector_left(sfVector2f *v, float angle)
{
    v->x = ((v->x * cosf(angle)) - (v->y * sinf(angle)));
    v->y = ((v->x * sinf(angle)) + (cosf(angle) * v->y));
}

void player_fwd(player_t *player, game_t *game)
{
    sfVector2f direction = {- sinf(RAD(player->angle)),
        cosf(RAD(player->angle))};

    if (player == NULL)
        return;
    // if (sfMouse_isButtonPressed(sfMouseLeft) && !player->running)
    //     shotgun_shoot(game);
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            shotgun_move(game);
        player->pos.x += direction.x * PLAYER_SPEED;
        player->pos.y += direction.y * PLAYER_SPEED;
    } else if (sfKeyboard_isKeyPressed(sfKeyS)) {
            shotgun_move(game);
        player->pos.x -= direction.x * PLAYER_SPEED;
        player->pos.y -= direction.y * PLAYER_SPEED;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        double oldDirx = player->direction.x;
        double oldPlanex = player->cam_plane.x;
        player->angle -= ROTATION_SPEED;
        player->direction.x = player->direction.x * cos(-ROTATION_SPEED) - player->direction.y * sin(-ROTATION_SPEED);
        player->direction.y = oldDirx * sin(-ROTATION_SPEED) + player->direction.y * cos(-ROTATION_SPEED);
        player->cam_plane.x = player->cam_plane.x * cos(-ROTATION_SPEED) - player->cam_plane.y * sin(-ROTATION_SPEED);
        player->cam_plane.y = oldPlanex * sin(-ROTATION_SPEED) + player->cam_plane.y * cos(-ROTATION_SPEED);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        double oldDirx = player->direction.x;
        double oldPlanex = player->cam_plane.x;
        player->angle += ROTATION_SPEED;
        player->direction.x = player->direction.x * cos(ROTATION_SPEED) - player->direction.y * sin(ROTATION_SPEED);
        player->direction.y = oldDirx * sin(ROTATION_SPEED) + player->direction.y * cos(ROTATION_SPEED);
        player->cam_plane.x = player->cam_plane.x * cos(ROTATION_SPEED) - player->cam_plane.y * sin(ROTATION_SPEED);
        player->cam_plane.y = oldPlanex * sin(ROTATION_SPEED) + player->cam_plane.y * cos(ROTATION_SPEED);
    }
    player->angle = player->angle > 360 ? 0 : player->angle;
    player->angle = player->angle < 0 ? 360 : player->angle;
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
