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
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent event;
} window_t;

typedef struct composant_s {
    int id;
    void *element;
    void (*function_display)(sfRenderWindow *, void *, sfRenderStates *);
    void (*function_destroy)(void *);
    struct composant_s *next;
} composant_t;

typedef struct layer_s {
    struct composant_s *composant;
    struct layer_s *next;
} layer_t;

typedef struct scene_s {
    int id_scene;
    bool pause;
    void (*function_event)(window_t *);
    struct layer_s *layer;
} scene_t;

typedef struct game_s {
    int nb_scene;
    int actual_scene;
    struct scene_s **tab_scene;
    struct window_s *window;
} game_t;

#endif /* STRUCT_H */
