/*
** EPITECH PROJECT, 2025
** Fridge
** File description:
** Write in a file
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "macro.h"
#include "error_str.h"
#include "libmy.h"

size_t write_in_file(char *filename, char *text)
{
    mode_t mode = S_IRWXU | S_IRWXG | S_IRWXO;
    int fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, mode);

    if (fd == ERROR) {
        print_error(OPEN_ERR);
        return EPI_FAIL;
    }
    mini_dprintf(fd, text);
    (void)close(fd);
    return EPI_SUCCESS;
}
