/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** error_handling
*/

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include "macro.h"

int str_is_same(const char *str1, const char *str2)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL) {
        return FALSE;
    }
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return FALSE;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0') ? TRUE : FALSE;
}

int str_n_is_same(const char *str1, const char *str2, int n)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL) {
        return FALSE;
    }
    while (i < n && str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return FALSE;
        }
        i++;
    }
    return (i == n || (str1[i] == '\0' && str2[i] == '\0')) ? TRUE : FALSE;
}
