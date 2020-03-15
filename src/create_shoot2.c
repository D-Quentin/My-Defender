/*
** EPITECH PROJECT, 2020
** create_shoot2
** File description:
** m
*/

#include "my.h"

all_t create_shoot3(all_t all, int i, float range, int t)
{
    sfVector2f pos;

    if (range == 168 * all.cn.lvl3[t]) {
        all = create_shoot3_2(all, i, range, t);
    }
    return (all);
}

all_t create_shoot3_2(all_t all, int i, float range, int t)
{
    char *fi = "files/fireball.png";
    sfVector2f pos;

    if (all.str.nb_fireball[t] == '0' &&
    sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.fireball[t])) > 600) {
        pos = sfSprite_getPosition(all.tex.p3_l0[t]);
        all.tex.fireball[t] = create_sprite(all.tex.fireball[t], fi);
        set_pos(all.tex.fireball[t], pos.x, pos.y);
        all.str.nb_fireball[t] = '1';
        rt(all, all.tex.p3_l0[t], all.tex.fireball[t], all.tex.tab[i]);
    } else if (all.str.nb_fireball[t] == '1' &&
    sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.fireball[t])) > 9) {
        range = t * 1000 + range;
        all = move_shoot(all, i, range, all.tex.fireball[t]);
        sfClock_restart(all.cl.fireball[t]);
    }
    return (all);
}

all_t create_shoot4(all_t all, int i, float range, int t)
{
    sfVector2f pos;
    float s = 1;

    if (all.cn.lvl4[t] == 3)
        s = 2;
    if (range == 168 * all.cn.lvl4[t]) {
        all = create_shoot4_2(all, i, range, t);
    }
    return (all);
}

all_t create_shoot4_2(all_t all, int i, float range, int t)
{
    float c = 200, s = 4;
    sfVector2f pos;

    if (all.cn.lvl2[t] >= 1.409)
        s = s / 2, c = c / 2;
    if (all.str.nb_laser[t] == '0' &&
    sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.laser[t])) > c) {
        pos = sfSprite_getPosition(all.tex.p4_l0[t]);
        all.tex.laser[t] = create_sprite(all.tex.laser[t], "files/laser.png");
        set_pos(all.tex.laser[t], pos.x, pos.y);
        all.str.nb_laser[t] = '1';
        rt(all, all.tex.p4_l0[t], all.tex.laser[t], all.tex.tab[i]);
    } else if (all.str.nb_laser[t] == '1' &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.laser[t])) > s) {
        range = t * 1000 + range;
        all = move_shoot(all, i, range, all.tex.laser[t]);
        sfClock_restart(all.cl.laser[t]);
    }
}