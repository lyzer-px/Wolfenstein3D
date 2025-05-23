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
    if ((g->tab_scene[g->actual]) != NULL) {
        g->tab_scene[g->actual]->function_event(g);
    }
    while (sfRenderWindow_pollEvent(g->window->window, &(g->window->event))) {
        if (g->window->event.type == sfEvtClosed)
            sfRenderWindow_close(g->window->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            g->actual = PAUSE_MENU;
        if (g->window->event.type == sfEvtKeyPressed &&
                g->window->event.key.code == sfKeyF11)
            change_the_mode_window(g->window);
        if (g->actual >= g->nb_scene || g->actual < 0 ||
            g->tab_scene[g->actual] == NULL)
            g->actual = ERROR_SCENE;
    }
}
