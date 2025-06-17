/*
** EPITECH PROJECT, 2025
** bstrapwoof
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "rendering.h"
#include "struct.h"
#include "macro.h"

const sfColor sfGrey = {190, 190, 190, 255};

static void draw_stripe(game_t *game, double perp_dist, coords_t c)
{
    sfRenderWindow *window = game->window->window;
    float stripe_height = (SCREEN_HEIGHT / perp_dist) * 5;
    int drawStart = -stripe_height / 2 + SCREEN_HEIGHT / 2;
    int tex_x = (int)(c.wall_x * 31) - 1;

    sfRectangleShape_setPosition(game->player->ray,
        (sfVector2f){c.x, drawStart});
    sfRectangleShape_setTextureRect(game->player->ray,
        (sfIntRect){tex_x, 0, 64, 62});
    sfRectangleShape_setSize(game->player->ray,
        (sfVector2f){1, stripe_height});
    sfRenderWindow_drawRectangleShape(window, game->player->ray, NULL);
}

static double dda_ray_cast(vect_t v, game_t *game, size_t x, bool draw)
{
    int side = 0;
    double perp_wall = 0;
    double wall_x = 0;

    while (map[v.map_pos->y][v.map_pos->x] != 1) {
        if (v.side_dist->x < v.side_dist->y) {
            v.side_dist->x += v.delta_dist->x;
            v.map_pos->x += v.step->x;
            side = 0;
        } else {
            v.side_dist->y += v.delta_dist->y;
            v.map_pos->y += v.step->y;
            side = 1;
        }
    }
    perp_wall = side == 0 ? v.side_dist->x - v.delta_dist->x :
        v.side_dist->y - v.delta_dist->y;
    wall_x = side == 0 ? game->player->pos.y +perp_wall * v.ray_dir->y :
        game->player->pos.x + perp_wall * v.ray_dir->x;
    if (draw)
        draw_stripe(game, perp_wall, (coords_t){wall_x - floor(wall_x), x});
    return perp_wall;
}

double cast_single_ray(game_t *g, double camera_x, size_t x, bool draw)
{
    sfVector2f ray_dir = {.x = ray_dir.x = PLAYER->dir.x +
        PLAYER->plane.x * camera_x,
        .y = PLAYER->dir.y + PLAYER->plane.y * camera_x};
    sfVector2i map_pos = {.x = ON_INT_MAP(PLAYER->pos.x),
        .y = ON_INT_MAP(PLAYER->pos.y)};
    sfVector2f side_dist = {};
    sfVector2f delta_dist = {.x = fabs((TILE_SIZE / ray_dir.x)),
        .y = fabs((TILE_SIZE / ray_dir.y))};
    sfVector2i step = {};

    step.x = ray_dir.x < 0 ? -1 : 1;
    step.y = ray_dir.y < 0 ? -1 : 1;
    side_dist.x = ray_dir.x < 0 ?
    (PLAYER->pos.x / TILE_SIZE - map_pos.x) * delta_dist.x : (map_pos.x + 1
    - PLAYER->pos.x / TILE_SIZE) * delta_dist.x;
    side_dist.y = ray_dir.y < 0 ? (PLAYER->pos.y / TILE_SIZE - map_pos.y) *
    delta_dist.y : (map_pos.y + 1 - PLAYER->pos.y / TILE_SIZE) * delta_dist.y;
    return dda_ray_cast((vect_t){&map_pos,
        &side_dist, &delta_dist, &step, &ray_dir}, g, x, draw);
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
    if (game->player->flashlight_on)
        draw_bloom(game->window->window, game->player->bloom);
}

void tick_game(game_t *game)
{
    sfRenderWindow *window = game->window->window;
    double camera_x = 0;
    char *infos = calloc(60, sizeof(char));

    if (game->player == NULL || window == NULL)
        return;
    for (size_t x = 0; x < SCREEN_WIDTH; x++) {
        camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
        cast_single_ray(game, camera_x, x, true);
    }
    draw_minimap(window, game->player, game->mini_map);
    player_fwd(game->player, game);
    sfRenderWindow_drawSprite(window, game->player->shotgun->sprite, NULL);
    handle_exceptions(game);
    sfRenderWindow_drawSprite(window, game->player->reticle->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->player->hud->sprite, NULL);
    sprintf(infos, "%i%%                                        %i", game->player->hp, game->player->ammo);
    sfText_setString(game->player_info, infos);
    sfRenderWindow_drawText(window, game->player_info, NULL);
    sfRenderWindow_drawSprite(window, game->player->shell->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->player->heart->sprite, NULL);
}

int end_game(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
