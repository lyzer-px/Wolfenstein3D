/*
** EPITECH PROJECT, 2024
** name
** File description:
** handle_event.c
*/

#include "struct.h"
#include "project_funct.h"
#include "libgraphic.h"

static bool is_button_clicked(button_tab_t *button,
    sfVector2i mouse, sfEvent *event)
{
    sfFloatRect bounds = get_button_hitbox(*button);

    return sfFloatRect_contains(&bounds, mouse.x, mouse.y) &&
    (event->type == sfEvtMouseButtonPressed &&
    event->mouseButton.button == sfMouseLeft);
}

void handle_event(game_t *g)
{
    while (sfRenderWindow_pollEvent(g->window->window, &(g->window->event))) {
        if (g->window->event.type == sfEvtClosed || (g->actual_scene == 0 &&
            is_button_clicked(&tab_button[2],
            sfMouse_getPositionRenderWindow(g->window->window), &g->window->event)))
            sfRenderWindow_close(g->window->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            g->actual_scene = 0;
        if (g->window->event.type == sfEvtKeyPressed &&
                g->window->event.key.code == sfKeyF11)
            change_the_mode_window(g->window);
        if (g->window->event.type == sfEvtKeyPressed &&
                g->window->event.key.code == sfKeySpace)
            g->actual_scene -= (g->actual_scene - 1) < 0 ? 0 : 1;
        if (g->window->event.type == sfEvtKeyPressed &&
                g->window->event.key.code == sfKeyEnter)
            g->actual_scene += (g->actual_scene + 1) >= g->nb_scene ? 0 : 1;
        if ((g->tab_scene[g->actual_scene]) != NULL) {
            g->tab_scene[g->actual_scene]->function_event(g);
        }
    }
}
