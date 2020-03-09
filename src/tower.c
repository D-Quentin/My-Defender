/*
** EPITECH PROJECT, 2020
** tower
** File description:
** m
*/

#include "my.h"

all_t tower(all_t all)
{
    all = click_tower1(all);
    all = click_tower2(all);
    all = click_tower3(all);
    all = click_tower4(all);

    return (all);
}

all_t check_range(sfSprite *sprite, int range, int tower, all_t all)
{
    int i = 0;
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f pos_b;

    pos.x += 30;
    pos.y += 30;
    while (i != all.cn.line) {
        pos_b = sfSprite_getPosition(all.tex.tab[i]);
        if (((pos.x - (pos_b.x + 22)) + (pos.y - (pos_b.y + 22))) < range &&
        ((pos.x - (pos_b.x + 22)) + (pos.y - (pos_b.y + 22))) > -range) {
            all = create_shoot(all, i, range, tower);
            return (all);
        }
        i++;
    }
    return (all);
}

all_t create_shoot(all_t all, int i, int range, int tower)
{
    sfVector2f pos;

    if (range == 168) {
        if (all.str.nb_dart[tower] == '0' &
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.dart[tower])) > 500) {
            pos = sfSprite_getPosition(all.tex.p1_l0[tower]);
            all.tex.dart[tower] = create_sprite(all.tex.dart[tower], "files/dart.png");
            set_pos(all.tex.dart[tower], pos.x, pos.y);
            all.str.nb_dart[tower] = '1';
        } else if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.dart[tower])) > 10 &&
        all.str.nb_dart[tower] == '1') {
            range = tower * 1000 + range;
            all = move_shoot(all, i, range, all.tex.dart[tower]);
            sfClock_restart(all.cl.dart[tower]);
        }
    }
    if (range == 169) {
        if (all.str.nb_shuriken[tower] == '0' &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.shuriken[tower])) > 500) {
            pos = sfSprite_getPosition(all.tex.p2_l0[tower]);
            all.tex.shuriken[tower] = create_sprite(all.tex.shuriken[tower], "files/shuriken.png");
            set_pos(all.tex.shuriken[tower], pos.x, pos.y);
            all.str.nb_shuriken[tower] = '1';
        } else if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.shuriken[tower])) > 10 &&
        all.str.nb_shuriken[tower] == '1') {
            range = tower * 1000 + range;
            all = move_shoot(all, i, range, all.tex.shuriken[tower]);
            sfClock_restart(all.cl.shuriken[tower]);
        }
    }
    if (range == 170) {
        if (all.str.nb_fireball[tower] == '0' &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.fireball[tower])) > 500) {
            pos = sfSprite_getPosition(all.tex.p3_l0[tower]);
            all.tex.fireball[tower] = create_sprite(all.tex.fireball[tower], "files/fireball.png");
            set_pos(all.tex.fireball[tower], pos.x, pos.y);
            all.str.nb_fireball[tower] = '1';
        } else if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.fireball[tower])) > 10 &&
        all.str.nb_fireball[tower] == '1') {
            range = tower * 1000 + range;
            all = move_shoot(all, i, range, all.tex.fireball[tower]);
            sfClock_restart(all.cl.fireball[tower]);
        }
    }
    if (range == 171) {
        if (all.str.nb_laser[tower] == '0' &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.laser[tower])) > 500) {
            pos = sfSprite_getPosition(all.tex.p4_l0[tower]);
            all.tex.laser[tower] = create_sprite(all.tex.laser[tower], "files/laser.png");
            set_pos(all.tex.laser[tower], pos.x, pos.y);
            all.str.nb_laser[tower] = '1';
        } else if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.laser[tower])) > 10 &&
        all.str.nb_laser[tower] == '1') {
            range = tower * 1000 + range;
            all = move_shoot(all, i, range, all.tex.laser[tower]);
            sfClock_restart(all.cl.laser[tower]);
        }
    }

    return (all);
}

