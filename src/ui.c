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
    sfText_setPosition(game->player_info, (sfVector2f){SCREEN_HEIGHT - 300,
        SCREEN_WIDTH / 5});
    sfText_setString(game->player_info, str);
}
