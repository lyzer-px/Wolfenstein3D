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
    sfVector2f pos;
} button_t;

typedef struct button_tab_s {
    char *path_sprite;
    sfIntRect rect;
    sfVector2f pos;
} button_tab_t;

    #define SIZE_TAB_BUTTON 4

typedef enum {
    CONTINUE,
    SAVE,
    SETTING_BUTTON,
    EXIT
}button_pause_menu_id_t;

static const button_tab_t button_pause_menu[] = {
    {"assets/buttons/Continue 192x48.png", {0, 0, 192, 48}, {100, 100}},
    {"assets/buttons/Save Game 192x48.png", {0, 0, 192, 48}, {100, 200}},
    {"assets/buttons/Settings 192x48.png", {0, 0, 192, 48}, {100, 300}},
    {"assets/buttons/Exit 192x48.png", {0, 0, 192, 48}, {100, 400}},
    {NULL, {0, 0, 0, 0}, {0, 0}}
};

typedef enum {
    START,
    LOAD_SAVE,
    SETTING_BUTTON_FROM_MENU,
    EXIT_FROM_MENU
}button_start_menu_id_t;

static const button_tab_t button_start_menu[] = {
    {"assets/buttons/Start 192x48.png", {0, 0, 192, 48}, {432, 100}},
    {"assets/buttons/Save 192x48.png", {0, 0, 192, 48}, {432, 200}},
    {"assets/buttons/Settings 192x48.png", {0, 0, 192, 48}, {432, 300}},
    {"assets/buttons/Exit 192x48.png", {0, 0, 192, 48}, {432, 400}},
    {NULL, {0, 0, 0, 0}, {0, 0}}
};

/*
** FUNCTION
*/

        // GAME

// Create a struct game (everything is already update)
game_t *init_game(void);

// Clean a game
void clean_game(game_t *game);

// Destroy a tab of scene
void free_tab_scene(game_t *game);

// Destroy a struct game
void destroy_game(game_t *game);

// Create all ressource by the config file
void load_config_file(game_t *game);

        // WINDOW

// Create a window on which to draw
sfRenderWindow *make_window(sfVector2i dimensions,
    int bits, char *name, sfUint32 style);

// Create a window on which to draw in a struct window_t
// (fullscreen or window)
void change_the_mode_window(window_t *win);

// Create a struct_window (the window on which to draw is already create)
window_t *create_window(void);

// Destroy a struct window_t
void destroy_window(window_t *window);

        // RESSOURCES

// Find a type by a str formated
int find_type(char *str);

// Create an element by the type and a filename
void *create_element(int type, char *filename);

// Create a ressource (the type is in a enum called type_id)
ressource_t *create_ressource(char *id, void *element, int type);

// Add to a linked list a ressource already created
void add_ressource(ressource_t **begin, ressource_t *new_ressource);

// Create and add a ressource to the linked list
void create_ressource_link(ressource_t **begin, char *id,
    void *element, int type);

// Create a ressource already in the struct game
void create_a_ressource_in_the_game(game_t *game, char *id,
    void *element, int type);

// Search a ressource from an id (if id is doesn't exist the function return
// NULL)
ressource_t *find_a_ressouce_from_id(ressource_t *begin, char *id);

// Destroy a ressource
void destroy_ressource(ressource_t **ressource);

// Destroy all ressource in a linked list
void destroy_all_ressource(ressource_t **ressource_begin);

        // SCENE

// initialise a tab's scene
scene_t **init_tab_scene(int nb_scene);

// Add an element to a scene (begin_scene is the begin of components in scene)
void add_element_to_scene(sfVector2f *pos, ressource_t *ressource,
    component_t **begin);

// Clean a scene
void clean_scene(scene_t *scene);

// Destoy a scene
void destroy_scene(scene_t *scene);

        // LAYER

// Create a layer to the scene
void create_layer(scene_t *scene);

// Remove all component of a layer
void clean_layer(layer_t *layer);

// Destroy a layer
void destroy_layer(layer_t *layer);

        // COMPONENT

// Reverse the list of component
void rev_component(component_t **begin);

// Create an component but it's not in a layer (yes the component just exist)
component_t *create_component(sfVector2f *pos, ressource_t *ressource);

// Add an created component to a layer of a scene, according to id
void add_a_component_to_layer(component_t *component, scene_t *scene, int id);

// draw each component of scene
void draw_component_of_scene(sfRenderWindow *window, scene_t *scene);

// destroy a component
void destroy_component(component_t *component);

// Destroy a layer
void destroy_layer(layer_t *layer);

// Destoy a scene
void destroy_scene(scene_t *scene);

// Destroy a struct game
void destroy_game(game_t *game);

// Destroy a tab of scene
void free_tab_scene(game_t *game);

// Destroy a struct window_t
void destroy_window(window_t *window);

// Create a button
button_t *create_button(const button_tab_t *def);

// Display a button
void display_button(sfRenderWindow *win, void *element,
    sfRenderStates *states);

// Destroy a button
void destroy_button(void *element);

// Get the hitbox of a button
sfFloatRect get_button_hitbox(button_tab_t button);

// Check if a buttin is clicked
bool is_button_clicked(const button_tab_t *button, sfVector2i mouse,
    sfEvent *event);

// Add button to a menu
void add_button_to_menu(scene_t *scene, button_tab_t button_def);

#endif /* LIBGRAPHIC_H */
