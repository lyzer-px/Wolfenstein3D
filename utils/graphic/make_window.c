/*
** EPITECH PROJECT, 2024
** Wolf
** File description:
** make_window.c
*/

#include <SFML/Graphics.h>

sfRenderWindow *make_window(sfVector2i dimensions,
    int bits, char *name)
{
    sfVideoMode mode = (sfVideoMode){dimensions.x, dimensions.y, bits};
    sfRenderWindow *window = sfRenderWindow_create(
        mode, name, sfResize | sfClose, NULL);

    if (!window)
        return NULL;
    return window;
}
