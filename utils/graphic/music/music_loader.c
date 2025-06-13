/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** music_loader.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include "macro.h"
#include "libmy.h"
#include "type_id.h"
#include "libgraphic.h"

static int add_music_from_tab(game_t *game, char **arg)
{
    music_t *new = NULL;

    if (arraylen(arg) != SIZE_LINE_MUSIC)
        return EPI_FAIL;
    new = malloc(sizeof(music_t));
    if (new == NULL)
        return EPI_FAIL;
    new->id = strdup(arg[NAME_MUSIC]);
    new->next = game->music;
    new->music = sfMusic_createFromFile(arg[MUSIC_PATH]);
    if (new->music == NULL) {
        dprintf(STDERR_FILENO,
            "Error: cannot load music :%s\n", arg[NAME_MUSIC]);
        free(new->id);
        free(new);
        return EPI_FAIL;
    }
    game->music = new;
    return EPI_SUCCESS;
}

void load_config_music(game_t *game)
{
    FILE *fd = fopen(PATH_CONIG_MUSIC, READ_FILE);
    size_t size = 0;
    int status = EPI_SUCCESS;
    char *line = NULL;
    char **arg = NULL;

    if (fd == NULL) {
        dprintf(STDERR_FILENO, "Error: No file %s found\n", PATH_CONIG_MUSIC);
        return;
    }
    while (getline(&line, &size, fd) != -1) {
        arg = parse_user_input(line, &status, SEPARATOR_CONFIG_FILE);
        if (status == EPI_SUCCESS)
            status = add_music_from_tab(game, arg);
        if (status != EPI_SUCCESS)
            dprintf(STDERR_FILENO, "Error: Line cannot use \"%s\"\n", line);
        free_tab(arg);
    }
    free(line);
    fclose(fd);
}
