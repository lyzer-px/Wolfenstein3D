/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** char_in_str.c
*/

#include "macro.h"

unsigned int char_in_str(char c, char *str)
{
    for (unsigned int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return TRUE;
        }
    }
    return FALSE;
}
