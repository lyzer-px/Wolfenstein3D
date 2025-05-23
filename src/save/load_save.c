/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** error_handling
*/

#include "macro.h"
#include "libmy.h"
#include "project_funct.h"

size_t load_save(char *filename, game_t *game)
{
    char *content;

    if (wrong_name(filename)) {
        mini_dprintf(STDERR, "Invalid file name\n");
        return EPI_FAIL;
    }
    if (encrypt_file(filename, -CRYPT_KEY) == EPI_FAIL)
        return EPI_FAIL;
    content = file_to_str(filename);
    if (read_content(content, game)) {
        return EPI_FAIL;
    }
    if (encrypt_file(filename, -CRYPT_KEY) == EPI_FAIL)
        return EPI_FAIL;
    return EPI_SUCCESS;
}
