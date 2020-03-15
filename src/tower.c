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
    all = check_pic(all);
    return (all);
}

all_t check_range(sfSprite *sprite, float r, int tower, all_t all)
{
    int i = 0;
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f pos_b;

    pos.x += 30;
    pos.y += 30;
    while (i != all.cn.line) {
        pos_b = sfSprite_getPosition(all.tex.tab[i]);
        if ((pos.x - (pos_b.x + 52)) < r && (pos.y - (pos_b.y + 52)) < r &&
        (pos.x - (pos_b.x + 52)) > -r && (pos.y - (pos_b.y + 52)) > -r) {
            all = create_shoot1(all, i, r, tower);
            all = create_shoot2(all, i, r, tower);
            all = create_shoot3(all, i, r, tower);
            all = create_shoot4(all, i, r, tower);
            return (all);
        }
        i++;
    }
    return (all);
}

void rt(all_t all, sfSprite *tower, sfSprite *shoot, sfSprite *bl)
{
    sfVector2f t = sfSprite_getPosition(tower);
    sfVector2f b = sfSprite_getPosition(bl);
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
}

void reset_pos_up(all_t all, int i)
{
    set_pos(all.tex.up1_1, 2000, 2000);
    set_pos(all.tex.up1_2, 2000, 2000);
    set_pos(all.tex.up2_1, 2000, 2000);
    set_pos(all.tex.up2_2, 2000, 2000);
    set_pos(all.tex.up3_1, 2000, 2000);
    set_pos(all.tex.up3_2, 2000, 2000);
    set_pos(all.tex.up4_1, 2000, 2000);
    if (i == 1) {
        set_pos(all.tex.desc1, 2000, 2000);
        set_pos(all.tex.desc2, 2000, 2000);
        set_pos(all.tex.desc3, 2000, 2000);
        set_pos(all.tex.desc4, 2000, 2000);
    }
}