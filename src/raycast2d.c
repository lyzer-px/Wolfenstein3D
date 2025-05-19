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

float cast_single_ray(player_t *player, float angle, sfRectangleShape *rect,
    sfRenderWindow *window)
{
    sfVector2f ray_direction = {- sinf(RAD(angle)), cosf(RAD(angle))};
    sfVector2f ray_pos = player->pos;

    while (!is_wall(ON_INT_MAP(ray_pos.x), ON_INT_MAP(ray_pos.y))) {
        ray_pos.x += ray_direction.x;
        ray_pos.y += ray_direction.y;
        sfRectangleShape_setPosition(rect, ray_pos);
        sfRenderWindow_drawRectangleShape(window, rect, NULL);
    }
    return (sqrtf(SQUARED(ray_pos.x - player->pos.x) +
    SQUARED(ray_pos.y - player->pos.y)));
}

static void set_rect(float distance, sfRectangleShape *rect,
    size_t ray_idx)
{
    float rect_height = (TILE_SIZE / distance) * (SCREEN_WIDTH / 2);

    if (rect_height < 0)
        rect_height = SCREEN_HEIGHT;
    sfRectangleShape_setSize(rect, (sfVector2f){10, rect_height});
    sfRectangleShape_setFillColor(rect, sfWhite);
    sfRectangleShape_setPosition(rect, (sfVector2f){(ray_idx * RECT_SIZE) / 7,
        (SCREEN_HEIGHT - rect_height) / 2});
}

static void prep_2d_ray(sfRectangleShape *ray)
{
    sfRectangleShape_setFillColor(ray, sfBlue);
    sfRectangleShape_setSize(ray, (sfVector2f){1, 1});
    sfRectangleShape_setOrigin(ray, (sfVector2f){0.5, 0.5});
}

static void draw_minimap(sfRenderWindow *window, player_t *player,
    sfRectangleShape **bounds)
{
    for (size_t i = 0; bounds[i] != NULL; i++)
        sfRenderWindow_drawRectangleShape(window, bounds[i], NULL);
    sfRectangleShape_setPosition(player->hitbox, player->pos);
    sfRectangleShape_setRotation(player->hitbox, player->angle);
    sfRenderWindow_drawRectangleShape(window, player->hitbox, NULL);
}

static void update_player(player_t *player, sfRenderWindow *window,
    sfRectangleShape *rect, sfRectangleShape **bounds)
{
    float distance = 0;
    float angle;

    if (player == NULL || window == NULL)
        return;
    draw_minimap(window, player, bounds);
    for (double i = 0; i < DEG(FOV); i++) {
        angle = (player->angle - DEG(FOV / 2) + i);
        prep_2d_ray(rect);
        distance = cast_single_ray(player, angle, rect, window)
        * cosf(RAD(player->angle) - RAD(angle));
        set_rect(distance, rect, i);
        sfRenderWindow_drawRectangleShape(window, rect, NULL);
    }
    player_fwd(player);
    if (is_wall((int)(player->pos.x / TILE_SIZE),
        (int)(player->pos.y / TILE_SIZE))) {
        player_repel(player);
        return;
    }
}

void catch_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

int end_game(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}

static sfRectangleShape *create_bg(sfVector2f size)
{
    sfRectangleShape *bg = sfRectangleShape_create();

    if (bg == NULL)
        return NULL;
    sfRectangleShape_setSize(bg, size);
    return bg;
}

static void draw_bg(sfRenderWindow *window, sfRectangleShape *bg)
{
    if (window == NULL || bg == NULL)
        return;
    sfRectangleShape_setPosition(bg, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(bg, sfCyan);
    sfRenderWindow_drawRectangleShape(window, bg, NULL);
    sfRectangleShape_setPosition(bg,
        (sfVector2f){0, SCREEN_HEIGHT / 2});
    sfRectangleShape_setFillColor(bg, sfGreen);
    sfRenderWindow_drawRectangleShape(window, bg, NULL);
}

int init_game(void)
{
    player_t player = {};
    sfRectangleShape **bounds = init_map();
    sfRectangleShape *bg = create_bg((sfVector2f){mode.width,
        mode.height / 2});
    sfRectangleShape *rect = create_bg((sfVector2f){1, 1});

    if (window == NULL || bg == NULL || init_player(&player) < 0)
        return EXIT_FAILURE;
    while (0) {
        draw_bg(window, bg);
        update_player(&player, window, rect, bounds);
        catch_events(window, event);
        sfRenderWindow_display(window);
    }
    return end_game(window);
}
