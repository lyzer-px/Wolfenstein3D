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

    #define NB_SCENE (1)

/*
** Main
*/

    #define NAME_WIN ("Wolf3d")
    #define DIM_X (1920 / 2)
    #define DIM_Y (1080 / 2)
    #define FPS (60)
    #define BITS (32)
    #define STYLE_WIND ((sfUint32)sfResize | sfClose)
    #define STYLE_FULL ((sfUint32) sfClose | sfFullscreen)

    #define DISPLAY_CHECK ("DISPLAY=:")

    #define ELAPSED_TIME (1000)

/*
** Libs
*/

    #define END_STR ('\0')

/*
** Error Print For User
*/

    #define ER_ENV ("The environment does not allow the window to be opened\n")

#endif /* MACRO_H */
