/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** Get a distace between two point
*/

#include <math.h>
#include <SFML/Graphics.h>

float get_distance(sfVector2f *point_a, sfVector2f *point_b)
{
    float dist_x = point_a->x - point_b->x;
    float dist_y = point_a->y - point_b->y;

    return sqrt(dist_x * dist_x + dist_y * dist_y);
}
