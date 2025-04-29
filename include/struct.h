/*
** EPITECH PROJECT, 2025
** Wolf3D
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

#endif /* STRUCT */
