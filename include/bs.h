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

    #define FOV (M_PI / 3)
    #define NUM_RAYS 800
    #define M_PI		3.14159265358979323846
    #define TILE_SIZE 64
    #define MAP_WIDTH 8
    #define MAP_HEIGHT 8
    #define TILE_THICKNESS 10
    #define RAD(i) (i * (M_PI / 180))
    #define DEG(i) (i * (180 / M_PI))
    #define SQUARED(a) ((a) * (a))
    #define PLAYER_SPEED 0.1
    #define ON_INT_MAP(a, b) ((int)(a) / TILE_SIZE, (int)(b) / TILE_SIZE)

static const int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, -1},
    {1, 1, 1, 1, 1, 1, 1, 1},
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

void init_hitbox(player_t *player);
sfBool is_wall(int x, int y);
void init_ray(player_t *player);
int init_game(void);
void player_fwd(player_t *player);
void player_repel(player_t *player);

#endif
