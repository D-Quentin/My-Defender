/*
** EPITECH PROJECT, 2020
** click_tower
** File description:
** m
*/

#include "my.h"

all_t click_tower1(all_t all)
{
    int i = 1;
    sfVector2f pos;
    sfVector2f s;

    while (i != all.cn.nb_t1) {
        if (check_click_tower(all.tex.p1_l0[i], 30, 30, all) == 1) {
            reset_pos_up(all, 1);
            pos = sfSprite_getPosition(all.tex.p1_l0[i]);
            s.x = all.cn.lvl1[i];
            s.y = all.cn.lvl1[i];
            sfSprite_setScale(all.tex.c_green, s);
            set_pos(all.tex.c_green, pos.x - 167 * s.x, pos.y - 167 * s.x);
            set_pos(all.tex.desc1, 1610, 200);
            all.cn.click = i;
        }
        all = check_range(all.tex.p1_l0[i], 168 * all.cn.lvl1[i], i, all);
        i++;
    }
    return (all);
}

all_t click_tower2(all_t all)
{
    int i = 1;
    sfVector2f pos;
    sfVector2f s;

    while (i != all.cn.nb_t2) {
        if (check_click_tower(all.tex.p2_l0[i], 30, 30, all) == 1) {
            reset_pos_up(all, 1);
            pos = sfSprite_getPosition(all.tex.p2_l0[i]);
            s.x = all.cn.lvl2[i];
            s.y = all.cn.lvl2[i];
            sfSprite_setScale(all.tex.c_green, s);
            set_pos(all.tex.c_green, pos.x - 167 * s.x, pos.y - 167 * s.x);
            set_pos(all.tex.desc2, 1610, 200);
            all.cn.click = i + 1000;
        }
        all = check_range(all.tex.p2_l0[i], 168 * all.cn.lvl2[i], i, all);
        i++;
    }
    return (all);
}

all_t click_tower3(all_t all)
{
    int i = 1;
    sfVector2f pos;
    sfVector2f s;

    while (i != all.cn.nb_t3) {
        if (check_click_tower(all.tex.p3_l0[i], 30, 30, all) == 1) {
            reset_pos_up(all, 1);
            pos = sfSprite_getPosition(all.tex.p3_l0[i]);
            s.x = all.cn.lvl3[i];
            s.y = all.cn.lvl3[i];
            sfSprite_setScale(all.tex.c_green, s);
            set_pos(all.tex.c_green, pos.x - 167 * s.x, pos.y - 167 * s.x);
            set_pos(all.tex.desc3, 1610, 200);
            all.cn.click = i + 10000;
        }
        all = check_range(all.tex.p3_l0[i], 168 * all.cn.lvl3[i], i, all);
        i++;
    }
    return (all);
}

all_t click_tower4(all_t all)
{
    int i = 1;
    sfVector2f pos;
    sfVector2f s;

    while (i != all.cn.nb_t4) {
        if (check_click_tower(all.tex.p4_l0[i], 30, 30, all) == 1) {
            reset_pos_up(all, 1);
            pos = sfSprite_getPosition(all.tex.p4_l0[i]);
            s.x = all.cn.lvl4[i];
            s.y = all.cn.lvl4[i];
            sfSprite_setScale(all.tex.c_green, s);
            set_pos(all.tex.c_green, pos.x - 167 * s.x, pos.y - 167 * s.x);
            set_pos(all.tex.desc4, 1610, 200);
            all.cn.click = i + 100000;
        }
        all = check_range(all.tex.p4_l0[i], 168 * all.cn.lvl4[i], i, all);
        i++;
    }
    return (all);
}