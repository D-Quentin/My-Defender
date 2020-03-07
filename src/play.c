/*
** EPITECH PROJECT, 2020
** play
** File description:
** m
*/

#include "my.h"

all_t play(all_t all)
{
    while (all.cn.play == 1) {
        if (all.cn.map == 1)
            all = init_waves(all);
        else
            all = init_waves_second(all);
        all = gest_drag(all);
        all = analyse_event(all);
        display_play(all);
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
    return (all);
}

int check_place(all_t all, sfVector2i mouse)
{
    int x = mouse.x;
    int y = mouse.y;
    int i = 0;

    if (x < 325 || x > 1590)
        return (1);
    while (i != all.cn.nb_t) {
        if (x - 30 > all.pos.tower[i].x - 90 &&
            x - 30 < all.pos.tower[i].x + 30 &&
            y - 30 > all.pos.tower[i].y - 90 &&
            y - 30 < all.pos.tower[i].y + 30)
            return (1);
        i++;
    }
    if (all.cn.map == 1 && (x < 520 && y > 810))
        return (1);
    return (0);
}

all_t set_tower1(all_t all, sfVector2i mouse)
{
    int i = all.cn.nb_t1;

    all.tex.p1_l0[i] = create_sprite(all.tex.p1_l0[i], "files/p1_l0.png"); 
    set_pos(all.tex.p1_l0[i], mouse.x - 30, mouse.y - 30);
    set_pos(all.tex.p1_l0[0], 2000, 2000);
    all.pos.tower[all.cn.nb_t] = mouse;
    all.cn.nb_t++;
    all.cn.nb_t1++;
    all.cn.money -= 250;
    return (all);
}

all_t set_tower2(all_t all, sfVector2i mouse)
{
    int i = all.cn.nb_t2;

    all.tex.p2_l0[i] = create_sprite(all.tex.p2_l0[i], "files/p2_l0.png");
    set_pos(all.tex.p2_l0[i], mouse.x - 30, mouse.y - 30);
    set_pos(all.tex.p2_l0[0], 2000, 2000);
    all.pos.tower[all.cn.nb_t] = mouse;
    all.cn.nb_t++;
    all.cn.nb_t2++;
    all.cn.money -= 400;
    return (all);
}

all_t set_tower3(all_t all, sfVector2i mouse)
{
    int i = all.cn.nb_t3;

    all.tex.p3_l0[i] = create_sprite(all.tex.p3_l0[i], "files/p3_l0.png");
    set_pos(all.tex.p3_l0[i], mouse.x - 30, mouse.y - 30);
    set_pos(all.tex.p3_l0[0], 2000, 2000);
    all.pos.tower[all.cn.nb_t] = mouse;
    all.cn.nb_t++;
    all.cn.nb_t3++;
    all.cn.money -= 600;
    return (all);
}

all_t set_tower4(all_t all, sfVector2i mouse)
{
    int i = all.cn.nb_t4;

    all.tex.p4_l0[i] = create_sprite(all.tex.p4_l0[i], "files/p4_l0.png");
    set_pos(all.tex.p4_l0[i], mouse.x - 30, mouse.y - 30);
    set_pos(all.tex.p4_l0[0], 2000, 2000);
    all.pos.tower[all.cn.nb_t] = mouse;
    all.cn.nb_t++;
    all.cn.nb_t4++;
    all.cn.money -= 1500;
    return (all);
}

all_t set_pos_drag(all_t all, sfVector2i mouse)
{
    sfClock_restart(all.cl.d);
    set_pos(all.tex.c_green, mouse.x - 167, mouse.y - 167);
    set_pos(all.tex.c_red, 2000, 2000);
    if (check_place(all, mouse) == 1) {
        set_pos(all.tex.c_red, mouse.x - 167, mouse.y - 167);
        set_pos(all.tex.c_green, 2000, 2000);
    }
    return (all);
}

all_t drag1(all_t all, sfVector2i mouse)
{
    if (all.cn.tower == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
         sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.d)) > 10) {
            set_pos(all.tex.p1_l0[0], mouse.x - 30, mouse.y - 30);
            all = set_pos_drag(all, mouse);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) != sfTrue) {
            if (check_place(all, mouse) != 1)
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
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.d)) > 10) {
            set_pos(all.tex.p2_l0[0], mouse.x - 30, mouse.y - 30);
            all = set_pos_drag(all, mouse);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) != sfTrue) {
            if (check_place(all, mouse) != 1)
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
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.d)) > 10) {
            set_pos(all.tex.p3_l0[0], mouse.x - 30, mouse.y - 30);
            all = set_pos_drag(all, mouse);
            }
        if (sfMouse_isButtonPressed(sfMouseLeft) != sfTrue) {
            if (check_place(all, mouse) != 1)
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
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.d)) > 10) {
            set_pos(all.tex.p4_l0[0], mouse.x - 30, mouse.y - 30);
            all = set_pos_drag(all, mouse);
            }
        if (sfMouse_isButtonPressed(sfMouseLeft) != sfTrue) {
            if (check_place(all, mouse) != 1)
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

all_t click_p(all_t all)
{
    if (check_click(all.tex.p1, 240, 218, all) == 1 &&
        all.cn.money >= 250)
        all.cn.tower = 1;
    if (check_click(all.tex.p2, 240, 218, all) == 1 &&
        all.cn.money >= 400)
        all.cn.tower = 2;
    if (check_click(all.tex.p3, 240, 218, all) == 1 &&
        all.cn.money >= 600)
        all.cn.tower = 3;
    if (check_click(all.tex.p4, 240, 218, all) == 1 &&
        all.cn.money >= 1500)
        all.cn.tower = 4;
    return (all);
}
