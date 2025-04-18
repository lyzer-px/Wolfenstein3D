/*
** EPITECH PROJECT, 2024
** lib
** File description:
** struct.h
*/

#ifndef STRUCT
    #define STRUCT

    #include <SFML/Graphics.h>
    #include <stdbool.h>

typedef struct window_s {
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent event;
    bool full_screen;
} window_t;

typedef struct {
    float x;
    float y;
    float angle;
} Player_t;

    # define TILE_SIZE 64
    # define MAP_WIDTH 8
    # define MAP_HEIGHT 8

#endif /* STRUCT */
