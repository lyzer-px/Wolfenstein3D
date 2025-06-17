/*
** EPITECH PROJECT, 2024
** Woof3D
** File description:
** ui.c
*/

#include <stdio.h>
#include "rendering.h"
#include "struct.h"

sfText *create_text(game_t *game)
{
    sfFont *font = sfFont_createFromFile("assets/Font/Horror_font.ttf");
    char buf[25] = {};

    game->player_info = sfText_create();
    if (game->player_info == nullptr || font == nullptr)
        return nullptr;
    sfText_setCharacterSize(game->player_info, 50);
    sfText_setFont(game->player_info, font);
    sfText_setPosition
    (game->player_info, (sfVector2f){SCREEN_HEIGHT - 300, SCREEN_WIDTH / 2});
    sprintf(buf, "%i%% %i", game->player->hp, game->player->ammo);
    sfText_setString(game->player_info, buf);
}