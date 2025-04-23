/*
** EPITECH PROJECT, 2024
** name
** File description:
** handle_event.c
*/

#include "struct.h"
#include "project_funct.h"
#include "libgraphic.h"

void handle_event(window_t *win, scene_t *scene)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed
            || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed &&
            win->event.key.code == sfKeyF11)
            change_the_mode_window(win);
        if (scene != NULL) {
            scene->function_event(win);
        }
    }
}
