/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** Add a wallpaper
*/

#include <stdlib.h>
#include "libgraphic.h"
#include "macro.h"
#include "type_id.h"

size_t create_ressource_for_sprite(game_t *game,
    const char *texture_path, char *id)
{
    sfTexture *texture = sfTexture_createFromFile(texture_path, NULL);
    sfSprite *sprite = create_sprite(texture);

    if (sprite == NULL)
        return EPI_FAIL;
    create_ressource_link(&(game->ressource), id, sprite, SPRITE);
    return EPI_SUCCESS;
}

size_t add_sprite_to_scene(sfVector2f *pos, scene_t *scene, int id_layer,
    ressource_t *ressource)
{
    component_t *wallpaper;

    wallpaper = create_component(pos, ressource);
    if (wallpaper == NULL) {
        return EPI_FAIL;
    }
    add_a_component_to_layer(wallpaper, scene, id_layer);
    return EPI_SUCCESS;
}
