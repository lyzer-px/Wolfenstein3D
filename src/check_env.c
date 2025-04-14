/*
** EPITECH PROJECT, 2024
** lib_graph
** File description:
** check_env.c
*/

#include <stdio.h>
#include <stddef.h>
#include "macro.h"
#include "libmy.h"

int check_env(char **env)
{
    int len = my_strlen(DISPLAY_CHECK);

    for (int i = 0; env[i] != nullptr; i++)
        if (!my_strncmp(DISPLAY_CHECK, env[i], len))
            return EPI_SUCESS;
    printf(ER_ENV);
    return EPI_FAIL;
}
