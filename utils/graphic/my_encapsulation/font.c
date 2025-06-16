/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** font.c
*/

#include <SFML/Graphics.h>

void destroy_font(void *font)
{
    sfFont_destroy((sfFont *)font);
}
