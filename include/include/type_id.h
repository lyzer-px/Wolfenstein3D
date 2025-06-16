/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** type_id.h
*/

#ifndef TYPE_ID_H
    #define TYPE_ID_H

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "macro.h"
    #include "my_encapsulation.h"

enum type_id {
    CIRCLESHAPE = 0,
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
    void (*set_position)(void *, sfVector2f *);
    void (*display)(sfRenderWindow *, void *, sfRenderStates *);
    void (*destroy)(void *);
} associative_tab_function_t;

static const struct associative_tab_function_s functions_by_type[] = {
    {(void *(*)(void))sfCircleShape_create,
        NULL,
        set_position_circle,
        draw_circle,
        destroy_circle},

    {NULL,
        (void *(*)(char *))sfFont_createFromFile,
        NULL,
        NULL,
        destroy_font},

    {NULL,
        (void *(*)(char *))sfImage_createFromFile,
        NULL,
        NULL,
        destroy_image},

    {(void *(*)(void))sfRectangleShape_create,
        NULL,
        set_position_rectangleshape,
        draw_rectangleshape,
        destroy_rectangleshape},

    {(void *(*)(void))sfSprite_create,
        NULL,
        set_position_sprite,
        draw_sprite,
        destroy_sprite},

    {(void *(*)(void))sfText_create,
        NULL,
        set_position_text,
        draw_text,
        destroy_text},

    {NULL,
        NULL,
        NULL,
        NULL,
        destroy_texture},

    {(void *(*)(void))sfTransformable_create,
        NULL,
        set_position_transformable,
        NULL,
        destroy_transformable},

    {(void *(*)(void))sfVertexArray_create,
        NULL,
        NULL,
        draw_vertexarray,
        destroy_vertexarray},

    {(void *(*)(void))sfView_create,
        NULL,
        NULL,
        NULL,
        destroy_view},

    {NULL,
        NULL,
        NULL,
        NULL,
        NULL}
};

#endif /* TYPE_ID_H */
