/*
** EPITECH PROJECT, 2025
** Wolf3D
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

    for (int i = 0; env[i] != NULL; i++)
        if (!my_strncmp(DISPLAY_CHECK, env[i], len))
            return EPI_SUCCESS;
    printf(ER_ENV);
    return EPI_FAIL;
}
