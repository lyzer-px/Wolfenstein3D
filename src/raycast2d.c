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

static double draw_stripe(game_t *game,
    double perp_dist, coords_t c, bool draw)
{
    sfRenderWindow *window = game->window->window;
    float stripe_height = (SCREEN_HEIGHT / perp_dist) * 5;
    int drawStart = -stripe_height / 2 + SCREEN_HEIGHT / 2;
    int tex_x = (int)(c.wall_x * 31) - 1;

    if (draw) {
        sfRectangleShape_setPosition(game->player->ray,
            (sfVector2f){c.x, drawStart});
        sfRectangleShape_setTextureRect(game->player->ray,
            (sfIntRect){tex_x, 0, 64, 62});
        sfRectangleShape_setSize(game->player->ray,
            (sfVector2f){1, stripe_height});
        sfRenderWindow_drawRectangleShape(window, game->player->ray, NULL);
    }
    return perp_dist;
}

static void increment_pos(float *side_dist, float delta_dist,
    int *map_pos, int step)
{
    *side_dist += delta_dist;
    *map_pos += step;
}

static hit_info_t dda_ray_cast(vect_t v, game_t *game, size_t x, bool draw)
{
    int side = 0;
    double p_dist = 0;
    double wl_x = 0;

    while (!game->map->map[v.map_pos->y][v.map_pos->x]) {
        if (v.side_dist->x < v.side_dist->y) {
            increment_pos(POS_ARGS(x));
            side = 0;
        } else {
            increment_pos(POS_ARGS(y));
            side = 1;
        }
    }
    p_dist = side == 0 ? v.side_dist->x - v.delta_dist->x :
        v.side_dist->y - v.delta_dist->y;
    wl_x = side == 0 ? game->player->pos.y + p_dist * v.ray_dir->y :
        game->player->pos.x + p_dist * v.ray_dir->x;
    return (hit_info_t){v.map_pos->x, v.map_pos->y,
        draw_stripe(game, p_dist, (coords_t){wl_x - floor(wl_x), x}, draw)};
}

hit_info_t cast_single_ray(game_t *g, double camera_x, size_t x, bool draw)
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

static void handle_exceptions(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyF) &&
        sfClock_getElapsedTime(game->player->clock).microseconds >= 100000) {
        game->player->flashlight_on = !game->player->flashlight_on;
        sfClock_restart(game->player->clock);
    }
    if (game->player->flashlight_on == false)
        sfRenderWindow_drawSprite(game->window->window,
            game->player->bloom->sprite, NULL);
}

static void end_tick(game_t *game, sfRenderWindow *window, char *infos)
{
    player_fwd(game->player, game);
    handle_exceptions(game);
    draw_minimap(window, game->player, game->mini_map);
    sfRenderWindow_drawSprite(window, game->player->shotgun->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->player->reticle->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->player->hud->sprite, NULL);
    sprintf(infos, INFO_FORMAT, game->player->hp, game->player->ammo);
    sfText_setString(game->player_info, infos);
    sfRenderWindow_drawText(window, game->player_info, NULL);
    sfRenderWindow_drawSprite(window, game->player->shell->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->player->heart->sprite, NULL);
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
    end_tick(game, window, infos);
}

int end_game(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
