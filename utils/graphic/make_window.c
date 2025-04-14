/*
** EPITECH PROJECT, 2024
** Wolf
** File description:
** make_window.c
*/

#include <SFML/Graphics.h>

sfRenderWindow *make_window(sfVector2i dimensions,
    sfVector2i fps_bits, char *name)
{
    sfVideoMode mode = (sfVideoMode){dimensions.x, dimensions.y, fps_bits.y};
    sfRenderWindow *window = sfRenderWindow_create(
        mode, name, sfResize | sfClose, NULL);

    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, fps_bits.x);
    return window;
}
