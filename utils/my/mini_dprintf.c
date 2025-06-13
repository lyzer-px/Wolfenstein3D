/*
** EPITECH PROJECT, 2025
** mini_printf
** File description:
** A function has to print all the characters in the string format
** and print variable when % is used before .
*/

#include <unistd.h>
#include <stdarg.h>
#include "libmy.h"

static int my_putchar(int std, char c)
{
    return write(std, &c, 1);
}

static int my_putnbr(int std, int nb)
{
    if (nb < 0) {
        return my_putchar(std, '-') +
        my_putnbr(std, - nb);
    } else if (nb >= 10) {
        return my_putnbr(std, nb / 10) +
        my_putchar(std, (nb % 10) + 48);
    } else {
        return my_putchar(std, nb + 48);
    }
    return 0;
}

static int my_putstr(int std, char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(std, str[i]);
        i++;
    }
    return i;
}

static int my_put_nbr_hexa(int std, int nb)
{
    char str[] = "0123456789abcdef";
    int i = 0;
    size_t count;

    if (nb < 0)
        return my_putchar(std, '-') + my_put_nbr_hexa(std, -nb);
    if (nb == 0)
        return my_putchar(std, '0');
    while (nb < 0) {
        for (; i < nb && i < 16; i++);
        count += my_putchar(std, str[i]);
        i = 0;
        nb = nb / 16;
    }
    return count;
}

static int my_putfloat(int std, double nb, int digits)
{
    int count_char = 0;
    int i;

    if (nb < 0) {
        return my_putchar(std, '-') + my_putfloat(std, - nb, digits);
    } else {
        count_char = my_putnbr(std, (long)nb);
        nb = nb - (long)nb;
        if (digits == 0) {
            return count_char;
        }
        my_putchar(std, '.');
        for (i = 0; i < digits; i++) {
            nb = nb * 10;
            count_char += my_putnbr(std, (long)nb);
            nb = nb - (long)nb;
        }
        return count_char + 1;
    }
}

static int my_print_flag_f(int std, double nb, int digits)
{
    if (nb > 2147483647) {
        return my_putstr(std, "inf");
    }
    if (nb < -2147483647) {
        return my_putstr(std, "-inf");
    }
    if (nb != nb) {
        return my_putstr(std, "-nan");
    }
    return my_putfloat(std, round_number(nb, digits), digits);
}

static int print_flag(int std, const char flag, va_list list)
{
    switch (flag) {
    case 'i':
    case 'd':
        return my_putnbr(std, va_arg(list, int));
    case 's':
        return my_putstr(std, va_arg(list, char *));
    case 'c':
        return my_putchar(std, va_arg(list, int));
    case '%':
        return my_putchar(std, '%');
    case 'h':
        return my_put_nbr_hexa(std, va_arg(list, int));
    case 'f':
        return my_print_flag_f(std, va_arg(list, int), 6);
    }
    return my_putchar(std, '%');
}

int mini_dprintf(int std, const char *format, ...)
{
    va_list list;
    int nbr = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            nbr += my_putchar(std, format[i]);
        } else {
            nbr += print_flag(std, format[i + 1], list);
            i++;
        }
    }
    va_end(list);
    return nbr;
}
