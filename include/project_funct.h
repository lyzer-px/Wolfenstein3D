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
int wolf3d(void);

// Print help for the user
void print_help(void);

// Function that check if we can play or not, according to the env
int check_env(char **env);

/*
** Scene creation
*/
void create_game_scene(game_t *game);

    // Scene Error
// Creation of a scene that look like (Error 404: not found)
void create_error_scene(game_t *game);

void create_backgound_error_ressource(game_t *game);

void create_text_error_ressource(game_t *game);

// Initialise pause menu
void init_pause_menu(scene_t *scene);

// Initialise start menu
void init_start_menu(scene_t *scene);

// Save the game status
int save_game(char *filename, game_t *game);

size_t wrong_name(char *name);

size_t read_content(char *file, game_t *game);

size_t load_save(char *filename, game_t *game);

#endif /* PROJECT_H */
