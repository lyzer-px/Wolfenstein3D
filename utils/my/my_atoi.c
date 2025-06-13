/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** A function that returns a number,
** sent to the function as a string.
*/

#include "macro.h"

int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            sign = -sign;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] != '\0') {
        return ERROR;
    }
    return result * sign;
}
