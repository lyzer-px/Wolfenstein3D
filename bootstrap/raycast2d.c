/*
** EPITECH PROJECT, 2024
** bstrapwoof
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "bs.h"

void init_player(player_t *player)
{
    if (player == nullptr)
        return;
    player->hitbox = sfRectangleShape_create();
    if (player->hitbox == nullptr)
        return;
    init_hitbox(player);
    init_ray(player);
    player->angle = fmod(0, 2 * M_PI);
    player->pos.x = 400;
    player->pos.y = 300;
}

void cast_single_ray(player_t *player, float angle,
    sfRenderWindow *window)
{
    sfVector2f ray_direction = {- sinf(RAD(angle)), cosf(RAD(angle))};
    sfVector2f ray_pos = player->pos;
    float distance = 0;

    while (!is_wall((int)ray_pos.x / TILE_SIZE, (int)ray_pos.y / TILE_SIZE)) {
        ray_pos.x += ray_direction.x;
        ray_pos.y += ray_direction.y;
    }
    distance = sqrtf(SQUARED(ray_pos.x - player->pos.x) +
    SQUARED(ray_pos.y - player->pos.y));
    sfRectangleShape_setPosition(player->ray, ray_pos);
    sfRenderWindow_drawRectangleShape(window, player->ray, nullptr);
}

static void update_player(player_t *player, sfRenderWindow *window,
    sfRectangleShape **bounds)
{
    if (player == nullptr || window == nullptr || bounds == nullptr)
        return;
    for (size_t i = 0; i < DEG(FOV); i++)
        cast_single_ray(player, (player->angle - DEG(FOV / 2) + i), window);
    player_fwd(player);
    if (is_wall((int)(player->pos.x / TILE_SIZE),
        (int)(player->pos.y / TILE_SIZE))) {
        sfRenderWindow_drawRectangleShape(window, player->hitbox, nullptr);
        player_repel(player);
        return;
    }
    sfRectangleShape_setPosition(player->hitbox, player->pos);
    sfRectangleShape_setRotation(player->hitbox, player->angle);
    sfRenderWindow_drawRectangleShape(window, player->hitbox, nullptr);
}

void init_tile(sfRectangleShape *tile, size_t i, size_t j)
{
    sfRectangleShape_setFillColor(tile, map[i][j] ? sfWhite : sfBlack);
    sfRectangleShape_setOutlineColor(tile, (sfColor){125, 125, 125, 255});
    sfRectangleShape_setOutlineThickness(tile, 1);
    sfRectangleShape_setSize(tile, (sfVector2f){TILE_SIZE, TILE_SIZE});
    sfRectangleShape_setPosition(tile,
        (sfVector2f){j * TILE_SIZE, i * TILE_SIZE});
}

static sfRectangleShape **init_map(void)
{
    sfRectangleShape **bounds = malloc(sizeof(sfRectangleShape *) *
        (MAP_HEIGHT * MAP_WIDTH) + 1);
    size_t k = 0;

    if (bounds == nullptr)
        return nullptr;
    for (size_t i = 0; i < MAP_HEIGHT; i++) {
        for (size_t j = 0; j < MAP_WIDTH; j++) {
            bounds[k] = sfRectangleShape_create();
            init_tile(bounds[k], i, j);
            k++;
        }
    }
    bounds[k] = nullptr;
    return bounds;
}

static void draw_map(sfRenderWindow *window, sfRectangleShape **bounds)
{
    for (size_t i = 0; bounds[i] != nullptr; i++)
        sfRenderWindow_drawRectangleShape(window, bounds[i], NULL);
}

static void catch_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

static int end_game(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}

int init_game(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "bswolf",
        sfClose | sfResize, NULL);
    sfEvent event;
    player_t player = {0};
    sfRectangleShape **bounds = init_map();

    if (window == nullptr || bounds == nullptr)
        return EXIT_FAILURE;
    init_player(&player);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        draw_map(window, bounds);
        update_player(&player, window, bounds);
        catch_events(window, event);
        sfRenderWindow_display(window);
    }
    return end_game(window);
}
