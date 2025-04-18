/*
** EPITECH PROJECT, 2024
** lib
** File description:
** struct.h
*/

#ifndef STRUCT
    #define STRUCT

    #include <SFML/Graphics.h>

typedef struct window_s {
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent event;
    int frame;
} window_t;

#endif /* STRUCT */
