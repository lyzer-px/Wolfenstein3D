/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** type_id.h
*/

#ifndef TYPE_ID_H
    #define TYPE_ID_H

    #include <stdbool.h>
    #include <SFML/Graphics.h>

enum type_id {
    CIRCLESHAPE = 0,
    CONVEXSHAPE,
    FONT,
    IMAGE,
    SHADER,
    RECTANGLESHAPE,
    RENDERTEXTURE,
    SHAPE,
    SPRITE,
    TEXT,
    TEXTURE,
    TRANSFORMABLE,
    VERTEXARRAY,
    VERTEXBUFFER,
    VIEW,
    VOID,
};

struct associative_tab_function_s
{
    void (*setposition)(void *, sfVector2f);
    void (*display)(sfRenderWindow *, void *, sfRenderStates *);
    void (*destroy)(void *);
} associative_tab_function_t;

static const struct associative_tab_function_s functions_by_type[] = {
    {(void (*)(void *, sfVector2f))sfCircleShape_setPosition,
    (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawCircleShape,
    (void (*)(void *))sfCircleShape_destroy},

    {(void (*)(void *, sfVector2f))sfConvexShape_setPosition,
    (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawConvexShape,
    (void (*)(void *))sfConvexShape_destroy},

    {NULL,
    NULL,
    (void (*)(void *))sfFont_destroy},

    {NULL,
    NULL,
    (void (*)(void *))sfImage_destroy},

    {NULL,
    NULL,
    (void (*)(void *))sfShader_destroy},

    {(void (*)(void *, sfVector2f))sfRectangleShape_setPosition,
    (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawRectangleShape,
    (void (*)(void *))sfRectangleShape_destroy},

    {NULL,
    NULL,
    (void (*)(void *))sfRenderTexture_destroy},

    {(void (*)(void *, sfVector2f))sfShape_setPosition,
    (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawShape,
    (void (*)(void *))sfShape_destroy},

    {(void (*)(void *, sfVector2f))sfSprite_setPosition,
    (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawSprite,
    (void (*)(void *))sfSprite_destroy},

    {(void (*)(void *, sfVector2f))sfText_setPosition,
    (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawText,
    (void (*)(void *))sfText_destroy},

    {NULL,
    NULL,
    (void (*)(void *))sfTexture_destroy},

    {(void (*)(void *, sfVector2f))sfTransformable_setPosition,
    NULL,
    (void (*)(void *))sfTransformable_destroy},

    {NULL,
    (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawVertexArray,
    (void (*)(void *))sfVertexArray_destroy},

    {NULL,
    (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawVertexBuffer,
    (void (*)(void *))sfVertexBuffer_destroy},

    {NULL,
    NULL,
    (void (*)(void *))sfView_destroy},

    {NULL,
    NULL,
    NULL}
};

#endif /* TYPE_ID_H */