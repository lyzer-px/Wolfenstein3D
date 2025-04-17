/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** del_tab_button.c
*/


#include <stdlib.h>
#include "libgraphic.h"

void free_tab_button(button_t **tab_button)
{
    for (int i = 0; tab_button[i] != NULL; i++) {
        sfSprite_destroy(tab_button[i]->sprite);
        sfTexture_destroy(tab_button[i]->texture);
        free(tab_button[i]);
    }
    free(tab_button);
    return;
}
