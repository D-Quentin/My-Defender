/*
** EPITECH PROJECT, 2020
** tower2
** File description:
** m
*/

#include "my.h"

all_t check_pic(all_t all)
{
    int j = 2, i = 0;
    sfVector2f pos, pos_b;

    while (i != all.cn.line) {
        pos_b = sfSprite_getPosition(all.tex.tab[i]);
        while (j != all.cn.nb_pic) {
            pos = sfSprite_getPosition(all.tex.pic[j]);
            if (pos_b.x - 30 > pos.x - 90 && pos_b.x - 30 < pos.x + 30 &&
                pos_b.y - 30 > pos.y - 90 && pos_b.y - 30 < pos.y + 30) {
                kill_ballon(all, i, 20), all.cn.dura_pic[j]++;
            }
            if (all.cn.dura_pic[j] >= 10)
                set_pos(all.tex.pic[j], 2000, 2000);
            j++;
        }
        j = 2, i++;
    }
    return (all);
}

all_t move_shoot(all_t all, int i, float range, sfSprite *sprite)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f b = sfSprite_getPosition(all.tex.tab[i]);
    float x = (b.x + 22) - pos.x;
    float y = (b.y + 22) - pos.y;
    float div = 5;
    sfVector2f move = {x / div, y / div};
    int tower = range / 1000;

    range = range - tower * 1000;
    if (pos.x >= (b.x + 22) - 30 && pos.x <= (b.x + 22) + 30 &&
        pos.y >= (b.y + 22) - 30 && pos.y <= (b.y + 22) + 30) {
        all = kill_ballon(all, i, range);
        move_shoot2(all, range, tower);
        set_pos(sprite, 2000, 2000);
    }
    sfSprite_move(sprite, move);

    return (all);
}

all_t move_shoot2(all_t all, float r, int tower)
{
    if (r == 168 || r == 168 * 1.5 || r == 253.679931640625)
        all.str.nb_dart[tower] = '0';
    if (r == 168 * 1.25 || r == 235.199951171875 || r == 236.8800048828125)
        all.str.nb_shuriken[tower] = '0';
    if (r == 168 * 1.75 || r == 168 * 2 || r == 337.679931640625)
        all.str.nb_fireball[tower] = '0';
    if (r == 168 * 2.5 || r == 168 * 3)
        all.str.nb_laser[tower] = '0';
    return (all);
}