/*
** EPITECH PROJECT, 2025
** bstrapwoof
** File description:
** rendering.h
*/

#ifndef RENDERING_H
    #define RENDERING_H

    #include <math.h>
    #include <SFML/Graphics/RectangleShape.h>
    #include <stdbool.h>
    #include "struct.h"

    #define FOV (M_PI / 2)
    #define M_PI 3.14159265358979323846
    #define RAD(i) (i * (M_PI / 180))
    #define DEG(i) (i * (180 / M_PI))
    #define SQUARED(a) ((a) * (a))
    #define ABS(a) ((a) < 0 ? -(a) : (a))

    #define RECT_MODIF 5
    #define TILE_SIZE 10
    #define MAP_TILE_SIZE 10
    #define PLAYER_SIZE 5
    #define RECT_SIZE 1
    #define MAP_WIDTH 16
    #define MAP_HEIGHT 16
    #define TILE_THICKNESS 10

    #define PLAYER_SPEED 0.7
    #define  ROTATION_SPEED 0.05

    #define ON_INT_MAP(a) (((int)(a) / TILE_SIZE))
    #define MAP_DIR(b, s) (ON_INT_MAP((player->pos.b s dir.b * PLAYER_SPEED)))
    #define DIR_COLLIDE(c, d, e, f) (!map[MAP_DIR(c, d)][MAP_DIR(e, f)])

    #define SCREEN_WIDTH 1920
    #define SCREEN_HEIGHT 1080

    #define PLAYER (g->player)

static const int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};


typedef struct tile_s {
    sfRectangleShape *rect;
    bool wall;
} tile_t;

sfRectangleShape *create_bg(sfVector2f size);

bool is_wall(int x, int y);

int launch_game(void);
void player_fwd(player_t *player, game_t *game);

void player_repel(player_t *player, game_t *game);

void init_ray(player_t *player);
int init_player(player_t *player);

void init_tile(sfRectangleShape *tile, size_t i, size_t j);

void init_hitbox(player_t *player);
sfRectangleShape **init_map(void);

void tick_game(game_t *game);

void shotgun_move(game_t *game);
void shotgun_shoot(game_t *game);

void cast_single_ray(game_t *g, double camera_x, size_t x);


void create_heart(game_t *game);

void init_text(game_t *game, char *str);
#endif
