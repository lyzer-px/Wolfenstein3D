/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** arraylen.c
*/

#include <stddef.h>

int arraylen(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return i;
    while (tab[i] != NULL)
        i++;
    return i;
}
