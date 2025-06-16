/*
** EPITECH PROJECT, 2025
** Wolfenstein3D
** File description:
** create_a_ressource_in_the_game.c
*/

#include "struct.h"
#include "macro.h"
#include "libgraphic.h"
#include "type_id.h"

void create_text_error_ressource(game_t *game)
{
    sfText *text_error = sfText_create();
    ressource_t *font = find_a_ressouce_from_id(game->ressource, FONT_HORROR);

    sfText_setColor(text_error, sfWhite);
    sfText_setString(text_error, ERROR_TEXT_404);
    if (font != NULL)
        sfText_setFont(text_error, font->element);
    create_a_ressource_in_the_game(game, TEXT_ERROR, (void *)text_error, TEXT);
    return;
}
