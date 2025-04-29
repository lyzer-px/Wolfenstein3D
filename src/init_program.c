/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_program.c
*/

#include <stdlib.h>
#include "macro.h"
#include "struct.h"
#include "project_funct.h"

int init_program(window_t *win)
{
    int status = EPI_SUCESS;

    if (status == EPI_SUCESS)
        status = loop(win);
    return status;
}
