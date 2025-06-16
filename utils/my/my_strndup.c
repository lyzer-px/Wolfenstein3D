/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** my_strndup.c
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strndup(char const *s, int len)
{
    char *dup = malloc(sizeof(char) * (len + 1));

    if (dup == NULL) {
        return NULL;
    }
    for (int i = 0; i < len && s[i] != '\0'; i++) {
        dup[i] = s[i];
    }
    dup[len] = '\0';
    return dup;
}
