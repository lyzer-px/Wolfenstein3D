/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** vertexarrayc
*/

#include <SFML/Graphics.h>

void draw_vertexarray(sfRenderWindow *window,
    void *vertexarray, sfRenderStates *states)
{
    sfRenderWindow_drawVertexArray(window,
        (sfVertexArray *)vertexarray, states);
}

void destroy_vertexarray(void *vertexarray)
{
    sfVertexArray_destroy((sfVertexArray *)vertexarray);
}
