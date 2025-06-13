/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** nb_to_str.c
*/

#include <stdlib.h>

char *nb_to_str(int nb)
{
    int index = 0;
    int tmp = nb;
    char *res;

    while (tmp != 0) {
        index += 1;
        tmp /= 10;
    }
    if (index == 0)
        index += 1;
    res = malloc(sizeof(char) * (index + 1));
    if (!res)
        return NULL;
    for (int i = (index - 1); i >= 0; i--) {
        res[i] = (nb % 10) + '0';
        nb /= 10;
    }
    res[index] = '\0';
    return res;
}
