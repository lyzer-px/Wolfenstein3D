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

// Initialise/Load all scene
int init_scene(game_t *game);

// Main Handle Event (we call inside the event's function for each scene)
void handle_event(game_t *g);

// The game loop
int loop(game_t *game);

// Main function, that calls all other function
int project(void);

// Print help for the user
void print_help(void);

// Function that check if we can play or not, according to the env
int check_env(char **env);

/*
** Scene creation
*/

    // Scene Error
// Creation of a scene that look like (Error 404: not found)
void create_error_scene(game_t *game);

void create_backgound_error_ressource(game_t *game);

void create_text_error_ressource(game_t *game);


// Initialise pause menu
void init_pause_menu(scene_t *scene);

#endif /* PROJECT_H */
