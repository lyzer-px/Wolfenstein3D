/*
** EPITECH PROJECT, 2024
** wolf3d
** File description:
** init_program.c
*/

#include <stdlib.h>
#include "macro.h"
#include "struct.h"
#include "project_funct.h"

static composant_t *set_composant(composant_t *begin)
{
    sfRectangleShape *square = sfRectangleShape_create();
    composant_t *compo = malloc(sizeof(composant_t));

    if (compo == NULL)
        return NULL;
    sfRectangleShape_setSize(square, (sfVector2f){50, 50});
    sfRectangleShape_setFillColor(square, sfCyan);
    sfRectangleShape_setPosition(square, (sfVector2f){30, 50});
    sfRectangleShape_setOutlineColor(square, sfGreen);
    sfRectangleShape_setOutlineThickness(square, 10);
    compo->element = square;
    compo->function_display = (void (*)(sfRenderWindow *, void *,
        sfRenderStates *))sfRenderWindow_drawRectangleShape;
    compo->function_destroy = (void (*)(void *))sfRectangleShape_destroy;
    compo->next = begin;
    return compo;
}

static scene_t *init_menu(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return NULL;
    scene->begin = NULL;
    scene->begin = set_composant(scene->begin);
    return scene;
}

int init_scene(game_t *game)
{
    int status = 0;

    game->tab_scene[0] = init_menu();
    if (status == EPI_SUCESS)
        status = loop(game);
    return status;
}
