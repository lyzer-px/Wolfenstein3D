/*
** EPITECH PROJECT, 2025
** Wolf
** File description:
** libgraphic.h
*/

#ifndef LIBGRAPHIC_H
    #define LIBGRAPHIC_H

    #include <SFML/Graphics.h>
    #include "struct.h"

typedef enum {
    OFF,
    HOVER,
    ON,
    NB_STATE
}button_state_t;
typedef struct button_s {
    sfTexture *texture[NB_STATE];
    sfSprite *sprite[NB_STATE];
    sfSprite *current_sprite;
    button_state_t *current_state;
    sfIntRect area;
    sfVector2f *pos;
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
    {"assets/buttons/base/Continue 192x48.png", {0, 0, 192, 48}, {150, 200}},
    {"assets/buttons/base/Save Game 192x48.png", {0, 0, 192, 48}, {150, 300}},
    {"assets/buttons/base/Settings 192x48.png", {0, 0, 192, 48}, {150, 400}},
    {"assets/buttons/base/Exit 192x48.png", {0, 0, 192, 48}, {150, 500}},
    {NULL, {0, 0, 0, 0}, {0, 0}}
};

typedef enum {
    START,
    LOAD_SAVE,
    SETTING_BUTTON_FROM_MENU,
    EXIT_FROM_MENU
}button_start_menu_id_t;

static const button_tab_t button_start_menu[] = {
    {"assets/buttons/base/Start 192x48.png", {0, 0, 192, 48}, {812, 300}},
    {"assets/buttons/base/Save 192x48.png", {0, 0, 192, 48}, {812, 400}},
    {"assets/buttons/base/Settings 192x48.png", {0, 0, 192, 48}, {812, 500}},
    {"assets/buttons/base/Exit 192x48.png", {0, 0, 192, 48}, {812, 600}},
    {NULL, {0, 0, 0, 0}, {0, 0}}
};

static const char wallpaper_start[] = "assets/menu/background_menu.png";
static const char wallpaper_pause[] = "assets/menu/background_menu_pause.jpg";
static const char fire_line[] = "assets/menu/Fire_line.png";

    #define FIRE_LINE_HEIGHT 599
    #define FIRE_LINE_WIDTH 417
    #define FIRE_LINE_SPRITE_HEIGHT 105
typedef struct sprite_rect_s {
    sfIntRect rect;
    int offset;
    int max_value;
}sprite_rect_t;

game_t *init_game(char **argv);

void clean_game(game_t *game);

void free_tab_scene(game_t *game);

void destroy_game(game_t *game);

void load_config_file(game_t *game);

sfRenderWindow *make_window(sfVector2i dimensions,
    int bits, char *name, sfUint32 style);

void change_the_mode_window(window_t *win);

window_t *create_window(void);

void destroy_window(window_t *window);

void load_config_music(game_t *game);

void destroy_a_music(music_t *music);

void destroy_all_music(game_t *game);


int find_type(char *str);

void *create_element(int type, char *filename);

ressource_t *create_ressource(char *id, void *element, int type);

void add_ressource(ressource_t **begin, ressource_t *new_ressource);

void create_ressource_link(ressource_t **begin, char *id,
    void *element, int type);

void create_a_ressource_in_the_game(game_t *game, char *id,
    void *element, int type);

ressource_t *find_a_ressouce_from_id(ressource_t *begin, char *id);

void destroy_ressource(ressource_t **ressource);

void destroy_all_ressource(ressource_t **ressource_begin);

scene_t **init_tab_scene(int nb_scene);

void add_element_to_scene(sfVector2f *pos, ressource_t *ressource,
    component_t **begin);

void change_scene(game_t *game, int new_scene);

void clean_scene(scene_t *scene);

void destroy_scene(scene_t *scene);

void create_layer(scene_t *scene);

void clean_layer(layer_t *layer);

void destroy_layer(layer_t *layer);


void rev_component(component_t **begin);

component_t *create_component(sfVector2f *pos, ressource_t *ressource);

void add_a_component_to_layer(component_t *component, scene_t *scene, int id);

void draw_component_of_scene(sfRenderWindow *window, scene_t *scene);

void destroy_component(component_t *component);

void destroy_layer(layer_t *layer);

void destroy_scene(scene_t *scene);

void destroy_game(game_t *game);

void free_tab_scene(game_t *game);

void destroy_window(window_t *window);

button_t *create_button(const button_tab_t *def);

void display_button(sfRenderWindow *win, void *element,
    sfRenderStates *states);

void destroy_button(void *element);

sfFloatRect get_button_hitbox(button_tab_t button);

bool is_button_clicked(const button_tab_t *button, sfVector2i mouse,
    sfEvent *event);

void add_button_to_menu(scene_t *scene, button_tab_t button_def);

void draw_rectangle(sfRenderWindow *window, sfVector2f position,
    sfVector2f size);

void my_draw_circle(sfRenderWindow *wind, sfVector2f center, float radius);

void update_sprite_rect(sfSprite *sprite, sprite_rect_t *sprite_rect,
    sfClock *clock, double nb_seconds);

sfSprite *create_sprite(sfTexture *texture);

sfText *create_text(sfFont *font, char *string, int size);

sfMusic *create_music(const char *music_path);

sfVector2f *get_movement(sfVector2f *start, sfVector2f *end);

float get_distance(sfVector2f *point_a, sfVector2f *point_b);

size_t add_sprite_to_scene(sfVector2f *pos, scene_t *scene, int id_layer,
    ressource_t *ressource);

size_t create_ressource_for_sprite(game_t *game,
    const char *texture_path, char *id);

#endif /* LIBGRAPHIC_H */
