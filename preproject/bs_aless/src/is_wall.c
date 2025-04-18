/*
** EPITECH PROJECT, 2024
** bs_aless
** File description:
** is_wall.c
*/

#include "struct.h"

int is_wall(int x, int y, int **map)
{
    if (x < 0 || y < 0 || x >= MAP_HEIGHT || y >= MAP_WIDTH)
        return -1;
    return map[x][y];
}
