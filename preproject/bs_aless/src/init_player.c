/*
** EPITECH PROJECT, 2024
** bs_aless
** File description:
** init_player.c
*/

#include <SFML/Graphics.h>
#include "struct.h"

void init_player(Player_t *player)
{
    player->angle = 0;
    player->x = 0;
    player->y = 0;
    return;
}
