/*
** EPITECH PROJECT, 2024
** Wolf
** File description:
** main.c
*/

#include <SFML/Graphics.h>

void init_player(Player *player);// Initializes the player 's position and angle

int is_wall(int x, int y);// Returns 1 if the position corresponds to a wall

void draw_floor_and_ceiling(sfRenderWindow *window); // Draws the floor and ceiling of the screen