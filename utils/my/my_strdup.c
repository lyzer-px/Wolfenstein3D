/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** my_strndup.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "libmy.h"

char *my_strdup(char *s)
{
    int len = my_strlen(s);
    char *dup = malloc(sizeof(char) * (len + 1));

    if (dup == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        dup[i] = s[i];
    dup[len] = '\0';
    return dup;
}
