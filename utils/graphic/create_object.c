/*
** EPITECH PROJECT, 2024
** my_hunter -> create_object
** File description:
** Create object for my_hunter
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

sfSprite *create_sprite(char *texture_path)
{
    sfTexture* texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(texture_path, NULL);
    if (!texture)
        return NULL;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfText *create_text(sfFont *font, char *string, int size)
{
    sfText *text = sfText_create();

    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    return text;
}

sfMusic *create_music(const char *music_path)
{
    sfMusic *music;

    music = sfMusic_createFromFile(music_path);
    if (!music)
        return NULL;
    sfMusic_play(music);
    return music;
}
