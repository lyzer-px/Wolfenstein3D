/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** inits.c
*/

#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <stdio.h>
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

static void init_impact(player_t *player)
{
    player->impact = calloc(1, sizeof(asset_t));
    if (player->impact == NULL)
        return;
    player->impact->rect = (sfIntRect){0, 0, 707, 353};
    player->impact->sprite = sfSprite_create();
    player->impact->texture =
    sfTexture_createFromFile("assets/impact-frame.png", &player->impact->rect);
    if (player->impact->sprite == NULL || player->impact->texture == NULL)
        return;
    sfSprite_setTexture(player->impact->sprite,
        player->impact->texture, sfFalse);
    sfSprite_setOrigin(player->impact->sprite,
        (sfVector2f){707 / 2, 353 / 2});
    sfSprite_setPosition(player->impact->sprite,
        (sfVector2f){DIM_X / 2, DIM_Y / 2 + 30});
}

static void init_hud(player_t *player)
{
    player->hud = calloc(1, sizeof(asset_t));
    if (player->hud == NULL)
        return;
    player->hud->rect = (sfIntRect){0, 0, 640, 77};
    player->hud->sprite = sfSprite_create();
    player->hud->texture = sfTexture_createFromFile("assets/HUD.png",
        &player->hud->rect);
    if (player->hud->sprite == NULL || player->hud->texture == NULL)
        return;
    sfSprite_setTexture(player->hud->sprite,
        player->hud->texture, sfFalse);
    sfSprite_setPosition(player->hud->sprite,
        (sfVector2f){80, DIM_Y - 90});
    sfSprite_setScale(player->hud->sprite,
        (sfVector2f){1.25, 1.25});
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

static int set_positions(player_t *player)
{
    sfSprite_setPosition(player->shotgun->sprite,
        (sfVector2f){DIM_X / 2 - 90, DIM_Y - 250});
    sfSprite_setPosition(player->reticle->sprite,
        (sfVector2f){DIM_X / 2, DIM_Y / 2 + 30});
    sfSprite_setOrigin(player->reticle->sprite,
        (sfVector2f){75 / 2, 75 / 2});
    init_impact(player);
    init_hitbox(player);
    init_ray(player);
    init_hud(player);
    player->angle = 0;
    player->pos.x = 20;
    player->pos.y = 30;
    return EXIT_SUCCESS;
}

static int set_propreties(player_t *player)
{
    player->reticle = calloc(1, sizeof(asset_t));
    if (player->reticle == NULL)
        return -1;
    player->reticle->sprite = sfSprite_create();
    player->reticle->texture = sfTexture_createFromFile("assets/reticle.png",
        NULL);
    if (player->reticle->sprite == NULL || player->reticle->texture == NULL)
        return -1;
    player->shotgun->rect = (sfIntRect){0, 0, 70, 90};
    sfSprite_setTexture(player->reticle->sprite, player->reticle->texture,
        sfFalse);
    sfSprite_setTexture(player->shotgun->sprite,
        player->shotgun->texture, sfFalse);
    sfSprite_setScale(player->shotgun->sprite, (sfVector2f){2, 2});
    sfSprite_setTextureRect(player->shotgun->sprite, player->shotgun->rect);
    player->direction = (sfVector2f){.x = -1, .y = 0};
    player->cam_plane = (sfVector2f){.x = 0, 0.66};
    return set_positions(player);
}

int init_player(player_t *player)
{
    player->shotgun = calloc(1, sizeof(asset_t));
    if (player == NULL || player->shotgun == NULL)
        return -1;
    player->hitbox = sfRectangleShape_create();
    if (player->hitbox == NULL)
        return -1;
    player->bloom = sfCircleShape_create();
    if (player->bloom == NULL)
        return -1;
    player->shotgun->sprite = sfSprite_create();
    if (player->shotgun->sprite == NULL)
        return -1;
    player->shotgun->texture =
    sfTexture_createFromFile("assets/weapons/shotgun.png", NULL);
    if (player->shotgun->texture == NULL)
        return -1;
    player->clock = sfClock_create();
    if (player->clock == NULL)
        return -1;
    return set_propreties(player);
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

sfRectangleShape **init_map(void)
{
    sfRectangleShape **mini_map = malloc(sizeof(sfRectangleShape *) *
        ((MAP_HEIGHT + 1) * MAP_WIDTH) + 1);
    size_t k = 0;

    if (mini_map == NULL)
        return NULL;
    for (size_t i = 0; i < MAP_HEIGHT; i++) {
        for (size_t j = 0; j < MAP_WIDTH; j++) {
            mini_map[k] = sfRectangleShape_create();
            init_tile(mini_map[k], i, j);
            k++;
        }
    }
    mini_map[k] = NULL;
    return mini_map;
}
