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
    if (all.cn.click > 0 && all.cn.click < 1000)
        all = up1(all, all.cn.click);
    if (all.cn.click > 1000 && all.cn.click < 10000)
        all = up2(all, all.cn.click - 1000);
    if (all.cn.click > 10000 && all.cn.click < 100000)
        all = up3(all, all.cn.click - 10000);
    if (all.cn.click > 100000)
        all = up4(all, all.cn.click - 100000);
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
        if ((pos.x - (pos_b.x + 22)) < range && (pos.y - (pos_b.y + 22)) < range &&
        (pos.x - (pos_b.x + 22)) > -range && (pos.y - (pos_b.y + 22)) > -range) {
            all = create_shoot(all, i, range, tower);
            return (all);
        }
        i++;
    }
    return (all);
}

all_t rotate_tower(all_t all, sfSprite *tower, sfSprite *shoot, sfSprite *ballon)
{
    sfVector2f t = sfSprite_getPosition(tower);
    sfVector2f b = sfSprite_getPosition(ballon);
    sfVector2f or_s = {7, 22};
    sfVector2f res = {0, 0};
    float angle = 0;

    if ((b.x - t.x) >= 0 && (b.y - t.y) <= 0)
        angle = 45;
    if ((b.x - t.x) >= 0 && (b.y - t.y) >= 0)
        angle = 135;
    if ((b.x - t.x) <= 0 && (b.y - t.y) >= 0)
        angle = 225;
    if ((b.x - t.x) <= 0 && (b.y - t.y) <= 0)
        angle = 315;
    sfSprite_setOrigin(shoot, or_s);
    sfSprite_setRotation(tower, angle);
    sfSprite_setRotation(shoot, angle);
    return (all);
}

all_t create_shoot(all_t all, int i, int range, int tower)
{
    sfVector2f pos;

    if (range == 168) {
        if (all.str.nb_dart[tower] == '0' &
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.dart[tower])) > 700) {
            pos = sfSprite_getPosition(all.tex.p1_l0[tower]);
            all.tex.dart[tower] = create_sprite(all.tex.dart[tower], "files/dart.png");
            set_pos(all.tex.dart[tower], pos.x, pos.y);
            all.str.nb_dart[tower] = '1';
            all = rotate_tower(all, all.tex.p1_l0[tower], all.tex.dart[tower], all.tex.tab[i]);
        } else if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.dart[tower])) > 8 &&
        all.str.nb_dart[tower] == '1') {
            range = tower * 1000 + range;
            all = move_shoot(all, i, range, all.tex.dart[tower]);
            sfClock_restart(all.cl.dart[tower]);
        }
    }
    if (range == 169) {
        if (all.str.nb_shuriken[tower] == '0' &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.shuriken[tower])) > 400) {
            pos = sfSprite_getPosition(all.tex.p2_l0[tower]);
            all.tex.shuriken[tower] = create_sprite(all.tex.shuriken[tower], "files/shuriken.png");
            set_pos(all.tex.shuriken[tower], pos.x, pos.y);
            all.str.nb_shuriken[tower] = '1';
            all = rotate_tower(all, all.tex.p2_l0[tower], all.tex.shuriken[tower], all.tex.tab[i]);
        } else if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.shuriken[tower])) > 6 &&
        all.str.nb_shuriken[tower] == '1') {
            range = tower * 1000 + range;
            all = move_shoot(all, i, range, all.tex.shuriken[tower]);
            sfClock_restart(all.cl.shuriken[tower]);
        }
    }
    if (range == 170) {
        if (all.str.nb_fireball[tower] == '0' &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.fireball[tower])) > 600) {
            pos = sfSprite_getPosition(all.tex.p3_l0[tower]);
            all.tex.fireball[tower] = create_sprite(all.tex.fireball[tower], "files/fireball.png");
            set_pos(all.tex.fireball[tower], pos.x, pos.y);
            all.str.nb_fireball[tower] = '1';
            all = rotate_tower(all, all.tex.p3_l0[tower], all.tex.fireball[tower], all.tex.tab[i]);
        } else if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.fireball[tower])) > 9 &&
        all.str.nb_fireball[tower] == '1') {
            range = tower * 1000 + range;
            all = move_shoot(all, i, range, all.tex.fireball[tower]);
            sfClock_restart(all.cl.fireball[tower]);
        }
    }
    if (range == 171) {
        if (all.str.nb_laser[tower] == '0' &&
        sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.laser[tower])) > 200) {
            pos = sfSprite_getPosition(all.tex.p4_l0[tower]);
            all.tex.laser[tower] = create_sprite(all.tex.laser[tower], "files/laser.png");
            set_pos(all.tex.laser[tower], pos.x, pos.y);
            all.str.nb_laser[tower] = '1';
            all = rotate_tower(all, all.tex.p4_l0[tower], all.tex.laser[tower], all.tex.tab[i]);
        } else if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.laser[tower])) > 4 &&
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

