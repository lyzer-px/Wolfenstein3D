/*
** EPITECH PROJECT, 2024
** lib
** File description:
** macro.h
*/

#ifndef MACRO_H
    #define MACRO_H

/*
** INCLUDE
*/

    #include <SFML/Graphics.h>

/*
** Always usefull
*/

    #define EPI_FAIL (84)
    #define EPI_SUCESS (0)

/*
** Main
*/

// Window information

    #define NAME_WIN ("Wolf3d")
    #define DIM_X (1920 / 2)
    #define DIM_Y (1080 / 2)
    #define FPS (60)
    #define BITS (32)

    #define STYLE_WIND ((sfUint32)sfResize | sfClose)
    #define STYLE_FULL ((sfUint32)sfResize | sfClose | sfFullscreen)

    #define ELAPSED_TIME (1000)

// Scene information

    // WARNING - When you want to add an scene you need to make a +1 in the
    // include/macro.h and utils/graphic/macro.h
    #define NB_SCENE (3)

/*
** Libs
*/

// Env information

    #define DISPLAY_CHECK ("DISPLAY=:")

// Text information

    #define END_STR ('\0')

// Configuration file

    #define PATH_FILE_CONIG ("assets/loader.config")
    #define SEPARATOR_CONFIG_FILE ("; \n\t")
    // each line need to be format like that:
    //TYPE; "NAME"; "FILE_PATH";
enum FORMAT_FILE_INDEX {
    TYPE = 0,
    NAME,
    FILE_PATH,
    SIZE_LINE
};

    #define READ_FILE ("r")

    #define CONFIG_CIRCLE ("CIRCLE")
    #define CONFIG_CONVEX ("CONVEX")
    #define CONFIG_FONT ("FONT")
    #define CONFIG_IMAGE ("IMAGE")
    #define CONFIG_RECTANGLE ("RECTANGLE")
    #define CONFIG_SPRITE ("SPRITE")
    #define CONFIG_TEXT ("TEXT")
    #define CONFIG_TEXTURE ("TEXTURE")
    #define CONFIG_TRANSFORM ("TRANSFORM")
    #define CONFIG_VERTEXARRAY ("VERTEXARRAY")
    #define CONFIG_VIEW ("VIEW")

enum TYPE_INSTRUCTION {
    ID = 0,
    PATH_TEXTURE,
    NB_ARG_CONFIG,
};

/*
** Error Print For User
*/

    #define ER_ENV ("The environment does not allow the window to be opened\n")

#endif /* MACRO_H */
