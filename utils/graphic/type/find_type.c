/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** find_type.c
*/

#include <stddef.h>
#include "type_id.h"
#include "macro.h"
#include "libmy.h"

int find_type(char *str)
{
    for (size_t i = 0; str_to_type_tab[i].str != NULL; i++)
        if (my_strcmp(str_to_type_tab[i].str, str) == 0)
            return str_to_type_tab[i].type;
    return EPI_FAIL;
}
