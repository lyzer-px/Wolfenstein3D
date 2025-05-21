/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** create_window.c
*/

#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "macro.h"
#include "libgraphic.h"

static int create_the_videomode(window_t *window)
{
    window->mode = malloc(sizeof(sfVideoMode));
    if (window->mode == NULL) {
        destroy_window(window);
        return EPI_FAIL;
    }
    *(window->mode) = sfVideoMode_getDesktopMode();
    return EPI_SUCCESS;
}

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
    if (window->window == NULL) {
        free(window);
        return NULL;
    }
    if (create_the_videomode(window) == EPI_FAIL)
        return NULL;
    sfRenderWindow_setFramerateLimit(window->window, window->frame);
    return window;
}
