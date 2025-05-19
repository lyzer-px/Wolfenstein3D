/*
** EPITECH PROJECT, 2024
** lib
** File description:
** libmy.h
*/

#ifndef LIBMY_H
    #define LIBMY_H

    #include <stdbool.h>

char *del_last_char(char *str);

bool is_in(char const character, char const *str);

char *my_strndup(char const *s, int len);

char **my_str_to_word_array(char *s, char *separator);

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2);

int my_strsame(char const *s1, char const *s2);

int my_getnbr(char const *str);

char *nb_to_str(int nb);

void free_tab(char **tab);

int arraylen(char **tab);

char **libcat(char **tab, char *str);

char **my_libdup(char **tab);

char **my_str_to_word_array(char *str, char *l);

char **parse_user_input(char *input, int *i, char *separator);

char *my_strdup(char *str);

int my_getnbr(char const *str);

int my_strncmp(char const *s1, char const *s2, int n);

#endif /* LIBMY_H */
