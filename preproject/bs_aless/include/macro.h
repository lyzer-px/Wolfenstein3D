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

    #include <math.h>

/*
** Always usefull
*/

    #define EPI_FAIL (84)
    #define EPI_SUCESS (0)

/*
** Main
*/

    #define NAME_WIN ("Boostrap Wolf3D")
    #define DIM_X (800)
    #define DIM_Y (600)
    #define FPS (60)
    #define BITS (32)

    #define DISPLAY_CHECK ("DISPLAY=:")

    #define ELAPSED_TIME (1000)

    #define GREY ((sfColor){118, 118, 118, 225})

    #define FOV ( M_PI / 3)
    #define NUM_RAYS 800

/*
** Error Print For User
*/

    #define ER_ENV ("The environment does not allow the window to be opened\n")


#endif /* MACRO_H */
