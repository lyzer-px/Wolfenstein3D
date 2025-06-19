/*
** EPITECH PROJECT, 2024
** Woof3D
** File description:
** map_loader.c
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "rendering.h"
#include "struct.h"

static void fill_int_map(game_t *game, char *buf, FILE *fp)
{
    size_t k = 0;

    game->map->map = calloc(game->map->height, sizeof(int));
    if (game->map->map == nullptr)
        return;
    for (size_t i = 0; i < game->map->height; i++) {
        for (size_t j = 0; i < game->map->width; j++)
            game->map->map[i][j] = buf[k] - '0';
        k++;
    }
    free(buf);
    fclose(fp);
}

void map_load(char const *filepath, game_t *game)
{
    FILE *fp = fopen(filepath, "r");
    struct stat stat_buffer = {};
    char *buf = nullptr;
    const size_t map_size = game->map->height * (game->map->width + 1);

    if (filepath == nullptr) {
        game->map->map = (int **)base_map;
        game->map->height = MAP_HEIGHT;
        game->map->width = MAP_WIDTH;
    }
    if (fp == nullptr || stat(filepath, &stat_buffer)
        || stat_buffer.st_size < 16)
        return;
    fscanf(fp, "%lu;%lu\n", &game->map->height, &game->map->width);
    fseek(fp, stat_buffer.st_size - map_size, SEEK_SET);
    buf = calloc(map_size, sizeof(char));
    if (buf == nullptr || fread(buf, map_size, map_size, fp) != map_size)
        return;
    fill_int_map(game, buf, fp);
}