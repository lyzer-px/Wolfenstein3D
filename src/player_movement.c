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

void player_fwd(player_t *player, game_t *game)
{
    sfVector2f direction = {- sinf(RAD(player->angle)),
        cosf(RAD(player->angle))};

    if (player == NULL)
        return;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        shotgun_fire(game);
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (!player->firing)
            shotgun_move(game);
        player->pos.x += direction.x * PLAYER_SPEED;
        player->pos.y += direction.y * PLAYER_SPEED;
    } else if (sfKeyboard_isKeyPressed(sfKeyS)) {
        if (!player->firing)
            shotgun_move(game);
        player->pos.x -= direction.x * PLAYER_SPEED;
        player->pos.y -= direction.y * PLAYER_SPEED;
    }
    player->angle -= sfKeyboard_isKeyPressed(sfKeyQ) * ROTATION_SPEED;
    player->angle += sfKeyboard_isKeyPressed(sfKeyD) * ROTATION_SPEED;
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
