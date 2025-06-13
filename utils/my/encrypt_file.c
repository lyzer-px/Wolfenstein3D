/*
** EPITECH PROJECT, 2025
** encrypt_file
** File description:
** encrypt_file
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "macro.h"
#include "libmy.h"

static char get_key_caracter(char car, int key)
{
    char c = '\0';

    while (key < 0)
        key += SIZE_ALPHABET;
    if (car >= 'A' && car <= 'Z') {
        c = ((car - 'A') + key) % SIZE_ALPHABET;
        return c + 'A';
    }
    if (car >= 'a' && car <= 'z') {
        c = ((car - 'a') + key) % SIZE_ALPHABET;
        return c + 'a';
    }
    return car;
}

static char *convert_a_string(const char *str, int key)
{
    static char cipher[BUFSIZ] = {0};

    if (str == NULL)
        return NULL;
    memset(cipher, 0, sizeof(char) * BUFSIZ);
    for (size_t i = 0; str[i] != '\0'; ++i)
        cipher[i] = get_key_caracter(str[i], key);
    return cipher;
}

static size_t write_in_crypt(const char *filename, const char *str)
{
    mode_t mode = S_IRWXU | S_IRWXG | S_IRWXO;
    int fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, mode);

    if (fd == ERROR)
        return EPI_FAIL;
    (void)dprintf(fd, "%s", str);
    (void)close(fd);
    return EPI_SUCCESS;
}

size_t encrypt_file(const char *filename, int key)
{
    char *file_str = NULL;
    char *encrypt_str = NULL;
    size_t error = EXIT_SUCCESS;

    if (filename == NULL)
        return EPI_FAIL;
    file_str = file_to_str(filename);
    if (file_str == NULL)
        return EPI_SUCCESS;
    encrypt_str = convert_a_string(file_str, key);
    error = write_in_crypt(filename, encrypt_str);
    free(file_str);
    return error;
}
