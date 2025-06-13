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

static void rotate_vect(sfVector2f *v, float old_x)
{
    v->x = v->x * cos(-ROTATION_SPEED) - v->y * sin(-ROTATION_SPEED);
    v->y = old_x * sin(-ROTATION_SPEED) + v->y * cos(-ROTATION_SPEED);
}

void player_fwd(player_t *player, game_t *game)
{
    sfVector2f dir = player->dir;

    if (player == NULL)
        return;
    if (sfMouse_isButtonPressed(sfMouseLeft) && !player->running)
        shotgun_shoot(game);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && DIR_COLLIDE(y, +, x, +)) {
            shotgun_move(game);
        player->pos.x += (dir.x * PLAYER_SPEED);
        player->pos.y += (dir.y * PLAYER_SPEED);
    } else if (sfKeyboard_isKeyPressed(sfKeyS && DIR_COLLIDE(y, -, x, +))) {
            shotgun_move(game);
        player->pos.x -= dir.x * PLAYER_SPEED;
        player->pos.y -= dir.y * PLAYER_SPEED;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        double oldDirx = player->dir.x;
        double oldPlanex = player->plane.x;
        rotate_vect(&player->dir, player->dir.x);
        player->plane.x = player->plane.x * cos(-ROTATION_SPEED) - player->plane.y * sin(-ROTATION_SPEED);
        player->plane.y = oldPlanex * sin(-ROTATION_SPEED) + player->plane.y * cos(-ROTATION_SPEED);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        double oldDirx = player->dir.x;
        double oldPlanex = player->plane.x;
        player->dir.x = player->dir.x * cos(ROTATION_SPEED) - player->dir.y * sin(ROTATION_SPEED);
        player->dir.y = oldDirx * sin(ROTATION_SPEED) + player->dir.y * cos(ROTATION_SPEED);
        player->plane.x = player->plane.x * cos(ROTATION_SPEED) - player->plane.y * sin(ROTATION_SPEED);
        player->plane.y = oldPlanex * sin(ROTATION_SPEED) + player->plane.y * cos(ROTATION_SPEED);
    }
}
