/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** libmy.h
*/

#ifndef LIBMY_H
    #define LIBMY_H

    #include <stdbool.h>
    #include <stddef.h>

char *del_last_char(char *str);

bool is_in(char const character, char const *str);

char *my_strndup(char const *s, int len);

char **my_str_to_word_array(char const *str, char *delim);

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2);

char *del_last_char(char *str);

bool is_in(char const character, char const *str);

char *my_strndup(char const *s, int len);

char **my_str_to_word_array(char const *str, char *delim);

int my_strsame(char const *s1, char const *s2);

int my_getnbr(char const *str);

char *nb_to_str(int nb);

void free_tab(char **tab);

int arraylen(char **tab);

char **libcat(char **tab, char *str);

char **my_libdup(char **tab);

char *file_to_str(const char *file_name);

char *array_to_str(char *const *array);

size_t write_in_file(char *filename, char *text);

double round_number(double nb, int digits);

int mini_dprintf(int std, const char *format, ...);
char **parse_user_input(char *input, int *i, char *separator);

char *my_strdup(char *str);

int my_getnbr(char const *str);

int my_strncmp(char const *s1, char const *s2, int n);

int str_is_same(const char *str1, const char *str2);

int str_n_is_same(const char *str1, const char *str2, int n);

int my_atoi(const char *str);

void print_array(char **arg);

char **str_to_array(char *str, char *sep);

unsigned int char_in_str(char c, char *str);

size_t encrypt_file(const char *filename, int key);

#endif /* LIBMY_H */