all_t up1(all_t all, int i)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.p1_l0[i]);
    sfVector2f origin = {30, 30};

    if (all.cn.lvl1[i] == 1) {
        set_pos(all.tex.up1_1, 1610, 600);
        if (check_click(all.tex.up1_1, 306, 363, all) == 1) {
            all.cn.lvl1[i] = 1.5;
            all.tex.p1_l0[i] = create_sprite(all.tex.p1_l0[i], "files/p1_l1.png");
        }
    }
    if (all.cn.lvl1[i] == 1.5) {
        set_pos(all.tex.up1_2, 1610, 600);
        if (check_click(all.tex.up1_2, 306, 363, all) == 1) {
            all.cn.lvl1[i] = 1.51;
            all.tex.p1_l0[i] = create_sprite(all.tex.p1_l0[i], "files/p1_l2.png");
        }
    }
    set_pos(all.tex.p1_l0[i], pos.x, pos.y);
    sfSprite_setOrigin(all.tex.p1_l0[i], origin);
    return (all);
}

all_t up2(all_t all, int i)
{
    if (all.cn.lvl2[i] == 1.2) {
        set_pos(all.tex.up2_1, 1610, 600);
        if (check_click(all.tex.up2_1, 306, 363, all) == 1) {
            all.cn.lvl2[i] = 1.4;
            all.tex.p2_l0[i] = create_sprite(all.tex.p2_l0[i], "files/p2_l1.png");
        }
    }
    if (all.cn.lvl2[i] == 1.4) {
        set_pos(all.tex.up2_2, 1610, 600);
        if (check_click(all.tex.up2_2, 306, 363, all) == 1) {
            all.cn.lvl2[i] = 1.41;
            all.tex.p2_l0[i] = create_sprite(all.tex.p2_l0[i], "files/p2_l2.png");
        }
    }
    return (all);
}

all_t up3(all_t all, int i)
{
    if (all.cn.lvl3[i] == 1.8) {
        set_pos(all.tex.up3_1, 1610, 600);
        if (check_click(all.tex.up3_1, 306, 363, all) == 1) {
            all.cn.lvl3[i] = 2;
            all.tex.p3_l0[i] = create_sprite(all.tex.p3_l0[i], "files/p3_l1.png");
        }
    }
    if (all.cn.lvl3[i] == 2) {
        set_pos(all.tex.up3_2, 1610, 600);
        if (check_click(all.tex.up3_2, 306, 363, all) == 1) {
            all.cn.lvl3[i] = 2.01;
            all.tex.p3_l0[i] = create_sprite(all.tex.p3_l0[i], "files/p3_l3.png");
        }
    }
    return (all);
}

all_t up4(all_t all, int i)
{
    if (all.cn.lvl4[i] == 2.5) {
        set_pos(all.tex.up4_1, 1610, 600);
        if (check_click(all.tex.up4_1, 306, 363, all) == 1) {
            all.cn.lvl4[i] = 3;
            all.tex.p4_l0[i] = create_sprite(all.tex.p4_l0[i], "files/p4_l1.png");
        }
    }
    return (all);
}

all_t click_tower1(all_t all)
{
    int i = 1;
    sfVector2f pos;
    sfVector2f scale;

    while (i != all.cn.nb_t1) {
        if (check_click_tower(all.tex.p1_l0[i], 30, 30, all) == 1) {
            pos = sfSprite_getPosition(all.tex.p1_l0[i]);
            scale.x = all.cn.lvl1[i];
            scale.y = all.cn.lvl1[i];
            sfSprite_setScale(all.tex.c_green, scale);
            set_pos(all.tex.c_green, pos.x - 167 * scale.x, pos.y - 167 * scale.x);
            set_pos(all.tex.desc1, 1610, 200);
            all.cn.click = i;
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
    sfVector2f scale;

    while (i != all.cn.nb_t2) {
        if (check_click_tower(all.tex.p2_l0[i], 30, 30, all) == 1) {
            pos = sfSprite_getPosition(all.tex.p2_l0[i]);
            scale.x = all.cn.lvl2[i];
            scale.y = all.cn.lvl2[i];
            sfSprite_setScale(all.tex.c_green, scale);
            set_pos(all.tex.c_green, pos.x - 167 * scale.x, pos.y - 167 * scale.x);
            set_pos(all.tex.desc2, 1610, 200);
            all.cn.click = i + 1000;
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
    sfVector2f scale;

    while (i != all.cn.nb_t3) {
        if (check_click_tower(all.tex.p3_l0[i], 30, 30, all) == 1) {
            pos = sfSprite_getPosition(all.tex.p3_l0[i]);
            scale.x = all.cn.lvl3[i];
            scale.y = all.cn.lvl3[i];
            sfSprite_setScale(all.tex.c_green, scale);
            set_pos(all.tex.c_green, pos.x - 167 * scale.x, pos.y - 167 * scale.x);
            set_pos(all.tex.desc3, 1610, 200);
            all.cn.click = i + 10000;
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
    sfVector2f scale;

    while (i != all.cn.nb_t4) {
        if (check_click_tower(all.tex.p4_l0[i], 30, 30, all) == 1) {
            pos = sfSprite_getPosition(all.tex.p4_l0[i]);
            scale.x = all.cn.lvl4[i];
            scale.y = all.cn.lvl4[i];
            sfSprite_setScale(all.tex.c_green, scale);
            set_pos(all.tex.c_green, pos.x - 167 * scale.x, pos.y - 167 * scale.x);
            set_pos(all.tex.desc4, 1610, 200);
            all.cn.click = i + 100000;
        }
        all = check_range(all.tex.p4_l0[i], 171, i, all);
        i++;
    }
    return (all);
}