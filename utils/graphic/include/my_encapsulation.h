/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** my_encapsulation.h
*/

#ifndef MY_ENCAPSULATION_H
    #define MY_ENCAPSULATION_H

    #include <SFML/Graphics.h>

void set_position_circle(void *circle, sfVector2f * position);
void draw_circle(sfRenderWindow *window, void *circle, sfRenderStates *states);
void destroy_circle(void *circle);

void destroy_font(void *font);

void destroy_image(void *image);

void set_position_rectangleshape(void *rectangle, sfVector2f * position);
void draw_rectangleshape(sfRenderWindow *window, void *rectangle,
    sfRenderStates *states);
void destroy_rectangleshape(void *rectangle);

void set_position_sprite(void *sprite, sfVector2f * position);
void draw_sprite(sfRenderWindow *window, void *sprite, sfRenderStates *states);
void destroy_sprite(void *sprite);

void set_position_text(void *text, sfVector2f * position);
void draw_text(sfRenderWindow *window, void *text, sfRenderStates *states);
void destroy_text(void *text);

void destroy_texture(void *texture);

void set_position_transformable(void *obj, sfVector2f * position);
void destroy_transformable(void *obj);

void draw_vertexarray(sfRenderWindow *window,
    void *vertexarray, sfRenderStates *states);
void destroy_vertexarray(void *vertexarray);

void destroy_view(void *view);

#endif /* MY_ENCAPSULATION_H */
