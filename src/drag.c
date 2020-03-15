/*
** EPITECH PROJECT, 2020
** drag
** File description:
** m
*/

#include "my.h"

all_t drag1(all_t all, sfVector2i mouse)
{
    if (all.cn.tower == 1) {
        all.cn.click = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
            sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.d)) > 10) {
            set_pos(all.tex.p1_l0[0], mouse.x - 30, mouse.y - 30);
            all = set_pos_drag(all, mouse, 1);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) != sfTrue) {
            if (check_place(all, mouse) == 0)
                all = set_tower1(all, mouse);
            set_pos(all.tex.p1_l0[0], 2000, 2000);
            all.cn.tower = 0;
            set_pos(all.tex.c_green, 2000, 2000);
            set_pos(all.tex.c_red, 2000, 2000);
        }
    } else
        set_pos(all.tex.p1_l0[0], 2000, 2000);
    return (all);
}

all_t drag2(all_t all, sfVector2i mouse)
{
    if (all.cn.tower == 2) {
        all.cn.click = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.d)) > 10) {
            set_pos(all.tex.p2_l0[0], mouse.x - 30, mouse.y - 30);
            all = set_pos_drag(all, mouse, 1.25);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) != sfTrue) {
            if (check_place(all, mouse) == 0)
                all = set_tower2(all, mouse);
            set_pos(all.tex.p2_l0[0], 2000, 2000);
            all.cn.tower = 0;
            set_pos(all.tex.c_green, 2000, 2000);
            set_pos(all.tex.c_red, 2000, 2000);
        }
    } else
        set_pos(all.tex.p2_l0[0], 2000, 2000);
    return (all);
}

all_t drag3(all_t all, sfVector2i mouse)
{
    if (all.cn.tower == 3) {
        all.cn.click = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.d)) > 10) {
            set_pos(all.tex.p3_l0[0], mouse.x - 30, mouse.y - 30);
            all = set_pos_drag(all, mouse, 1.75);
            }
        if (sfMouse_isButtonPressed(sfMouseLeft) != sfTrue) {
            if (check_place(all, mouse) == 0)
                all = set_tower3(all, mouse);
            set_pos(all.tex.p3_l0[0], 2000, 2000);
            all.cn.tower = 0;
            set_pos(all.tex.c_green, 2000, 2000);
            set_pos(all.tex.c_red, 2000, 2000);
        }
    } else
        set_pos(all.tex.p3_l0[0], 2000, 2000);
    return (all);
}

all_t drag4(all_t all, sfVector2i mouse)
{
    if (all.cn.tower == 4) {
        all.cn.click = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.d)) > 10) {
            set_pos(all.tex.p4_l0[0], mouse.x - 30, mouse.y - 30);
            all = set_pos_drag(all, mouse, 2.5);
            }
        if (sfMouse_isButtonPressed(sfMouseLeft) != sfTrue) {
            if (check_place(all, mouse) == 0)
                all = set_tower4(all, mouse);
            set_pos(all.tex.p4_l0[0], 2000, 2000);
            all.cn.tower = 0;
            set_pos(all.tex.c_green, 2000, 2000);
            set_pos(all.tex.c_red, 2000, 2000);
        }
    } else
        set_pos(all.tex.p4_l0[0], 2000, 2000);
    return (all);
}

all_t drag_pic(all_t all, sfVector2i mouse)
{
    if (all.cn.tower == 5) {
        all.cn.click = 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.d)) > 10) {
            set_pos(all.tex.pic[1], mouse.x - 30, mouse.y - 30);
            all = set_pos_drag_pic(all, mouse, 0.2);
            }
        if (sfMouse_isButtonPressed(sfMouseLeft) != sfTrue) {
            if (check_place(all, mouse) == 1)
                all = set_pic(all, mouse);
            set_pos(all.tex.pic[1], 2000, 2000);
            all.cn.tower = 0;
            set_pos(all.tex.c_green, 2000, 2000);
            set_pos(all.tex.c_red, 2000, 2000);
        }
    } else
        set_pos(all.tex.pic[1], 2000, 2000);
    return (all);
}