all_t move_shoot(all_t all, int i, int range, sfSprite *sprite)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f pos_b = sfSprite_getPosition(all.tex.tab[i]);
    float x = (pos_b.x + 22) - pos.x;
    float y = (pos_b.y + 22) - pos.y;
    float div = 5;
    sfVector2f move = {x / div, y / div};
    int tower = range / 1000;

    if (pos.x >= (pos_b.x + 22) - 30 && pos.x <= (pos_b.x + 22) + 30 && pos.y >= (pos_b.y + 22) - 30 && pos.y <= (pos_b.y + 22) + 30) {
        all = kill_ballon(all, i, range);
        if (range - tower * 1000 == 168)
            all.str.nb_dart[tower] = '0';
        if (range  - tower * 1000 == 169)
            all.str.nb_shuriken[tower] = '0';
        if (range  - tower * 1000 == 170)
            all.str.nb_fireball[tower] = '0';
        if (range  - tower * 1000 == 171)
            all.str.nb_laser[tower] = '0';
        set_pos(sprite, 2000, 2000);
    }
    sfSprite_move(sprite, move);

    return (all);
}

all_t kill_ballon(all_t all, int i , int range)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.tab[i]);

    if (all.str.line[i] == '1') {
        set_pos(all.tex.tab[i], 20, 20);
        all.cn.money += 1;
    }
    if (all.str.line[i] == '2') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b1.png");
        set_pos(all.tex.tab[i], pos.x, pos.y);
        all.cn.money += 2;
        all.str.line[i] = '1';
        all.cn.spd[i] = 1;
    }
    if (all.str.line[i] == '3') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b2.png");
        set_pos(all.tex.tab[i], pos.x, pos.y);
        all.cn.money += 3;
        all.str.line[i] = '2';
        all.cn.spd[i] = 1;
    }
    if (all.str.line[i] == '4') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b3.png");
        set_pos(all.tex.tab[i], pos.x, pos.y);
        all.cn.money += 4;
        all.str.line[i] = '3';
        all.cn.spd[i] = 1;
    }
    if (all.str.line[i] == '5') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b4.png");
        set_pos(all.tex.tab[i], pos.x, pos.y);
        all.cn.money += 5;
        all.str.line[i] = '4';
        all.cn.spd[i] = 3;
    }
    return (all);
}

all_t click_tower1(all_t all)
{
    int i = 1;
    sfVector2f pos;

    while (i != all.cn.nb_t1) {
        if (check_click(all.tex.p1_l0[i], 60, 60, all) == 1) {
            pos = sfSprite_getPosition(all.tex.p1_l0[i]);
            set_pos(all.tex.c_green, pos.x - 137, pos.y - 137);
        }
        all = check_range(all.tex.p1_l0[i], 168, i, all);
        i++;
    }
    return (all);
}

all_t click_tower2(all_t all)
{
    int i = 1;
    sfVector2f pos;

    while (i != all.cn.nb_t2) {
        if (check_click(all.tex.p2_l0[i], 60, 60, all) == 1) {
            pos = sfSprite_getPosition(all.tex.p2_l0[i]);
            set_pos(all.tex.c_green, pos.x - 137, pos.y - 137);
        }
        all = check_range(all.tex.p2_l0[i], 169, i, all);
        i++;
    }
    return (all);
}

all_t click_tower3(all_t all)
{
    int i = 1;
    sfVector2f pos;

    while (i != all.cn.nb_t3) {
        if (check_click(all.tex.p3_l0[i], 60, 60, all) == 1) {
            pos = sfSprite_getPosition(all.tex.p3_l0[i]);
            set_pos(all.tex.c_green, pos.x - 137, pos.y - 137);
        }
        all = check_range(all.tex.p3_l0[i], 170, i, all);
        i++;
    }
    return (all);
}

all_t click_tower4(all_t all)
{
    int i = 1;
    sfVector2f pos;

    while (i != all.cn.nb_t4) {
        if (check_click(all.tex.p4_l0[i], 60, 60, all) == 1) {
            pos = sfSprite_getPosition(all.tex.p4_l0[i]);
            set_pos(all.tex.c_green, pos.x - 137, pos.y - 137);
        }
        all = check_range(all.tex.p4_l0[i], 171, i, all);
        i++;
    }
    return (all);
}