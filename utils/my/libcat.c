/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** libcat.c
*/

#include <stdlib.h>
#include "libmy.h"

char **libcat(char **tab, char *str)
{
    int size = arraylen(tab);
    char **result = malloc(sizeof(char *) * (size + 2));
    int i = 0;

    if (result == NULL)
        return NULL;
    if (tab != NULL)
        while (tab[i] != NULL) {
            result[i] = my_strdup(tab[i]);
            i++;
        }
    result[i] = my_strdup(str);
    result[i + 1] = NULL;
    return result;
}
