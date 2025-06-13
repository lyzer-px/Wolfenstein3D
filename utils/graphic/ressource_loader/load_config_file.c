/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** load_config_file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "struct.h"
#include "macro.h"
#include "libmy.h"
#include "type_id.h"
#include "libgraphic.h"

static int add_ressource_from_tab(game_t *game, char **arg)
{
    int type;
    ressource_t *ressource = NULL;
    void *element = NULL;

    if (arraylen(arg) != SIZE_LINE)
        return EPI_FAIL;
    type = find_type(arg[TYPE]);
    if (type == EPI_FAIL)
        return EPI_FAIL;
    element = create_element(type, arg[FILE_PATH]);
    if (element == NULL) {
        dprintf(STDERR_FILENO, "Error: cannot create %s\n", arg[NAME]);
        return EPI_FAIL;
    }
    ressource = create_ressource(arg[NAME], element, type);
    add_ressource(&(game->ressource), ressource);
    return EPI_SUCCESS;
}

void load_config_file(game_t *game)
{
    FILE *fd = fopen(PATH_FILE_CONIG, READ_FILE);
    size_t size = 0;
    int status = EPI_SUCCESS;
    char *line = NULL;
    char **arg = NULL;

    if (fd == NULL) {
        dprintf(STDERR_FILENO, "Error: No file %s found\n", PATH_FILE_CONIG);
        return;
    }
    while (getline(&line, &size, fd) != -1) {
        arg = parse_user_input(line, &status, SEPARATOR_CONFIG_FILE);
        if (status == EPI_SUCCESS)
            status = add_ressource_from_tab(game, arg);
        if (status != EPI_SUCCESS)
            dprintf(STDERR_FILENO, "Error: Line is wrong \"%s\"\n", line);
        free_tab(arg);
    }
    free(line);
    fclose(fd);
}
