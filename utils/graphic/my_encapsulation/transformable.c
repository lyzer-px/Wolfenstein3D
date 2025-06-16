/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** transformable.c
*/

#include <SFML/Graphics.h>

void set_position_transformable(void *obj, sfVector2f *position)
{
    sfTransformable_setPosition((sfTransformable *)obj, *position);
}

void destroy_transformable(void *obj)
{
    sfTransformable_destroy((sfTransformable *)obj);
}
