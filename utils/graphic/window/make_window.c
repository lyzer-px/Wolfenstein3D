/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** make_window.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "macro.h"

sfRenderWindow *make_window(sfVector2i dimensions,
    int bits, char *name, sfUint32 style)
{
    sfVideoMode w_mode = (sfVideoMode){dimensions.x, dimensions.y, bits};
    sfVideoMode full_mode = *sfVideoMode_getFullscreenModes(NULL);
    sfRenderWindow *window;

    if (style == STYLE_WIND) {
        window = sfRenderWindow_create(w_mode, name, style, NULL);
    } else {
        window = sfRenderWindow_create(full_mode, name, style, NULL);
    }
    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, FPS);
    return window;
}
