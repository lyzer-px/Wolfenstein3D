/*
** EPITECH PROJECT, 2024
** wolf3d
** File description:
** my_strlen.c
*/

#include <stddef.h>

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return i;
    while (str[i] != '\0')
        i++;
    return i;
}
