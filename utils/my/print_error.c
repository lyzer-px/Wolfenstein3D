/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** string_error
*/

#include <string.h>
#include <stdio.h>
#include "error_str.h"
#include "macro.h"

static const char *string_error[] = {
    "malloc failed",
    "error opening file",
    "error reading file",
};

void print_error(error_t error)
{
    dprintf(STDERR, "./corewar: %s\n",
            string_error[error]);
}
