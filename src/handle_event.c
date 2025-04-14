/*
** EPITECH PROJECT, 2024
** name
** File description:
** handle_event.c
*/

#include "struct.h"
#include "project_funct.h"

void handle_event(window_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed
            || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
    }
}
