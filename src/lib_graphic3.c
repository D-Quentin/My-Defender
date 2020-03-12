/*
** EPITECH PROJECT, 2020
** lib_graphic3
** File description:
** m
*/

#include "my.h"

sfSprite *set_scale(sfSprite *sprite, float x, float y)
{
    sfVector2f scale = {x, y};

    sfSprite_setScale(sprite, scale);
    return (sprite);
}