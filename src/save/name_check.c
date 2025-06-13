/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** error_handling
*/

#include "macro.h"
#include "libmy.h"

size_t wrong_name(char *name)
{
    int name_len = my_strlen(name);

    if (name_len < 6) {
        return TRUE;
    }
    if (str_is_same(&name[name_len - 5], ".save") == false) {
        return TRUE;
    }
    return FALSE;
}
