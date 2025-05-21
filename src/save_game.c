/*
** EPITECH PROJECT, 2024
** wolf3d
** File description:
** wolf3d.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "macro.h"
#include "struct.h"
#include "libmy.h"
#include "error_str.h"

int save_game(char *filename, game_t *game)
{
    mode_t mode = S_IRWXU | S_IRWXG | S_IRWXO;
    int fd;

    if (game == NULL)
        return ERROR;
    if (filename == NULL)
        filename = "1.save";
    fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, mode);
    if (fd == ERROR) {
        print_error(OPEN_ERR);
        return ERROR;
    }
    mini_dprintf(fd, "player:\npos:%f,%f\nangle:%f", game->player->pos.x,
        game->player->pos.y, game->player->angle);
    (void)close(fd);
    return EPI_SUCCESS;
}
