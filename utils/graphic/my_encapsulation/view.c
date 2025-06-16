/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** view.c
*/

#include <SFML/Graphics.h>

void destroy_view(void *view)
{
    sfView_destroy((sfView *)view);
}
