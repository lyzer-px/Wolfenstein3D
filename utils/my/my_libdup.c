/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** my_libdup.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "libmy.h"

char **my_libdup(char **tab)
{
    int len = arraylen(tab);
    char **result = malloc(sizeof(char *) * (len + 1));

    if (result == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        result[i] = my_strdup(tab[i]);
    result[len] = NULL;
    return result;
}
