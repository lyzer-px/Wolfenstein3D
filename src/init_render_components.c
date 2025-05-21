/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** inits.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "macro.h"
#include "rendering.h"

void init_ray(player_t *player)
{
    player->ray = sfRectangleShape_create();
    if (player->ray == NULL)
        return;
    sfRectangleShape_setSize(player->ray, (sfVector2f){1, 1});
    sfRectangleShape_setFillColor(player->ray, sfBlue);
    sfRectangleShape_setOrigin(player->ray, (sfVector2f){2, 2});
}

void init_hitbox(player_t *player)
{
    sfRectangleShape_setFillColor(player->hitbox, sfRed);
    sfRectangleShape_setSize(player->hitbox,
        (sfVector2f){PLAYER_SIZE, PLAYER_SIZE});
    sfRectangleShape_setOrigin(player->hitbox,
        (sfVector2f){PLAYER_SIZE / 2, PLAYER_SIZE / 2});
    sfRectangleShape_setPosition(player->hitbox, (sfVector2f){400, 300});
    sfRectangleShape_setRotation(player->hitbox, player->angle);
}

int init_player(player_t *player)
{
    if (player == NULL)
        return -1;
    player->hitbox = sfRectangleShape_create();
    if (player->hitbox == NULL)
    return -1;
    player->bloom = sfCircleShape_create();
    if (player->bloom == NULL)
        return -1;
    init_hitbox(player);
    init_ray(player);
    player->angle = 0;
    player->pos.x = 20;
    player->pos.y = 30;
    return EXIT_SUCCESS;
}

void init_tile(sfRectangleShape *tile, size_t i, size_t j)
{
    sfRectangleShape_setFillColor(tile, map[i][j] ? sfWhite : sfBlack);
    sfRectangleShape_setOutlineColor(tile, (sfColor){125, 125, 125, 255});
    sfRectangleShape_setOutlineThickness(tile, 1);
    sfRectangleShape_setSize(tile, (sfVector2f){TILE_SIZE, TILE_SIZE});
    sfRectangleShape_setPosition(tile,
        (sfVector2f){j * TILE_SIZE, i * TILE_SIZE});
}

static bool destroy_bounds(sfRectangleShape **bounds, size_t k)
{
    if (bounds[k] == NULL) {
        for (size_t j = 0; j < k; j++)
            sfRectangleShape_destroy(bounds[j]);
        free(bounds);
        return true;
    }
    return false;
}

sfRectangleShape **init_map(void)
{
    sfRectangleShape **bounds = malloc(sizeof(sfRectangleShape *) *
        ((MAP_HEIGHT + 1) * MAP_WIDTH) + 1);
    size_t k = 0;

    if (bounds == NULL)
        return NULL;
    for (size_t i = 0; i < MAP_HEIGHT; i++) {
        for (size_t j = 0; j < MAP_WIDTH; j++) {
            bounds[k] = sfRectangleShape_create();
            if (destroy_bounds(bounds, k))
                return NULL;
            init_tile(bounds[k], i, j);
            k++;
        }
    }
    bounds[k] = NULL;
    return bounds;
}
