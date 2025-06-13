/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** error_str
*/

#ifndef ERROR_STR_
    #define ERROR_STR_

typedef enum {
    MALLOC_ERR,
    OPEN_ERR,
    READ_ERR,
} error_t;

void print_error(error_t error);

#endif
