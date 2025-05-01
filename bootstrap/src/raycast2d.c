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

float cast_single_ray(player_t *player, float angle)
{
    sfVector2f ray_direction = {- sinf(RAD(angle)), cosf(RAD(angle))};
    sfVector2f ray_pos = player->pos;

    while (!is_wall((int)ray_pos.x / TILE_SIZE, (int)ray_pos.y / TILE_SIZE)) {
        ray_pos.x += ray_direction.x;
        ray_pos.y += ray_direction.y;
    }
    return (sqrtf(SQUARED(ray_pos.x - player->pos.x) +
    SQUARED(ray_pos.y - player->pos.y))) * cosf(player->angle - angle);
}

static void set_rect(player_t *player, float distance, sfRectangleShape *rect, size_t ray_idx)
{
    float rect_height = (TILE_SIZE / distance) * (SCREEN_WIDTH / 2);

    sfRectangleShape_setSize(rect, (sfVector2f){10, rect_height});
    sfRectangleShape_setFillColor(rect, sfWhite);
    sfRectangleShape_setPosition(rect, (sfVector2f){(ray_idx * TILE_SIZE) / 7, (SCREEN_HEIGHT - rect_height) / 2});
}

static void update_player(player_t *player, sfRenderWindow *window,
    sfRectangleShape *rect)
{
    float distance = 0;
    float angle;

    if (player == nullptr || window == nullptr)
        return;
    for (size_t i = -DEG(FOV); i < DEG(FOV); i++) {
        angle = (player->angle - DEG(FOV / 2) + i);
        distance = cast_single_ray(player, angle);
        set_rect(player, distance, rect, i);
        sfRenderWindow_drawRectangleShape(window, rect, nullptr);
    }
    player_fwd(player);
    if (is_wall((int)(player->pos.x / TILE_SIZE),
        (int)(player->pos.y / TILE_SIZE))) {
        player_repel(player);
        return;
    }
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

static sfRectangleShape *create_bg(sfVideoMode mode, sfVector2f size)
{
    sfRectangleShape *bg = sfRectangleShape_create();

    if (bg == nullptr)
        return nullptr;
    sfRectangleShape_setSize(bg, size);
    return bg;
}

static void draw_bg(sfRenderWindow *window, sfRectangleShape *bg)
{
    if (window == nullptr || bg == nullptr)
        return;
    sfRectangleShape_setPosition(bg, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(bg, sfCyan);
    sfRenderWindow_drawRectangleShape(window, bg, nullptr);
    sfRectangleShape_setPosition(bg, (sfVector2f){0, sfRenderWindow_getSize(window).y / 2});
    sfRectangleShape_setFillColor(bg, sfGreen);
    sfRenderWindow_drawRectangleShape(window, bg, nullptr);
}

int init_game(void)
{
    sfVideoMode mode = {SCREEN_WIDTH, SCREEN_HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "bswolf",
        sfClose | sfResize, NULL);
    sfEvent event;
    player_t player = {};
    sfRectangleShape *bg = create_bg(mode, (sfVector2f){mode.width, mode.height / 2});
    sfRectangleShape *rect = create_bg(mode, (sfVector2f){1, 1});

    if (window == nullptr || bg == nullptr)
        return EXIT_FAILURE;
    init_player(&player);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        draw_bg(window, bg);
        update_player(&player, window, rect);
        catch_events(window, event);
        sfRenderWindow_display(window);
    }
    return end_game(window);
}
