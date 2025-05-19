/*
** EPITECH PROJECT, 2024
** name
** File description:
** handle_event.c
*/

#include "struct.h"
#include "project_funct.h"
#include "libgraphic.h"
#include "macro.h"

void handle_event(game_t *g)
{
    while (sfRenderWindow_pollEvent(g->window->window, &(g->window->event))) {
        if (g->window->event.type == sfEvtClosed
                || sfKeyboard_isKeyPressed(sfKeyQ))
            sfRenderWindow_close(g->window->window);
        if (g->window->event.type == sfEvtKeyPressed &&
                g->window->event.key.code == sfKeyF11)
            change_the_mode_window(g->window);
        if (g->actual_scene >= g->nb_scene || g->actual_scene < 0 ||
            g->tab_scene[g->actual_scene] == NULL)
            g->actual_scene = ERROR_SCENE;
        if ((g->tab_scene[g->actual_scene]) != NULL) {
            g->tab_scene[g->actual_scene]->function_event(g);
        }
    }
}
