/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** my_strlen.c
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return i;
    while (str[i] != '\0')
        i++;
    return i;
}
