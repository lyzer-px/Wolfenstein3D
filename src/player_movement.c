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

bool is_wall(int x, int y)
{
    if ((x < 0 || y < 0) || (x > MAP_WIDTH || y > MAP_HEIGHT))
        return sfFalse;
    return map[y][x];
}

static void rotate_vect(sfVector2f *v, float old_x, float angle)
{
    v->x = v->x * cos(angle) - v->y * sin(angle);
    v->y = old_x * sin(angle) + v->y * cos(angle);
}

void player_fwd(player_t *player, game_t *game)
{
    sfVector2f dir = player->dir;

    if (sfMouse_isButtonPressed(sfMouseLeft) && !player->running)
        shotgun_shoot(game);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && DIR_COLLIDE(y, +, x, +)) {
        shotgun_move(game);
        player->pos.x += (dir.x * PLAYER_SPEED);
        player->pos.y += (dir.y * PLAYER_SPEED);
    } else if (sfKeyboard_isKeyPressed(sfKeyS) && DIR_COLLIDE(y, -, x, +)) {
        shotgun_move(game);
        player->pos.x -= dir.x * PLAYER_SPEED;
        player->pos.y -= dir.y * PLAYER_SPEED;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        rotate_vect(&player->dir, player->dir.x, -ROTATION_SPEED);
        rotate_vect(&player->plane, player->plane.x, -ROTATION_SPEED);
    } else if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        rotate_vect(&player->dir, player->dir.x, ROTATION_SPEED);
        rotate_vect(&player->plane, player->plane.x, ROTATION_SPEED);
    }
}
