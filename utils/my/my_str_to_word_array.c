/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** my_str_to_word_array.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "libmy.h"

static int find_word_len(char const *str, char const *separator)
{
    int i = 0;

    while (!is_in(str[i], separator) && str[i])
        i++;
    return i;
}

static int count_str(char *s, char *separator)
{
    int count = 0;

    for (int j = 0; s[j]; j++)
        if (!is_in(s[j], separator)) {
            j += find_word_len(s + j, separator);
            count += 1;
        }
    return count;
}

static char *add_word(char *s, char *separator, int *i)
{
    int size_w = find_word_len(s + *i, separator);
    char *res = my_strndup(s + *i, size_w);

    *i += size_w;
    return res;
}

char **my_str_to_word_array(char *s, char *separator)
{
    int i = 0;
    int nb = 0;
    int count = count_str(s, separator);
    char **tab = malloc((sizeof(char *) * (count + 1)));

    if (tab == NULL)
        return NULL;
    for (int j = 0; s[j] != '\0' || !is_in(s[j], "#\n"); j++)
        if (!is_in(s[j], separator)) {
            tab[nb] = add_word(s, separator, &j);
            nb++;
            i = j;
        }
    if (nb != count)
        tab[nb] = add_word(s, separator, &i);
    tab[nb] = NULL;
    return tab;
}
