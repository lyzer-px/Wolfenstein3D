/*
** EPITECH PROJECT, 2024
** lib
** File description:
** project_funct.h
*/

#ifndef PROJECT_H
    #define PROJECT_H

    #include <SFML/Graphics.h>
    #include "struct.h"

int init_program(window_t *win);

void handle_event(window_t *win);

int loop(window_t *win);

int project(void);

void print_help(void);

int check_env(char **env);

#endif /* PROJECT_H */
