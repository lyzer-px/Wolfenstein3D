/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** Convert file path to a string
*/

#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>

char *file_to_str(const char *file_name)
{
    int file = open(file_name, O_RDONLY);
    struct stat file_stat;
    char *buffer;

    stat(file_name, &file_stat);
    buffer = malloc(file_stat.st_size + 1);
    if (buffer == NULL) {
        write(2, "Error: malloc failed\n", 22);
        return NULL;
    }
    read(file, buffer, file_stat.st_size);
    buffer[file_stat.st_size] = '\0';
    close(file);
    return buffer;
}
