/*
** EPITECH PROJECT, 2025
** Woof3D
** File description:
** render_properties.c
*/

#include <stdlib.h>
#include "macro.h"
#include "rendering.h"
#include "struct.h"

int set_positions(player_t *player)
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

int set_propreties(player_t *player)
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
    return set_positions(player);
}
