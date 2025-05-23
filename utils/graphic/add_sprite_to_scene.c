/*
** EPITECH PROJECT, 2024
** Wolf3D
** File description:
** Add a wallpaper
*/

#include <stdlib.h>
#include "libgraphic.h"
#include "macro.h"
#include "type_id.h"

size_t add_sprite_to_scene(sfVector2f *pos, scene_t *scene,
    const char *texture_path, char *id)
{
    ressource_t *ressource;
    component_t *wallpaper;
    sfTexture *texture = sfTexture_createFromFile(texture_path, NULL);
    sfSprite *sprite = create_sprite(texture);

    if (sprite == NULL)
        return EPI_FAIL;
    ressource = create_ressource(id, sprite, SPRITE);
    if (ressource == NULL) {
        free(sprite);
        return EPI_FAIL;
    }
    wallpaper = create_component(pos, ressource);
    if (wallpaper == NULL) {
        free(sprite);
        free(ressource);
        return EPI_FAIL;
    }
    add_a_component_to_layer(wallpaper, scene, 2);
    return EPI_SUCCESS;
}
