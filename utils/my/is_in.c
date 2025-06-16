/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** is_in.c
*/

#include <stdbool.h>

bool is_in(char const character, char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == character)
            return true;
    }
    if (character == '\0')
        return true;
    return false;
}
