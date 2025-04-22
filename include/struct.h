/*
** EPITECH PROJECT, 2024
** lib
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <SFML/Graphics.h>
    #include <stdbool.h>

typedef struct window_s {
    bool full_screen : 1;
    int frame;
    sfColor color;
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent event;
} window_t;

typedef struct composant_s {
    void *element;
    void (*function_display)(sfRenderWindow *, void *);
    void (*function_destroy)(void *);
    struct composant_s *next;
} composant_t;

typedef struct scene_s {
    int id_scene;
    sfTexture *background_texture;
    sfSprite *background_sprite;
    void (*function_event)(sfRenderWindow *);
    struct composant_t *begin;
} scene_t;

typedef struct game_s {
    int nb_scene;
    struct scene_s **tab_scene;
    struct window_s *window;
} game_t;

#endif /* STRUCT_H */
