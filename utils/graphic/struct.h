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

typedef struct ressource_s {
    // id to know which ressource is it
    char *id;
    // the ressource
    void *element;
    // how to set the position
    void (*setposition)(void *, sfVector2f *);
    // how to display the ressource
    void (*display)(sfRenderWindow *, void *, sfRenderStates *);
    // how to destroy the ressource
    void (*destroy)(void *);
    // next ressource
    struct ressource_s *next;
} ressource_t;

typedef struct component_s {
    // The ressource that you want to draw
    ressource_t *ressource;
    // The position of the ressource
    sfVector2f *pos;
    // next component
    struct component_s *next;
} component_t;

typedef struct layer_s {
    // id to know which layer is it
    int id;
    // an linked list, where each component of the layer is
    struct component_s *component;
    // the next layer of the scene
    struct layer_s *next;
    // is the print or not
    bool view : 1;
} layer_t;

typedef struct game_s game_t;

typedef struct scene_s {
    // id to know which scene is it
    int id_scene;
    // is the scene in pause (true or false)
    bool pause : 1;
    // a function where each event of the scene is
    void (*function_event)(struct game_s *);
    // a linked list where all the layer are
    struct layer_s *layer;
} scene_t;

typedef struct player_s {
    sfVector2f pos;
    float angle;
    sfRectangleShape *hitbox;
    sfRectangleShape *ray;
    sfCircleShape *bloom;
    bool flashlight_on;
} player_t;

struct game_s {
    player_t *player;
    sfRectangleShape **bounds;
    sfRectangleShape *rect;
    // how many scene do we have (if you  want to change it we have an macro)
    int nb_scene;
    // which scene do we show
    int actual_scene;
    // an array with all scene in it (all texture are create before the loop)
    struct scene_s **tab_scene;
    // stuct window where we have each window's information
    struct window_s *window;
    // all ressource
    struct ressource_s *ressource;
};

#endif /* STRUCT_H */
