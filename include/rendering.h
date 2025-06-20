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
    #define MAP game->map->map
    #define MAP_DIR(b, s) (ON_INT_MAP((player->pos.b s dir.b * PLAYER_SPEED)))
    #define DIR_COLLIDE(c, d, e, f) (!MAP[MAP_DIR(c, d)][MAP_DIR(e, f)])

    #define SCREEN_WIDTH 1920
    #define SCREEN_HEIGHT 1080
    #define INFO_FORMAT "%i%%                                        %i"

    #define PLAYER (g->player)
    #define BASE_MAP "assets/maps/base_map.txt"

    #define D_SIDE(a) &v.side_dist->a, v.delta_dist->a
    #define M_STEP(a) &v.map_pos->a, v.step->a
    #define POS_ARGS(a) D_SIDE(a), M_STEP(a)

typedef struct tile_s {
    sfRectangleShape *rect;
    bool wall;
} tile_t;

sfRectangleShape *create_bg(sfVector2f size);

bool is_wall(int x, int y, game_t *game);

int launch_game(void);
void player_fwd(player_t *player, game_t *game);

void player_repel(player_t *player, game_t *game);

void init_ray(player_t *player);
int init_player(player_t *player);

void init_tile(sfRectangleShape *tile, size_t i, size_t j, game_t *game);

void init_hitbox(player_t *player);
sfRectangleShape **init_map(game_t *game);

void tick_game(game_t *game);

void shotgun_move(game_t *game);
void shotgun_shoot(game_t *game);

hit_info_t cast_single_ray(game_t *g, double camera_x, size_t x, bool draw);

void create_heart(game_t *game);

void init_text(game_t *game, char *str);

void init_bloom(player_t *player);

int map_load(char const *filepath, game_t *game);
#endif
