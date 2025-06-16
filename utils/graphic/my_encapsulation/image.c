/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** image.c
*/

#include <SFML/Graphics.h>

void destroy_image(void *image)
{
    sfImage_destroy((sfImage *)image);
}
