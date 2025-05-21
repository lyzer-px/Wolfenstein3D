/*
** EPITECH PROJECT, 2024
** lib
** File description:
** libmy.h
*/

#ifndef LIBMY_H
    #define LIBMY_H

    #include <stddef.h>

int my_strncmp(char const *s1, char const *s2, int n);

int my_strcmp(char const *s1, char const *s2);

int my_strlen(char const *str);

int arraylen(void **tab);

char *file_to_str(const char *file_name);

char *array_to_str(char *const *array);

size_t write_in_file(char *filename, char *text);

double round_number(double nb, int digits);

int mini_dprintf(int std, const char *format, ...);

#endif /* LIBMY_H */
