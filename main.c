/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** main.c
*/

#include "macro.h"
#include "libmy.h"
#include "project_funct.h"

int main(int argc, char **argv, char **env)
{
    if ((argc == 2 && !my_strcmp("-h", argv[1])) ||
        (argc == 2 && !my_strcmp("-help", argv[1]))) {
        print_help();
        return EPI_SUCCESS;
    }
    if (check_env(env) == EPI_FAIL)
        return EPI_FAIL;
    return wolf3d(argv);
}
