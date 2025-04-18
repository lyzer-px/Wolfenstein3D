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
int loop(window_t *win, int **map);
int project(void);
void print_help(void);
int check_env(char **env);

/*
** BOOTSTRAP
*/

void init_player(Player_t *player);
int is_wall(int x, int y, int **map);
void draw_floor_and_ceiling(sfRenderWindow *window);

float cast_single_ray(Player_t player, float ray_angle,
    sfRenderWindow *window);
void cast_all_rays(sfRenderWindow *window, Player_t player);

#endif /* PROJECT_H */
