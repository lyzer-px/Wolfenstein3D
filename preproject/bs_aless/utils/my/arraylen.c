/*
** EPITECH PROJECT, 2024
** wolf3d
** File description:
** arraylen.c
*/

#include <stddef.h>

int arraylen(void **tab)
{
    int i = 0;

    if (tab == NULL)
        return i;
    while (tab[i] != NULL)
        i++;
    return i;
}
