/*
** EPITECH PROJECT, 2020
** set_tower
** File description:
** m
*/

#include "my.h"

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
    all.cn.nb_t += 1;
    all.cn.nb_t1 += 1;
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
    all.cn.lvl2[i] = 1.25;
    all.cn.nb_t += 1;
    all.cn.nb_t2 += 1;
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
    all.cn.lvl3[i] = 1.75;
    all.cn.nb_t += 1;
    all.cn.nb_t3 += 1;
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
    all.cn.lvl4[i] = 2.50;
    all.cn.nb_t += 1;
    all.cn.nb_t4 += 1;
    all.cn.money -= 1500;
    return (all);
}

all_t set_pic(all_t all, sfVector2i mouse)
{
    int i = all.cn.nb_pic;

    all.tex.pic[i] = create_sprite(all.tex.pic[i], "files/pic.png");
    set_pos(all.tex.pic[i], mouse.x - 30, mouse.y - 30);
    set_pos(all.tex.pic[1], 2000, 2000);
    all.pos.pic[all.cn.nb_pic] = mouse;
    all.cn.nb_pic++;
    all.cn.dura_pic[i] = 0;
    all.cn.money -= 100;
    return (all);
}