/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** my_strcmp.c
*/

#include "libmy.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    return 0;
}

int my_strsame(char const *s1, char const *s2)
{
    int l1 = my_strlen(s1);
    int l2 = my_strlen(s2);

    if (l1 == 0 && l2 == 0)
        return 0;
    if (l1 < l2)
        return 0 - s2[l1];
    if (l1 > l2)
        return 0 - s1[l2];
    for (int i = 0; s1[i] && s2[i]; i++)
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    return 0;
}
