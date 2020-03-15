/*
** EPITECH PROJECT, 2020
** drag2
** File description:
** m
*/

#include "my.h"

all_t set_pos_drag(all_t all, sfVector2i mouse, float scale)
{
    sfVector2f rescale = {scale, scale};

    sfSprite_setScale(all.tex.c_green, rescale);
    sfSprite_setScale(all.tex.c_red, rescale);
    sfClock_restart(all.cl.d);
    set_pos(all.tex.c_green, mouse.x - 167 * scale, mouse.y - 167 * scale);
    set_pos(all.tex.c_red, 2000, 2000);
    if (check_place(all, mouse) != 0) {
        set_pos(all.tex.c_red, mouse.x - 167 * scale, mouse.y - 167 * scale);
        set_pos(all.tex.c_green, 2000, 2000);
    }
    return (all);
}

all_t set_pos_drag_pic(all_t all, sfVector2i mouse, float scale)
{
    sfVector2f rescale = {scale, scale};

    sfSprite_setScale(all.tex.c_green, rescale);
    sfSprite_setScale(all.tex.c_red, rescale);
    sfClock_restart(all.cl.d);
    set_pos(all.tex.c_red, mouse.x - 167 * scale, mouse.y - 167 * scale);
    set_pos(all.tex.c_green, 2000, 2000);
    if (check_place(all, mouse) == 1) {
        set_pos(all.tex.c_green, mouse.x - 167 * scale, mouse.y - 167 * scale);
        set_pos(all.tex.c_red, 2000, 2000);
    }
    return (all);
}

all_t gest_drag(all_t all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all.window);

    all = click_p(all);
    all = drag1(all, mouse);
    all = drag2(all, mouse);
    all = drag3(all, mouse);
    all = drag4(all, mouse);
    all = drag_pic(all, mouse);
    return (all);
}