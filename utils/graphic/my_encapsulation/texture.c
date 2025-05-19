/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** texture.c
*/

#include <SFML/Graphics.h>

void destroy_texture(void *texture)
{
    sfTexture_destroy((sfTexture *)texture);
}
