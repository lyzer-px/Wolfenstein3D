/*
** EPITECH PROJECT, 2024
** Wolf
** File description:
** bs.h
*/

#ifndef BS_H
    #define BS_H

typedef struct {
    float x ;
    float y ;
    float angle ;
} Player ;

    # define TILE_SIZE 64
    # define MAP_WIDTH 8
    # define MAP_HEIGHT 8

extern int map[MAP_HEIGHT][MAP_WIDTH];

#endif /* BS_H */