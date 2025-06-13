/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** Return a vector which represents a step in a direction.
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>

sfVector2f *get_movement(sfVector2f *start, sfVector2f *end)
{
    sfVector2f *movement = malloc(sizeof(sfVector2f));
    float vector_x = (end->x - start->x);
    float vector_y = (end->y - start->y);
    float length = sqrt(vector_x * vector_x + vector_y * vector_y);

    if (movement == NULL)
        return NULL;
    if (length == 0) {
        movement->x = 0;
        movement->y = 0;
        return movement;
    }
    movement->x = vector_x / length;
    movement->y = vector_y / length;
    return movement;
}
