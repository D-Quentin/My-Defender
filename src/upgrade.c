/*
** EPITECH PROJECT, 2020
** upgrade
** File description:
** m
*/

#include "my.h"

all_t up1(all_t all, int i)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.p1_l0[i]);
    sfVector2f origin = {30, 30};

    reset_pos_up(all, 0);
    if (all.cn.lvl1[i] == 1) {
        all = up1_2(all, i);
    }
    if (all.cn.lvl1[i] == 1.5 ) {
        set_pos(all.tex.up1_2, 1610, 600);
        if (check_release(all.tex.up1_2, 306, 363, all) == 1 &&
        all.cn.money >= 150) {
            all.cn.lvl1[i] = 1.510000000000000009;
            all.tex.p1_l0[i] = create_sprite(all.tex.p1_l0[i], "files/1.png");
            all.cn.money -= 150;
            sound_upgrade(all);
        }
    }
    set_pos(all.tex.p1_l0[i], pos.x, pos.y);
    sfSprite_setOrigin(all.tex.p1_l0[i], origin);
    return (all);
}

all_t up1_2(all_t all, int i)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.p1_l0[i]);

    set_pos(all.tex.up1_1, 1610, 600);
    if (check_release(all.tex.up1_1, 306, 363, all) == 1 &&
    all.cn.money >= 100) {
        all.cn.lvl1[i] = 1.5;
        all.tex.p1_l0[i] = create_sprite(all.tex.p1_l0[i], "files/p1_l1.png");
        set_scale(all.tex.c_green, all.cn.lvl1[i], all.cn.lvl1[i]);
        set_pos(all.tex.c_green, pos.x - 252, pos.y - 252);
        all.cn.money -= 100;
        sound_upgrade(all);
    }
    return (all);
}

all_t up2(all_t all, int i)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.p2_l0[i]);
    sfVector2f origin = {30, 30};

    reset_pos_up(all, 0);
    if (all.cn.lvl2[i] == 1.25) {
        all = up2_2(all, i);
    }
    if (all.cn.lvl2[i] == 1.39999997615814209) {
        set_pos(all.tex.up2_2, 1610, 600);
        if (check_release(all.tex.up2_2, 306, 363, all) == 1
        && all.cn.money >= 1000) {
            all.cn.lvl2[i] = 1.40999999999999992;
            all.tex.p2_l0[i] = create_sprite(all.tex.p2_l0[i], "files/2.png");
            all.cn.money -= 1000;
            sound_upgrade(all);
        }
    }
    set_pos(all.tex.p2_l0[i], pos.x, pos.y);
    sfSprite_setOrigin(all.tex.p2_l0[i], origin);
    return (all);
}

all_t up2_2(all_t all, int i)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.p2_l0[i]);

    set_pos(all.tex.up2_1, 1610, 600);
    if (check_release(all.tex.up2_1, 306, 363, all) == 1 &&
    all.cn.money >= 200) {
        all.cn.lvl2[i] = 1.39999997615814209;
        all.tex.p2_l0[i] = create_sprite(all.tex.p2_l0[i], "files/p2_l1.png");
        set_scale(all.tex.c_green, all.cn.lvl2[i], all.cn.lvl2[i]);
        set_pos(all.tex.c_green, pos.x - 235, pos.y - 235);
        all.cn.money -= 200;
        sound_upgrade(all);
    }
    return (all);
}