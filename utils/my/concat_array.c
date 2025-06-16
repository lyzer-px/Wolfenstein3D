/*
** EPITECH PROJECT, 2025
** concat_array
** File description:
** concat array
*/

#include <string.h>
#include <stdlib.h>
#include <stddef.h>

static int my_array_len(char *const *array)
{
    int len = 0;

    for (size_t i = 0; array[i] != NULL; i++) {
        len += strlen(array[i]) + 1;
    }
    return len;
}

char *array_to_str(char *const *array)
{
    int len = my_array_len(array);
    char *str = malloc(sizeof(char) * len);
    int count = 0;

    if (str == NULL)
        return NULL;
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            str[count] = array[i][j];
            count++;
        }
        str[count] = ' ';
        count++;
    }
    str[count - 1] = '\0';
    return str;
}
