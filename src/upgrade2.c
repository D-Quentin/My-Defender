/*
** EPITECH PROJECT, 2020
** upgrade2
** File description:
** m
*/

#include "my.h"

all_t up3(all_t all, int i)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.p3_l0[i]);
    sfVector2f origin = {30, 30};

    reset_pos_up(all, 0);
    if (all.cn.lvl3[i] == 1.75) {
        up3_2(all, i);
    }
    if (all.cn.lvl3[i] == 2) {
        set_pos(all.tex.up3_2, 1610, 600);
        if (check_release(all.tex.up3_2, 306, 363, all) == 1 &&
        all.cn.money >= 500) {
            all.cn.lvl3[i] = 2.009999999999999787;
            all.tex.p3_l0[i] = create_sprite(all.tex.p3_l0[i], "files/3.png");
            all.cn.money -= 500;
            sound_upgrade(all);
        }
    }
    set_pos(all.tex.p3_l0[i], pos.x, pos.y);
    sfSprite_setOrigin(all.tex.p3_l0[i], origin);
    return (all);
}

all_t up3_2(all_t all, int i)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.p3_l0[i]);

    set_pos(all.tex.up3_1, 1610, 600);
    if (check_release(all.tex.up3_1, 306, 363, all) == 1 &&
    all.cn.money >= 250) {
        all.cn.lvl3[i] = 2;
        all.tex.p3_l0[i] = create_sprite(all.tex.p3_l0[i], "files/p3_l1.png");
        set_scale(all.tex.c_green, all.cn.lvl3[i], all.cn.lvl3[i]);
        set_pos(all.tex.c_green, pos.x - 336, pos.y - 336);
        all.cn.money -= 250;
        sound_upgrade(all);
    }
    return (all);
}

all_t up4(all_t all, int i)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.p4_l0[i]);
    sfVector2f origin = {30, 30};

    reset_pos_up(all, 0);
    if (all.cn.lvl4[i] == 2.5) {
        set_pos(all.tex.up4_1, 1610, 600);
        if (check_release(all.tex.up4_1, 306, 363, all) == 1 &&
        all.cn.money >= 3000) {
            all.cn.lvl4[i] = 3;
            all.tex.p4_l0[i] = create_sprite(all.tex.p4_l0[i], "files/4.png");
            set_scale(all.tex.c_green, all.cn.lvl4[i], all.cn.lvl4[i]);
            set_pos(all.tex.c_green, pos.x - 504, pos.y - 504);
            all.cn.money >= 3000;
            sound_upgrade(all);
        }
    }
    set_pos(all.tex.p4_l0[i], pos.x, pos.y);
    sfSprite_setOrigin(all.tex.p4_l0[i], origin);
    return (all);
}