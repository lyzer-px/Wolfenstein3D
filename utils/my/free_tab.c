/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** free_tab.c
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab[i]);
    free(tab);
    return;
}
