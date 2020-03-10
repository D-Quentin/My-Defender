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
        all = tower(all);
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
    if (y < 90 || y > 1040)
        return (1);
    i = -80;
    while (i != 40) {
        if (all.str.map1[(y + i) / 10][(x + i) / 10] != '|')
            return (1);
        i += 10;
    }
    return (0);
}

all_t set_tower1(all_t all, sfVector2i mouse)
{
    int i = all.cn.nb_t1;
    sfVector2f or_t = {30, 30};

    all.tex.p1_l0[i] = create_sprite(all.tex.p1_l0[i], "files/p1_l0.png");
    sfSprite_setOrigin(all.tex.p1_l0[i], or_t);
    set_pos(all.tex.p1_l0[i], mouse.x, mouse.y);
    set_pos(all.tex.p1_l0[0], 2000, 2000);
    all.pos.tower[all.cn.nb_t] = mouse;
    all.cn.lvl1[i] = 1;
    all.cn.nb_t++;
    all.cn.nb_t1++;
    all.cn.money -= 250;
    return (all);
}

all_t set_tower2(all_t all, sfVector2i mouse)
{
    int i = all.cn.nb_t2;
    sfVector2f or_t = {30, 30};

    all.tex.p2_l0[i] = create_sprite(all.tex.p2_l0[i], "files/p2_l0.png");
    sfSprite_setOrigin(all.tex.p2_l0[i], or_t);
    set_pos(all.tex.p2_l0[i], mouse.x, mouse.y);
    set_pos(all.tex.p2_l0[0], 2000, 2000);
    all.pos.tower[all.cn.nb_t] = mouse;
    all.cn.lvl2[i] = 1.2;
    all.cn.nb_t++;
    all.cn.nb_t2++;
    all.cn.money -= 400;
    return (all);
}

all_t set_tower3(all_t all, sfVector2i mouse)
{
    int i = all.cn.nb_t3;
    sfVector2f or_t = {30, 30};

    all.tex.p3_l0[i] = create_sprite(all.tex.p3_l0[i], "files/p3_l0.png");
    sfSprite_setOrigin(all.tex.p3_l0[i], or_t);
    set_pos(all.tex.p3_l0[i], mouse.x, mouse.y);
    set_pos(all.tex.p3_l0[0], 2000, 2000);
    all.pos.tower[all.cn.nb_t] = mouse;
    all.cn.lvl3[i] = 1.8;
    all.cn.nb_t++;
    all.cn.nb_t3++;
    all.cn.money -= 600;
    return (all);
}

all_t set_tower4(all_t all, sfVector2i mouse)
{
    int i = all.cn.nb_t4;
    sfVector2f or_t = {30, 30};

    all.tex.p4_l0[i] = create_sprite(all.tex.p4_l0[i], "files/p4_l0.png");
    sfSprite_setOrigin(all.tex.p4_l0[i], or_t);
    set_pos(all.tex.p4_l0[i], mouse.x, mouse.y);
    set_pos(all.tex.p4_l0[0], 2000, 2000);
    all.pos.tower[all.cn.nb_t] = mouse;
    all.cn.lvl4[i] = 2.5;
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
        all.cn.click = 0;
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
        all.cn.click = 0;
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
        all.cn.click = 0;
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
        all.cn.click = 0;
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
