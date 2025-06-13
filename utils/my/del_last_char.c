/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** del_last_char.c
*/

#include <stdlib.h>
#include "libmy.h"

char *del_last_char(char *str)
{
    char *res = my_strdup(str);
    int len = 0;

    if (res == NULL)
        return NULL;
    len = my_strlen(res);
    res[len - 1] = '\0';
    return res;
}
