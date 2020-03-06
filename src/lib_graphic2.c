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
        window = sfRenderWindow_create(mode, title, sfClose | sfResize, NULL);
    else
        window = sfRenderWindow_create(mode, title, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    return (window);
}

int check_on(sfSprite *sprite, int x, int y, all_t all)
{
    if (sfMouse_getPositionRenderWindow(all.window).x >= \
        sfSprite_getPosition(sprite).x && \
        sfMouse_getPositionRenderWindow(all.window).x <= \
        sfSprite_getPosition(sprite).x + x && \
        sfMouse_getPositionRenderWindow(all.window).y >= \
        sfSprite_getPosition(sprite).y && \
        sfMouse_getPositionRenderWindow(all.window).y <= \
        sfSprite_getPosition(sprite).y + y) {
            return (1);
    }
    return (0);
}

all_t scale_tex(sfSprite *sprite, int *size, all_t all)
{
    sfVector2f pos_s = sfSprite_getPosition(sprite);
    int sx = 0, sy = 0;

    if (check_on(sprite, size[0], size[1], all) == 1 && sfSprite_getScale(sprite).x == 1) {
        sx += ((1.1 * size[0]) - size[0]) / 2, sy += ((1.1 * size[1]) - size[1]) / 2;
        set_pos(sprite, pos_s.x - sx, pos_s.y - sy);
        sfSprite_setScale(sprite, all.pos.scale);
    }
    if (check_on(sprite, size[0], size[1], all) != 1) {
        set_pos(sprite, size[2], size[3]);
        sfSprite_setScale(sprite, all.pos.rescale);
    }
    return (all);
}

int check_release(sfSprite *sprite, int x, int y, all_t all)
{
    static int i = 0;
    sfIntRect rect = {0, 0, x * 1.1, y * 1.1};
    sfVector2f pos;

    if (check_click(sprite, x, y, all) == 1) {
        i = y;
        pos = sfSprite_getPosition(sprite);
        sfSprite_setTextureRect(all.tex.cache, rect);
        set_pos(all.tex.cache, pos.x, pos.y);
    }
    if (i == y && sfMouse_isButtonPressed(sfMouseLeft) != sfTrue) {
        i = 0;
        set_pos(all.tex.cache, 2000, 2000);
        return (1);
    }
    return (0);
}