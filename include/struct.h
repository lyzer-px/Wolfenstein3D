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
    // is full screen or not (true or false)
    bool full_screen : 1;
    // number max of frame in the window
    int frame;
    // the window (where you draw)
    sfRenderWindow *window;
    // the clock of the window
    sfClock *clock;
    // event on the window
    sfEvent event;
} window_t;

typedef struct composant_s {
    // id to know which composant is it
    int id;
    // the composant
    void *element;
    // how to display the composant
    void (*function_display)(sfRenderWindow *, void *, sfRenderStates *);
    // how to destroy the composant
    void (*function_destroy)(void *);
    // next composant
    struct composant_s *next;
} composant_t;

typedef struct layer_s {
    // id to know which layer is it
    int id;
    // an linked list, where each composant of the layer is
    struct composant_s *composant;
    // the next layer of the scene
    struct layer_s *next;
    // is the print or not
    bool view : 1;
} layer_t;

typedef struct game_s game_t;

typedef enum scene_id_s {
    PAUSE_MENU
} scene_id_t;

typedef struct scene_s {
    // id to know which scene is it
    int id_scene;
    // is the scene in pause (true or false)
    bool pause;
    // a function where each event of the scene is
    void (*function_event)(struct game_s *);
    // a linked list where all the layer are
    struct layer_s *layer;
} scene_t;

typedef struct game_s {
    // how many scene do we have (if you  want to change it we have an macro)
    int nb_scene;
    // which scene do we show
    int actual_scene;
    // an array with all scene in it (all texture are create before the loop)
    struct scene_s **tab_scene;
    // stuct window where we have each window's information
    struct window_s *window;
} game_t;

#endif /* STRUCT_H */
