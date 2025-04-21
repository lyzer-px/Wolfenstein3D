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

sfRenderWindow *make_window(sfVector2i dimensions,
    int bits, char *name, sfUint32 style);
void make_a_new_style_window(window_t *win);

#endif /* LIBGRAPHIC_H */
