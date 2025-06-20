/*
** EPITECH PROJECT, 2025
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
    sfTexture *wall_texture = sfTexture_createFromFile
    ("assets/wall_texture.jpg", nullptr);

    player->ray = sfRectangleShape_create();
    if (player->ray == nullptr || wall_texture == nullptr)
        return;
    sfRectangleShape_setTexture(player->ray, wall_texture, sfFalse);
    sfRectangleShape_setSize(player->ray, (sfVector2f){1, 1});
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
        (sfVector2f){DIM_X / 2 - 50, DIM_Y / 2});
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
        (sfVector2f){400, DIM_Y - 200});
    sfSprite_setScale(player->hud->sprite,
        (sfVector2f){1.5, 1.5});
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

static int create_shell(player_t *player)
{
    player->shell = calloc(1, sizeof(asset_t));
    if (player->shell == nullptr)
        return EXIT_FAILURE;
    player->shell->sprite = sfSprite_create();
    player->shell->rect = (sfIntRect){0, 0, 360, 360};
    player->shell->texture = sfTexture_createFromFile
    ("assets/shotgun_shell.png", &player->shell->rect);
    sfSprite_setScale(player->shell->sprite, (sfVector2f){0.2, 0.2});
    player->shell->pos = (sfVector2f){SCREEN_WIDTH / 2 + 175,
        SCREEN_HEIGHT / 2 + 360};
    sfSprite_setPosition(player->shell->sprite, player->shell->pos);
    sfSprite_setTexture(player->shell->sprite,
        player->shell->texture, sfFalse);
    return EXIT_SUCCESS;
}

static int set_positions(player_t *player)
{
    sfSprite_setPosition(player->shotgun->sprite,
        (sfVector2f){DIM_X / 2 - 180, DIM_Y - 450});
    sfSprite_setPosition(player->reticle->sprite,
        (sfVector2f){DIM_X / 2 - 30, DIM_Y / 2 + 30});
    sfSprite_setOrigin(player->reticle->sprite,
        (sfVector2f){(75 * 1.5) / 2, (75 * 1.5) / 2});
    init_impact(player);
    init_hitbox(player);
    init_ray(player);
    init_hud(player);
    player->plane = (sfVector2f){.x = 0, .y = 0.66};
    player->angle = RAD(M_PI);
    player->pos.x = 2 * MAP_TILE_SIZE;
    player->pos.y = 3 * MAP_TILE_SIZE;
    player->hp = 100;
    player->ammo = 1;
    return create_shell(player);
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
    sfSprite_setScale(player->shotgun->sprite, (sfVector2f){3, 3});
    sfSprite_setScale(player->reticle->sprite, (sfVector2f){1.5, 1.5});
    sfSprite_setTextureRect(player->shotgun->sprite, player->shotgun->rect);
    player->dir = (sfVector2f){.x = -1, .y = 0};
    player->plane = (sfVector2f){.x = 0, 0.66};
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
    init_bloom(player);
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

void init_tile(sfRectangleShape *tile, size_t i, size_t j, game_t *game)
{
    sfColor tile_color = {};

    switch (game->map->map[i][j]) {
        case 1:
            tile_color = sfWhite;
            break;
        case 2:
            tile_color = sfGreen;
            break;
        case 0:
            tile_color = sfBlack;
            break;
    }
    sfRectangleShape_setFillColor(tile, tile_color);
    sfRectangleShape_setOutlineColor(tile, (sfColor){125, 125, 125, 255});
    sfRectangleShape_setOutlineThickness(tile, 1);
    sfRectangleShape_setSize(tile, (sfVector2f){MAP_TILE_SIZE, MAP_TILE_SIZE});
    sfRectangleShape_setPosition(tile,
        (sfVector2f){j * MAP_TILE_SIZE, i * MAP_TILE_SIZE});
}

sfRectangleShape **init_map(game_t *game)
{
    sfRectangleShape **mini_map = malloc(sizeof(sfRectangleShape *) *
        ((game->map->height + 1) * game->map->width) + 1);
    size_t k = 0;

    if (mini_map == NULL)
        return NULL;
    for (size_t i = 0; i < game->map->height; i++) {
        for (size_t j = 0; j < game->map->width; j++) {
            mini_map[k] = sfRectangleShape_create();
            init_tile(mini_map[k], i, j, game);
            k++;
        }
    }
    mini_map[k] = NULL;
    return mini_map;
}
