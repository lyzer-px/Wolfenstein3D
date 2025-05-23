/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** parse_user_input.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "libmy.h"

static int is_sep(char c, char *separator)
{
    for (int i = 0; separator[i] != '\0'; i += 1)
        if (c == separator[i])
            return 1;
    return 0;
}

static int format_user_input(char *str, char *separator)
{
    bool bound_check = false;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '\"') {
            bound_check = bound_check == true ? false : true;
            str[i] = ' ';
            continue;
        }
        if (bound_check == true && is_sep(str[i], separator) == 1)
            str[i] -= 127;
    }
    if (bound_check == true)
        return 84;
    return 0;
}

static void reformat_user_input(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i] < 0)
            str[i] += 127;
}

char **parse_user_input(char *input, int *i, char *separator)
{
    char *copy = strdup(input);
    char **tab = NULL;
    int len_copy = my_strlen(copy);

    if (copy[len_copy - 1] == '\n')
        copy[len_copy - 1] = '\0';
    if (copy == NULL || format_user_input(copy, separator) == 84) {
        free(copy);
        *i = 84;
        return NULL;
    }
    tab = my_str_to_word_array(copy, separator);
    if (tab != NULL) {
        for (*i = 0; tab[*i] != NULL; *i += 1)
            reformat_user_input(tab[*i]);
        }
    free(copy);
    *i = 0;
    return tab;
}
