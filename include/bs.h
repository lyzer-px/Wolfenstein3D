/*
** EPITECH PROJECT, 2024
** bstrapwoof
** File description:
** bs.h
*/

#ifndef BS_H
    #define BS_H

    #include <math.h>
    #include <SFML/Graphics/RectangleShape.h>
    #include <stdbool.h>

    #define FOV (M_PI / 2)
    #define NUM_RAYS 60
    #define M_PI		3.14159265358979323846
    #define TILE_SIZE 10
    #define PLAYER_SIZE 10
    #define RECT_SIZE 64
    #define MAP_WIDTH 16
    #define MAP_HEIGHT 16
    #define TILE_THICKNESS 10
    #define RAD(i) (i * (M_PI / 180))
    #define DEG(i) (i * (180 / M_PI))
    #define SQUARED(a) ((a) * (a))
    #define PLAYER_SPEED 0.1
    #define ON_INT_MAP(a, b) ((int)(a) / TILE_SIZE, (int)(b) / TILE_SIZE)
    #define SCREEN_WIDTH 800
    #define SCREEN_HEIGHT 600

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

typedef struct player_s {
    sfVector2f pos;
    float angle;
    sfRectangleShape *hitbox;
    sfRectangleShape *ray;
} player_t;

typedef struct tile_s {
    sfRectangleShape *rect;
    bool wall;
} tile_t;

sfBool is_wall(int x, int y);
int init_game(void);
void player_fwd(player_t *player);
void player_repel(player_t *player);
void init_ray(player_t *player);
int init_player(player_t *player);
void init_tile(sfRectangleShape *tile, size_t i, size_t j);
void init_hitbox(player_t *player);
void init_ray(player_t *player);
sfRectangleShape **init_map(void);
#endif
