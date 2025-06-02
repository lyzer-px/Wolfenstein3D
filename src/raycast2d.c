/*
** EPITECH PROJECT, 2024
** bstrapwoof
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "rendering.h"
#include "macro.h"

const sfColor sfGrey = {190, 190, 190, 255};

float cast_single_ray(player_t *player, float angle)
{
    sfVector2f ray_direction = {- sinf(RAD(angle)), cosf(RAD(angle))};
    sfVector2f ray_pos = player->pos;

    while (!is_wall(ON_INT_MAP(ray_pos.x), ON_INT_MAP(ray_pos.y))) {
        ray_pos.x += ray_direction.x * 0.05;
        ray_pos.y += ray_direction.y * 0.05;
    }
    return (sqrtf(SQUARED(ray_pos.x - player->pos.x) +
        SQUARED(ray_pos.y - player->pos.y))) *
        (cosf(RAD(player->angle) - RAD(angle)));
}

static void set_rect(float distance, sfRectangleShape *rect,
    double ray_idx, player_t *player)
{
    float rect_height = ((float)TILE_SIZE / distance) *
        ((float)SCREEN_WIDTH / 2);

    rect_height = rect_height > (float)SCREEN_HEIGHT ? (float)SCREEN_HEIGHT :
    rect_height;
    if (rect_height < 0)
        rect_height = SCREEN_HEIGHT;
    sfRectangleShape_setSize(rect, (sfVector2f){(SCREEN_WIDTH / 200),
        rect_height});
    sfRectangleShape_setFillColor(rect, player->flashlight_on ? sfWhite :
        sfGrey);
    sfRectangleShape_setPosition(rect, (sfVector2f){(ray_idx * RECT_SIZE),
        ((float)SCREEN_HEIGHT - rect_height) / 2});
}

static void draw_minimap(sfRenderWindow *window, player_t *player,
    sfRectangleShape **mini_map)
{
    for (size_t i = 0; mini_map[i] != NULL; i++)
        sfRenderWindow_drawRectangleShape(window, mini_map[i], NULL);
    sfRectangleShape_setPosition(player->hitbox, player->pos);
    sfRectangleShape_setRotation(player->hitbox, player->angle);
    sfRenderWindow_drawRectangleShape(window, player->hitbox, NULL);
}

static void draw_bloom(sfRenderWindow *window, sfCircleShape *circle)
{
    float radius = 500;
    sfColor sfLighted = {181, 144, 45, 75};

    sfCircleShape_setFillColor(circle, sfLighted);
    for (size_t i = 1; i != 3; i++) {
        sfCircleShape_setRadius(circle, radius * i);
        sfCircleShape_setOrigin(circle, (sfVector2f){(radius * i),
            (radius * i)});
        sfCircleShape_setPosition(circle, (sfVector2f){(DIM_X / 2),
            (DIM_Y / 2) + 25});
        sfLighted.a -= 30;
        sfRenderWindow_drawCircleShape(window, circle, NULL);
    }
}

static void handle_exceptions(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyF))
        game->player->flashlight_on = !game->player->flashlight_on;
    if (is_wall(ON_INT_MAP(game->player->pos.x),
        ON_INT_MAP(game->player->pos.y)))
        player_repel(game->player, game);
    if (game->player->flashlight_on)
        draw_bloom(game->window->window, game->player->bloom);
}

void tick_game(game_t *game)
{
    float distance = 0;
    float angle;
    sfRenderWindow *window = game->window->window;

    if (game->player == NULL || window == NULL)
        return;
    for (double i = 0; i < DEG(FOV); i += 0.25) {
        angle = (game->player->angle - DEG(FOV / 2) + i);
        distance = cast_single_ray(game->player, angle);
        set_rect(distance, game->rect, i, game->player);
        sfRenderWindow_drawRectangleShape(window, game->rect, NULL);
    }
    player_fwd(game->player, game);
    sfRenderWindow_drawSprite(window, game->player->shotgun->sprite, NULL);
    handle_exceptions(game);
    sfRenderWindow_drawSprite(window, game->player->reticle->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->player->hud->sprite, NULL);
    draw_minimap(window, game->player, game->mini_map);
}

int end_game(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}

sfRectangleShape *create_bg(sfVector2f size)
{
    sfRectangleShape *bg = sfRectangleShape_create();

    if (bg == NULL)
        return NULL;
    sfRectangleShape_setSize(bg, size);
    return bg;
}
