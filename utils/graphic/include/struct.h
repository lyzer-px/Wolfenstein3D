/*
** EPITECH PROJECT, 2024
** lib
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>

typedef struct window_s {
    bool full_screen : 1;
    int frame;
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent event;
    sfVector2u *mode;
} window_t;

typedef struct ressource_s {
    char *id;
    void *element;
    void (*setposition)(void *, sfVector2f *);
    void (*display)(sfRenderWindow *, void *, sfRenderStates *);
    void (*destroy)(void *);
    struct ressource_s *next;
} ressource_t;

typedef struct component_s {
    ressource_t *ressource;
    sfVector2f *pos;
    struct component_s *next;
} component_t;

typedef struct layer_s {
    int id;
    struct component_s *component;
    struct layer_s *next;
    bool view : 1;
} layer_t;

typedef struct game_s game_t;

typedef struct scene_s {
    int id_scene;
    bool pause : 1;
    void (*function_event)(struct game_s *);
    void (*set_positions)(struct game_s *);
    char *id_music;
    bool hide_cursor;
    struct layer_s *layer;
} scene_t;

typedef struct asset_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
} asset_t;

typedef struct player_s {
    sfVector2f pos;
    float angle;
    sfRectangleShape *hitbox;
    sfRectangleShape *ray;
    sfCircleShape *bloom;
    asset_t *hud;
    asset_t *shotgun;
    asset_t *impact;
    asset_t *reticle;
    sfClock *clock;
    bool flashlight_on;
    bool firing;
    bool running;
} player_t;

typedef struct music_s {
    char *id;
    sfMusic *music;
    struct music_s *next;
} music_t;

typedef struct settings_s {
    int music_played;
    int fxaudio_played;
    short music_nb;
    short fxaudio_nb;
} settings_t;

struct game_s {
    player_t *player;
    sfRectangleShape **mini_map;
    sfRectangleShape *rect;
    int nb_scene;
    int actual;
    struct scene_s **tab_scene;
    settings_t *settings;
    struct window_s *window;
    music_t *music;
    char *id_music;
    struct ressource_s *ressource;
};

#endif /* STRUCT_H */
