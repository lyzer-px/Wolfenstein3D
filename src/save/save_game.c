/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** wolf3d.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "macro.h"
#include "struct.h"
#include "libmy.h"
#include "error_str.h"
#include <sys/stat.h>

static void fill_file(int fd, game_t *game)
{
    dprintf(fd, "player\npos:%f,%f\nangle:%f", game->player->pos.x,
        game->player->pos.y, game->player->angle);
    dprintf(fd, "\nsettings\nfxaudio_nb:%i\nfxaudio_played:%i\n",
        game->settings->fxaudio_nb, game->settings->fxaudio_played);
    dprintf(fd, "music_nb:%i\nmusic_played:%i\n",
        game->settings->music_nb, game->settings->music_played);
}

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
    fill_file(fd, game);
    if (encrypt_file(filename, CRYPT_KEY) == EPI_FAIL)
        return EPI_FAIL;
    (void)close(fd);
    return EPI_SUCCESS;
}
