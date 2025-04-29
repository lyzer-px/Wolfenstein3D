/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** handle_event.c
*/

#include "struct.h"
#include "project_funct.h"
#include "libgraphic.h"

void handle_event(window_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed
            || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtKeyPressed &&
                win->event.key.code == sfKeyF11)
            make_a_new_style_window(win);
    }
}
