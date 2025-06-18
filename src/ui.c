/*
** EPITECH PROJECT, 2024
** Woof3D
** File description:
** ui.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "rendering.h"
#include "struct.h"

void create_heart(game_t *game)
{
    game->player->heart = calloc(1, sizeof(game_t));
    if (game->player->heart == nullptr)
        return;
    game->player->heart->sprite = sfSprite_create();
    game->player->heart->rect = (sfIntRect){0, 0, 850, 772};
    game->player->heart->texture = sfTexture_createFromFile("assets/heart.jpg",
        &game->player->heart->rect);
    game->player->heart->pos = (sfVector2f)
        {SCREEN_WIDTH / 4, SCREEN_HEIGHT - 180};
    sfSprite_setTexture(game->player->heart->sprite,
        game->player->heart->texture, sfFalse);
    sfSprite_setPosition(game->player->heart->sprite,
        game->player->heart->pos);
    sfSprite_setScale(game->player->heart->sprite, (sfVector2f){0.15, 0.15});
}

void init_text(game_t *game, char *str)
{
    game->player_info = sfText_create();
    if (game->player_info == nullptr)
        return;
    sfText_setFont(game->player_info,
        sfFont_createFromFile("assets/Font/arial.ttf"));
    sfText_setCharacterSize(game->player_info, 50);
    sfText_setPosition(game->player_info, (sfVector2f){SCREEN_WIDTH / 4 + 80,
        SCREEN_WIDTH / 2 - 55});
    sfText_setString(game->player_info, str);
}

void init_bloom(player_t *player)
{
    player->bloom = calloc(1, sizeof(asset_t));
    if (player->bloom == nullptr)
        return;
    player->bloom->sprite = sfSprite_create();
    if (player->bloom->sprite == nullptr)
        return;
    player->bloom->rect = (sfIntRect){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    player->bloom->texture = sfTexture_createFromFile(
        "assets/flash_effect.png", &player->bloom->rect);
    player->bloom->pos = (sfVector2f){0, 0};
    if (player->bloom->texture == nullptr)
        return;
    sfSprite_setTexture(player->bloom->sprite,
        player->bloom->texture, sfFalse);
    sfSprite_setScale(player->bloom->sprite, (sfVector2f){4.777, 2.673});
    player->flashlight_on = false;
}
