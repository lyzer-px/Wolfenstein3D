/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** error_handling
*/

#include <stdlib.h>
#include "struct.h"
#include "macro.h"
#include "libmy.h"

static size_t read_player(char **content, player_t *player)
{
    if ((str_is_same(content[0], "player") && str_is_same(content[1], "pos")
        && str_is_same(content[4], "angle")) == FALSE)
        return EPI_FAIL;
    player->pos.x = atof(content[2]);
    player->pos.y = atof(content[3]);
    player->angle = atof(content[5]);
    if (player->pos.x == ERROR || player->pos.x == ERROR ||
        player->angle == ERROR)
        return EPI_FAIL;
    return EPI_SUCCESS;
}

static size_t read_settings(char **content, settings_t *settings)
{
    if ((str_is_same(content[6], "settings") &&
        str_is_same(content[7], "fxaudio_nb") &&
        str_is_same(content[9], "fxaudio_played") &&
        str_is_same(content[11], "music_nb") &&
        str_is_same(content[13], "music_played")) == FALSE)
        return EPI_FAIL;
    settings->fxaudio_nb = my_atoi(content[8]);
    settings->fxaudio_played = my_atoi(content[10]);
    settings->music_nb = my_atoi(content[12]);
    settings->music_played = my_atoi(content[14]);
    if (settings->fxaudio_nb == ERROR || settings->fxaudio_played == ERROR ||
        settings->music_nb == ERROR || settings->music_played == ERROR)
        return EPI_FAIL;
    return EPI_SUCCESS;
}

static size_t read_line(char *file, game_t *game)
{
    char **content = str_to_array(file, "\n:,");
    int nb_line;

    if (content == NULL)
        return EPI_FAIL;
    nb_line = arraylen(content);
    if (nb_line != 15) {
        mini_dprintf(STDERR, "Invalid content\n");
        return EPI_FAIL;
    }
    if (read_player(content, game->player) == EPI_FAIL) {
        return EPI_FAIL;
    }
    if (read_settings(content, game->settings)) {
        return EPI_FAIL;
    }
    return EPI_SUCCESS;
}

size_t read_content(char *file, game_t *game)
{
    if (file == NULL) {
        mini_dprintf(STDERR, "Cannot open file\n");
        return EPI_FAIL;
    }
    if (file[0] == '\0') {
        mini_dprintf(STDERR, "File is empty\n");
        return EPI_FAIL;
    }
    if (read_line(file, game)) {
        return EPI_FAIL;
    }
    return EPI_SUCCESS;
}
