/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** del_tab_button.c
*/


#include <stdlib.h>
#include "libgraphic.h"

void free_tab_button(button_t **tab_button)
{
    for (int i = 0; tab_button[i] != NULL; i++) {
        sfSprite_destroy(tab_button[i]->sprite[OFF]);
        sfTexture_destroy(tab_button[i]->texture[OFF]);
        free(tab_button[i]);
    }
    free(tab_button);
    return;
}
