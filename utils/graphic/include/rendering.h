/*
** EPITECH PROJECT, 2024
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

    #define FOV (M_PI / 2) // The Field of view in radians
    #define M_PI 3.14159265358979323846
    #define RAD(i) (i * (M_PI / 180)) // Degrees to radians
    #define DEG(i) (i * (180 / M_PI)) // Radians to degrees
    #define SQUARED(a) ((a) * (a)) // does x ^ 2


    #define TILE_SIZE 10 // the size of tiles in the minimap
    #define PLAYER_SIZE 10 // the size of the player's rectangle on minimap
    #define RECT_SIZE 64 // the size of the rectangles used to make walls
    #define MAP_WIDTH 16
    #define MAP_HEIGHT 16
    #define TILE_THICKNESS 10 // The thickness of tile outlines

    #define PLAYER_SPEED 0.1
    #define ROTATION_SPEED 0.2

    // Transposes real coords on the int map
    #define ON_INT_MAP(a) (((int)(a) / TILE_SIZE))
    //

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

typedef struct tile_s {
    sfRectangleShape *rect;
    bool wall;
} tile_t;
sfRectangleShape *create_bg(sfVector2f size);

sfBool is_wall(int x, int y);
int launch_game(void); // Launches the game
void player_fwd(player_t *player); // player angle and directional input

// function to negate movement when collision happens
void player_repel(player_t *player);
//

void init_ray(player_t *player); // Inits ray propreties
int init_player(player_t *player); // Inits player stats

// Creates a tile for the minimap
void init_tile(sfRectangleShape *tile, size_t i, size_t j);
//

void init_hitbox(player_t *player); // Inits player hitbox on minimap
sfRectangleShape **init_map(void); // Inits the map to be shown on the screen

void tick_game(game_t *game);

#endif
