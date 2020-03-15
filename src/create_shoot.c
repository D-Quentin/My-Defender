/*
** EPITECH PROJECT, 2020
** create_shoot
** File description:
** m
*/

#include "my.h"

all_t create_shoot1(all_t all, int i, float range, int t)
{
    sfVector2f pos;

    if (range == 168 * all.cn.lvl1[t]) {
        if (all.str.nb_dart[t] == '0' &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.dart[t])) > 600) {
            pos = sfSprite_getPosition(all.tex.p1_l0[t]);
            all.tex.dart[t] = create_sprite(all.tex.dart[t], "files/dart.png");
            set_pos(all.tex.dart[t], pos.x, pos.y);
            all.str.nb_dart[t] = '1';
            rt(all, all.tex.p1_l0[t], all.tex.dart[t], all.tex.tab[i]);
        } else if (all.str.nb_dart[t] == '1' &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.dart[t])) > 8) {
            range = t * 1000 + range;
            all = move_shoot(all, i, range, all.tex.dart[t]);
            sfClock_restart(all.cl.dart[t]);
        }
    }
    return (all);
}

all_t create_shoot2(all_t all, int i, float range, int t)
{
    sfVector2f pos;
    float s = 1;

    if (all.cn.lvl2[t] >= 1.409)
        s = 2.5;
    if (range == 168 * all.cn.lvl2[t]) {
        all = create_shoot2_2(all, i, range, t);
    }
    return (all);
}

all_t create_shoot2_2(all_t all, int i, float range, int t)
{
    float c = 300, s = 6;
    sfVector2f pos;
    char *su = "files/shuriken.png";

    if (all.cn.lvl2[t] >= 1.409)
        s = s / 2.5, c = c / 2.5;
    if (all.str.nb_shuriken[t] == '0' &&
    sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.shuriken[t])) > c) {
        pos = sfSprite_getPosition(all.tex.p2_l0[t]);
        all.tex.shuriken[t] = create_sprite(all.tex.shuriken[t], su);
        set_pos(all.tex.shuriken[t], pos.x, pos.y);
        all.str.nb_shuriken[t] = '1';
        rt(all, all.tex.p2_l0[t], all.tex.shuriken[t], all.tex.tab[i]);
    } else if (all.str.nb_shuriken[t] == '1' &&
    sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.shuriken[t])) > s) {
        range = t * 1000 + range;
        all = move_shoot(all, i, range, all.tex.shuriken[t]);
        sfClock_restart(all.cl.shuriken[t]);
    }
    return (all);
}