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

    for (size_t i = 0; i <= game->map->height; i++) {
        game->map->map[i] = calloc(game->map->width + 1, sizeof(int));
        for (size_t j = 0; j <= game->map->width; j++) {
            game->map->map[i][j] = (buf[k] - '0');
            k++;
        }
    }
    free(buf);
    fclose(fp);
}

static int set_map(game_t *game, FILE *fp, struct stat *stat_buffer, char *buf)
{
    size_t map_size = game->map->height * (game->map->width + 1);

    fseek(fp, stat_buffer->st_size - map_size, SEEK_SET);
    game->map->map = calloc(game->map->height, sizeof(int *));
    buf = calloc(map_size, sizeof(char));
    if (game == nullptr || game->map->height & 1 || game->map->width & 1
        || fread(buf, map_size, map_size, fp) <= 0
        || game->map->map == nullptr)
        return -1;
    fill_int_map(game, buf, fp);
    return EXIT_SUCCESS;
}

int map_load(char const *filepath, game_t *game)
{
    FILE *fp = nullptr;
    struct stat stat_buffer = {};
    char *buf = nullptr;
    char const *abs_path = filepath == nullptr ? BASE_MAP : filepath;

    game->map = calloc(1, sizeof(map_t));
    fp = fopen(abs_path, "r");
    if (fp == nullptr || stat(abs_path, &stat_buffer)
        || stat_buffer.st_size < 16)
        return -1;
    fscanf(fp, "%lu;%lu\n", &game->map->height, &game->map->width);
    return set_map(game, fp, &stat_buffer, buf);
}
