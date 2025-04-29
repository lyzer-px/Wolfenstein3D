/*
** EPITECH PROJECT, 2024
** Wolf
** File description:
** libgraphic.h
*/

#ifndef LIBGRAPHIC_H
    #define LIBGRAPHIC_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
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

typedef struct sprite_rect_s {
    sfIntRect rect;
    int offset;
    int max_value;
}sprite_rect_t;

sfRenderWindow *make_window(sfVector2i dimensions,
    int bits, char *name, sfUint32 style);
void make_a_new_style_window(window_t *win);
void draw_rectangle(sfRenderWindow *window, sfVector2f position,
    sfVector2f size);
void draw_circle(sfRenderWindow *wind, sfVector2f center, float radius);
void update_sprite_rect(sfSprite *sprite, sprite_rect_t *sprite_rect,
    sfClock *clock, double nb_seconds);
sfSprite *create_sprite(char *texture_path);
sfText *create_text(sfFont *font, char *string, int size);
sfMusic *create_music(const char *music_path);
sfVector2f *get_movement(sfVector2f *start, sfVector2f *end);
float get_distance(sfVector2f *point_a, sfVector2f *point_b);

#endif /* LIBGRAPHIC_H */
