/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** splits a string into words with non alpha chars as separators
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libmy.h"

static int is_alpha(char a, char *delim)
{
    if (is_in(a, delim) && a != '\0' && a != '\n' && a != '\t')
        return false;
    return true;
}

static int char_count(char const *str, char *delim)
{
    int i = 0;

    while (is_alpha(str[i], delim))
        i++;
    return i;
}

static int word_count(char const *str, char *delim)
{
    int words = 0;

    for (int i = 0; i < my_strlen(str); i++)
        if (is_alpha(str[i], delim)) {
            i += char_count(&str[i], delim);
            words++;
        }
    return words;
}

static char *get_word(char const *src, char *delim)
{
    char *dest;
    int i = 0;
    int char_counter = char_count(src, delim);

    dest = malloc(sizeof(char) * (char_counter + 1));
    while (i < char_counter) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

static const char *next(int i, char const *str, char **end_array, char *delim)
{
    for (int j = 0; str[j]; j++)
        if (is_alpha(str[j], delim)) {
            end_array[i] = get_word(&str[j], delim);
            str = str + j + char_count(&str[j], delim);
            return str;
        }
    return str;
}

char **my_str_to_word_array(char const *str, char *delim)
{
    int i = 0;
    int array_height = word_count(str, delim);
    char **end_array = malloc(sizeof(char *) * (array_height + 1));

    while (i < array_height) {
        str = next(i, str, end_array, delim);
        i++;
    }
    end_array[i] = NULL;
    return end_array;
}
