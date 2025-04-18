/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** get_pos.c
*/

//#include <SFML/Graphics.h>
//#include <math.h>
//
//sfVector2f get_position(sfVector3f pos, float *angle,
//    sfVector2f translation, int zoom)
//{
//    sfVector2f new_pos;
//    float angle_y = TO_RAD(angle[0]);
//    float angle_x = TO_RAD(angle[1]);
//
//    new_pos.x = (((pos.x * zoom) * cos(angle_y)) - ((pos.y * zoom) *
//        sin(angle_y)) + translation.x);
//    new_pos.y = ((pos.x * zoom) * sin(angle_y) * cos(angle_x)) +
//        ((pos.y * zoom) * cos(angle_y) * cos(angle_x)) - ((pos.z * zoom)
//            * sin(angle_x)) + translation.y - (DIM_Y / 4);
//    return new_pos;
//}

#include <SFML/Graphics.h>

sfVector2f get_position(sfVector3f pos, float *angle,
    sfVector2f translation, int zoom)
{
    return translation;
}
