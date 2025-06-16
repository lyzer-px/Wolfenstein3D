/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** my_getnbr.c
*/

#include <unistd.h>

static int is_digit_or_symb(int value)
{
    if (value >= 48 && value <= 57) {
        return value - 48;
    }
    if (value == 43) {
        return 10;
    }
    if (value == 45) {
        return 11;
    }
    return 12;
}

static int calculating(int result, char c)
{
    if (is_digit_or_symb(c) == 11) {
            result = ((-1) * result);
        }
    if (is_digit_or_symb(c) < 10) {
        result = (result * 10) + is_digit_or_symb(c);
    }
    return result;
}

int my_getnbr(char const *str)
{
    int result = 0;
    int index = 0;

    while (is_digit_or_symb(str[index]) < 12) {
        if (((result * 10 + str[index] < result) && result > 0)
            || ((result * 10 + str[index]) > result && result < 0)) {
            write(2, "Invalid Error", 13);
            return -1;
        }
        result = calculating(result, str[index]);
        index = index + 1;
    }
    return result;
}
