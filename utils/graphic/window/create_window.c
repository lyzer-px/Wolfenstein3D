/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** create_window.c
*/

#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "macro.h"
#include "libgraphic.h"

window_t *create_window(void)
{
    window_t *window = malloc(sizeof(window_t));
    sfVector2i dimensions = {DIM_X, DIM_Y};

    if (window == NULL)
        return NULL;
    memset(window, 1, sizeof(window_t));
    window->clock = sfClock_create();
    window->full_screen = false;
    window->frame = FPS;
    window->window = make_window(dimensions, BITS, NAME_WIN, STYLE_WIND);
    window->mode = malloc(sizeof(sfVector2u));
    if (window->mode == NULL || window->window == NULL) {
        destroy_window(window);
        return NULL;
    }
    *(window->mode) = (sfVector2u){DIM_X, DIM_Y};
    sfRenderWindow_setFramerateLimit(window->window, window->frame);
    return window;
}
