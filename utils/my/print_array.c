/*
** EPITECH PROJECT, 2025
** Cuddle
** File description:
** Print_array
*/

#include <stddef.h>
#include "libmy.h"
#include "macro.h"

void print_array(char **arg)
{
    mini_dprintf(STDOUT, "[");
    for (int i = 0; arg[i] != NULL; i++) {
        mini_dprintf(STDOUT, "\"%s\", ", arg[i]);
    }
    mini_dprintf(STDOUT, "]\n");
}
