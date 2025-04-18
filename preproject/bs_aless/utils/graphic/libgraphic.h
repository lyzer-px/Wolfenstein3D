/*
** EPITECH PROJECT, 2024
** Wolf
** File description:
** libgraphic.h
*/

#ifndef LIBGRAPHIC_H
    #define LIBGRAPHIC_H

    #include <SFML/Graphics.h>

sfRenderWindow *make_window(sfVector2i dimensions,
    sfVector2i fps_bits, char *name);

#endif /* LIBGRAPHIC_H */
