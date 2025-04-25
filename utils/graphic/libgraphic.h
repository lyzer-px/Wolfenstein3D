/*
** EPITECH PROJECT, 2024
** Wolf
** File description:
** libgraphic.h
*/

#ifndef LIBGRAPHIC_H
    #define LIBGRAPHIC_H

    #include <SFML/Graphics.h>
    #include "struct.h"

typedef struct button_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect area;
    sfVector2i pos;
} button_t;

typedef struct button_tab_s {
    char *path_sprite;
    sfIntRect rect;
    sfVector2i pos;
} button_tab_t;

    #define SIZE_TAB_BUTTON 4

static const button_tab_t tab_button[] = {
    {NULL, {0, 0, 0, 0}, {0, 0}}
};

/*
** FUNCTION
*/

// Create a window on which to draw
sfRenderWindow *make_window(sfVector2i dimensions,
    int bits, char *name, sfUint32 style);

// Create a window on which to draw in a struct window_t
// (fullscreen or window)
void change_the_mode_window(window_t *win);

// Create a struct_window (the window on which to draw is already create)
window_t *create_window(void);

// initialise a tab's scene
scene_t **init_tab_scene(int nb_scene);

// Create a struct game (everything is already update)
game_t *init_game(void);

// Reverse the list of composant
void rev_composant(composant_t **begin);

// Add an element to a scene (begin_scene is the begin of composants in scene)
void add_element_to_scene(void *element,
    void (*function_display)(sfRenderWindow *, void *, sfRenderStates *),
    void (*function_destroy)(void *), composant_t **begin_scene);

// Create a layer to the scene
void create_layer(scene_t **scene);

// Create an composant but it's not in a layer (yes the composant just exist)
composant_t *create_composant(void *element,
    void (*function_display)(sfRenderWindow *, void *, sfRenderStates *),
    void (*function_destroy)(void *));

// Add an created composant to a layer of a scene, according to id
void add_a_composant_to_layer(composant_t *composant, scene_t *scene, int id);

// draw each composant of scene
void draw_composant_of_scene(sfRenderWindow *window, scene_t *scene);

// Remove all composant of a layer
void clean_layer(layer_t *layer);

// Clean a scene
void clean_scene(scene_t *scene);

// Clean a game
void clean_game(game_t *game);

// destroy a composant
void destroy_composant(composant_t **composant);

// Destroy a layer
void destroy_layer(layer_t **layer);

// Destoy a scene
void destroy_scene(scene_t **scene);

// Destroy a struct game
void destroy_game(game_t **game);

// Destroy a tab of scene
void free_tab_scene(game_t *game);

// Destroy a struct window_t
void destroy_window(window_t **window);

#endif /* LIBGRAPHIC_H */
