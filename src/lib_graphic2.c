/*
** EPITECH PROJECT, 2020
** lib_graphic2
** File description:
** m
*/

#include "my.h"

sfRenderWindow *set_win(char *title, int fps, int fullscreen)
{
    sfRenderWindow *window = NULL;
    sfVideoMode mode = {1920, 1080, 32};

    if (fullscreen == 0)
        window = sfRenderWindow_create(mode, title, sfClose, NULL);
    else
        window = sfRenderWindow_create(mode, title, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    return (window);
}
