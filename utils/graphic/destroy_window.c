/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** destroy_window.c
*/

#include <stdlib.h>
#include "struct.h"

void destroy_window(window_t **window)
{
    sfClock_destroy((*window)->clock);
    sfRenderWindow_destroy((*window)->window);
    free((*window));
}
