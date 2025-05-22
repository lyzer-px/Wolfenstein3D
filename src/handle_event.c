/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** handle_event.c
*/

#include "struct.h"
#include "project_funct.h"
#include "libgraphic.h"
#include "macro.h"

void handle_event(game_t *g)
{
    if ((g->tab_scene[g->actual_scene]) != NULL) {
        g->tab_scene[g->actual_scene]->function_event(g);
    }
    while (sfRenderWindow_pollEvent(g->window->window, &(g->window->event))) {
        if (g->window->event.type == sfEvtClosed)
            sfRenderWindow_close(g->window->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            g->actual_scene = PAUSE_MENU;
        if (g->window->event.type == sfEvtKeyPressed &&
                g->window->event.key.code == sfKeyF11)
            change_the_mode_window(g->window);
        if (g->actual_scene >= g->nb_scene || g->actual_scene < 0 ||
            g->tab_scene[g->actual_scene] == NULL)
            g->actual_scene = ERROR_SCENE;
    }
}
