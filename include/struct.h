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
    // every information of the window in it
    sfVideoMode *mode;
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
    // id of the scene music
    char *id_music;
    // do we hide the cursor
    bool hide_cursor;
    // a linked list where all the layer are
    struct layer_s *layer;
} scene_t;


// the structure for assets, assets are things to be displayed on window
typedef struct asset_s {
    // logical entity
    sfSprite *sprite;
    // the asset's appearance
    sfTexture *texture;
    // the asset's area
    sfIntRect rect;
    // the assets position
    sfVector2f pos;
} asset_t;

// the player structure, contains everything it needs
typedef struct player_s {
    // player position
    sfVector2f pos;
    // player angle (0, 360)°
    float angle;
    // the player's body
    sfRectangleShape *hitbox;
    // a ray which will be both on minimap (blue) and on screen (white)
    sfRectangleShape *ray;
    // the flashlight
    sfCircleShape *bloom;
    // the shotgun
    asset_t *shotgun;
    //the reticle
    asset_t *reticle;
    // player internal animation clock
    sfClock *clock;
    // states
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
    // true if the music is playing
    bool music_played;
    // true if the audio effect is playing
    bool fxaudio_played;
    // is a percentage (100 the music is at maximum)
    short music_nb;
    // is a percentage (100 the audio effect is at maximum)
    short fxaudio_nb;
} settings_t;

struct game_s {
    // the player
    player_t *player;
    // the mini map
    sfRectangleShape **mini_map;
    // the rectangle which will be used to draw both the rays and the walls
    sfRectangleShape *rect;
    // how many scene do we have (if you  want to change it we have an macro)
    int nb_scene;
    // which scene do we show
    int actual_scene;
    // an array with all scene in it (all texture are create before the loop)
    struct scene_s **tab_scene;
    // stuct which have all information of the setting of the game
    settings_t *settings;
    // stuct window where we have each window's information
    struct window_s *window;
    // tab with all music in it
    music_t *music;
    // id of the actual music
    char *id_music;
    // all ressource
    struct ressource_s *ressource;
};

#endif /* STRUCT_H */
