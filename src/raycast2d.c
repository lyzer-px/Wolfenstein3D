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
#include "struct.h"
#include "macro.h"

const sfColor sfGrey = {190, 190, 190, 255};

float cast_single_ray(player_t *player, float angle)
{
    return 0.0f;
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
    sfRectangleShape_setSize(rect, (sfVector2f){(SCREEN_WIDTH / 240),
        rect_height});
    sfRectangleShape_setFillColor(rect, player->flashlight_on ? sfWhite :
        sfGrey);
    sfRectangleShape_setPosition(rect, (sfVector2f){(ray_idx * RECT_SIZE) / 6,
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
        sfCircleShape_setPosition(circle, (sfVector2f){((float)DIM_X / 2),
            ((float)DIM_Y / 2) + 25});
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
    double camera_x = 0;
    sfVector2f ray_dir = {};
    sfRenderWindow *window = game->window->window;
    sfVector2i map = {};
    sfVector2d side_dist = {};
    sfVector2d delta_dist = {};
    double perp_wall_dist = 0;
    sfVector2i step = {0};


    if (game->player == NULL || window == NULL)
        return;
    for (double x = 0; x < SCREEN_WIDTH; x++) {
        camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
        ray_dir.x = game->player->direction.x;
        ray_dir.y = game->player->direction.y;
        map.x = ON_INT_MAP(game->player->pos.x);
        map.y = ON_INT_MAP(game->player->pos.y);
        delta_dist.x = (ray_dir.x == 0) ? 1e30 : abs(1 / ray_dir.x);
        delta_dist.x = (ray_dir.x == 0) ? 1e30 : abs(1 / ray_dir.x);
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

