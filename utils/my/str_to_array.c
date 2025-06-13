/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** You must find the largest possible square
** on a board while avoiding obstacles.
*/

#include <unistd.h>
#include <stdlib.h>
#include "macro.h"
#include "libmy.h"
#include "error_str.h"

static char **create_tab(char *str, char *sep)
{
    char **tab;
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (char_in_str(str[i], sep)) {
            count++;
        }
    }
    tab = malloc(sizeof(char *) * (size_t)count);
    tab[count - 1] = NULL;
    return tab;
}

static char **write_tab(char *str, char **tab, char *sep, int len_tab)
{
    int i = 0;

    if (str[0] == '\0') {
        return tab;
    }
    for (; str[i] != '\0'; i++) {
        if (char_in_str(str[i], sep)) {
            str[i] = '\0';
            tab[len_tab] = &str[0];
            str = &str[i + 1];
            return write_tab(str, tab, sep, len_tab + 1);
        }
    }
    tab[len_tab] = NULL;
    return tab;
}

char **str_to_array(char *str, char *sep)
{
    char **tab = create_tab(str, sep);

    if (tab == NULL) {
        print_error(MALLOC_ERR);
        return tab;
    }
    return write_tab(str, tab, sep, 0);
}
