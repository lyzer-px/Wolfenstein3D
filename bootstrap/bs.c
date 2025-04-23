/*
** EPITECH PROJECT, 2024
** bstrapwoof
** File description:
** bs.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "bs.h"

sfBool is_wall(int x, int y)
{
    return map[y][x];
}

void init_ray(player_t *player)
{
    player->ray = sfRectangleShape_create();
    if (player->ray == nullptr)
        return;
    sfRectangleShape_setSize(player->ray,
        sfRectangleShape_getSize(player->hitbox));
    sfRectangleShape_setFillColor(player->ray, sfBlue);
    sfRectangleShape_setOrigin(player->ray, (sfVector2f){10, 10});
}

void init_hitbox(player_t *player)
{
    sfRectangleShape_setFillColor(player->hitbox, sfRed);
    sfRectangleShape_setOrigin(player->hitbox, (sfVector2f){10, 10});
    sfRectangleShape_setSize(player->hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setPosition(player->hitbox, (sfVector2f){400, 300});
    sfRectangleShape_setRotation(player->hitbox, player->angle);
}

void player_fwd(player_t *player)
{
    sfVector2f direction = {- sinf(RAD(player->angle)),
        cosf(RAD(player->angle))};

    if (player == nullptr)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        player->pos.x += direction.x * PLAYER_SPEED;
        player->pos.y += direction.y * PLAYER_SPEED;
    } else if (sfKeyboard_isKeyPressed(sfKeyS)) {
        player->pos.x -= direction.x * PLAYER_SPEED;
        player->pos.y -= direction.y * PLAYER_SPEED;
    }
    player->angle -= sfKeyboard_isKeyPressed(sfKeyQ) * PLAYER_SPEED;
    player->angle += sfKeyboard_isKeyPressed(sfKeyD) * PLAYER_SPEED;
}

void player_repel(player_t *player)
{
    sfVector2f direction = {- sinf(RAD(player->angle)),
        cosf(RAD(player->angle))};

    if (player == nullptr)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        player->pos.x -= direction.x * PLAYER_SPEED;
        player->pos.y -= direction.y * PLAYER_SPEED;
    } else if (sfKeyboard_isKeyPressed(sfKeyS)) {
        player->pos.x += direction.x * PLAYER_SPEED;
        player->pos.y += direction.y * PLAYER_SPEED;
    }
}

