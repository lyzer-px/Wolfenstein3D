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
            game->map->map[i][j] = (buf[k] == '1' ? 1 : 0);
            k++;
        }
    }
    for (size_t i = 0; i < game->map->height; i++) {
        for (size_t j = 0; j < game->map->width; j++) {
            printf("%d", game->map->map[i][j]);
        }
        putchar('\n');
    }
    //free(buf);
    fclose(fp);
}

void map_load(char const *filepath, game_t *game)
{
    FILE *fp = fopen(filepath, "r");
    struct stat stat_buffer = {};
    char *buf = nullptr;
    size_t map_size = 0;

    game->map = calloc(1, sizeof(map_t));
    if (filepath == nullptr) {
        game->map->map = calloc(MAP_HEIGHT, sizeof(int *));
        for (int i = 0; i < MAP_HEIGHT; i++)
            game->map->map[i] = (int *)&base_map[i];
        game->map->height = MAP_HEIGHT;
        game->map->width = MAP_WIDTH;
    }
    if (fp == nullptr || stat(filepath, &stat_buffer)
        || stat_buffer.st_size < 16)
        return;
    fscanf(fp, "%lu;%lu\n", &game->map->height, &game->map->width);
    map_size = game->map->height * (game->map->width + 1);
    //
    printf("offset = %ld\n", stat_buffer.st_size - map_size);
    //
    fseek(fp, stat_buffer.st_size - map_size, SEEK_SET);
    game->map->map = calloc(game->map->height, sizeof(int *));
    buf = calloc(map_size, sizeof(char));
    if (buf == nullptr || fread(buf, map_size, map_size, fp) <= 0
        || game->map->map == nullptr)
        return;
    puts(buf);
    puts("");
    fill_int_map(game, buf, fp);
}