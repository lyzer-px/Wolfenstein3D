/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** make_a_new_style_window.c
*/

#include <SFML/Graphics.h>
#include <string.h>
#include <stdlib.h>
#include "libgraphic.h"
#include "struct.h"
#include "macro.h"

void make_a_new_style_window(window_t *win)
{
    sfRenderWindow *window;
    sfVector2i dimensions = {DIM_X, DIM_Y};
    sfUint32 style = win->full_screen ? STYLE_WIND : STYLE_FULL;

    window = make_window(dimensions, BITS, NAME_WIN, style);
        if (window == NULL)
        return;
    sfRenderWindow_destroy(win->window);
    win->full_screen = !win->full_screen;
    win->window = window;
}
