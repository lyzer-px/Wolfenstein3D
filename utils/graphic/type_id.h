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
    #include "macro.h"

enum type_id {
    CIRCLESHAPE = 0,
    CONVEXSHAPE,
    FONT,
    IMAGE,
    RECTANGLESHAPE,
    SPRITE,
    TEXT,
    TEXTURE,
    TRANSFORMABLE,
    VERTEXARRAY,
    VIEW,
    VOID,
};

typedef struct struct_strtype_s {
    char *str;
    int type;
} struct_strtype_t;

static const struct struct_strtype_s str_to_type_tab[] = {
    {CONFIG_CIRCLE, CIRCLESHAPE},
    {CONFIG_FONT, FONT},
    {CONFIG_IMAGE, IMAGE},
    {CONFIG_RECTANGLE, RECTANGLESHAPE},
    {CONFIG_SPRITE, SPRITE},
    {CONFIG_TEXT, TEXT},
    {CONFIG_TEXTURE, TEXTURE},
    {CONFIG_TRANSFORM, TRANSFORMABLE},
    {CONFIG_VERTEXARRAY, VERTEXARRAY},
    {CONFIG_VIEW, VIEW},
    {NULL, -1}
};

typedef struct associative_tab_function_s {
    void *(*creation)(void);
    void *(*creation_fromfile)(char *);
    void (*set_position)(void *, sfVector2f);
    void (*display)(sfRenderWindow *, void *, sfRenderStates *);
    void (*destroy)(void *);
} associative_tab_function_t;

static const struct associative_tab_function_s functions_by_type[] = {
    {(void *(*)(void))sfCircleShape_create,
        NULL,
        (void (*)(void *, sfVector2f))sfCircleShape_setPosition,
        (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawCircleShape,
        (void (*)(void *))sfCircleShape_destroy},

    {(void *(*)(void))sfConvexShape_create,
        NULL,
        (void (*)(void *, sfVector2f))sfConvexShape_setPosition,
        (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawConvexShape,
        (void (*)(void *))sfConvexShape_destroy},

    {NULL,
        (void *(*)(char *))sfFont_createFromFile,
        NULL,
        NULL,
        (void (*)(void *))sfFont_destroy},

    {NULL,
        (void *(*)(char *))sfImage_createFromFile,
        NULL,
        NULL,
        (void (*)(void *))sfImage_destroy},

    {(void *(*)(void))sfRectangleShape_create,
        NULL,
        (void (*)(void *, sfVector2f))sfRectangleShape_setPosition,
        (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawRectangleShape,
        (void (*)(void *))sfRectangleShape_destroy},

    {(void *(*)(void))sfSprite_create,
        NULL,
        (void (*)(void *, sfVector2f))sfSprite_setPosition,
        (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawSprite,
        (void (*)(void *))sfSprite_destroy},

    {(void *(*)(void))sfText_create,
        NULL,
        (void (*)(void *, sfVector2f))sfText_setPosition,
        (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawText,
        (void (*)(void *))sfText_destroy},

    {NULL,
        NULL,
        NULL,
        NULL,
        (void (*)(void *))sfTexture_destroy},

    {(void *(*)(void))sfTransformable_create,
        NULL,
        (void (*)(void *, sfVector2f))sfTransformable_setPosition,
        NULL,
        (void (*)(void *))sfTransformable_destroy},

    {(void *(*)(void))sfVertexArray_create,
        NULL,
        NULL,
        (void (*)(sfRenderWindow *, void *, sfRenderStates *))
        sfRenderWindow_drawVertexArray,
        (void (*)(void *))sfVertexArray_destroy},

    {(void *(*)(void))sfView_create,
        NULL,
        NULL,
        NULL,
        (void (*)(void *))sfView_destroy},

    {NULL,
        NULL,
        NULL,
        NULL,
        NULL}
};

#endif /* TYPE_ID_H */
