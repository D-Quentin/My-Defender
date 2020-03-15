/*
** EPITECH PROJECT, 2020
** play
** File description:
** m
*/

#include "my.h"

all_t play(all_t all)
{
    while (all.cn.play == 1) {
        if (all.cn.map == 1)
            all = init_waves(all);
        else
            all = init_waves_second(all);
        all = check_best_score(all);
        all = gest_drag(all);
        all = analyse_event(all);
        all = tower(all);
        all = endgame_part(all);
        all = game_pause(all);
        display_play(all);
    }
    return (all);
}

int check_place(all_t all, sfVector2i mouse)
{
    int x = mouse.x;
    int y = mouse.y;
    int i = 0;

    if (x < 325 || x > 1590)
        return (2);
    while (i != all.cn.nb_t) {
        if (x - 30 > all.pos.tower[i].x - 90 &&
            x - 30 < all.pos.tower[i].x + 30 &&
            y - 30 > all.pos.tower[i].y - 90 &&
            y - 30 < all.pos.tower[i].y + 30)
            return (2);
        i++;
    }
    return (check_place2(all, mouse));
}

int check_place2(all_t all, sfVector2i mouse)
{
    int x = mouse.x;
    int y = mouse.y;
    int i = -80;

    if (y < 90 || y > 1040)
        return (1);
    while (i != 40) {
        if (all.str.map1[(y + i) / 10][(x + i) / 10] != '|')
            return (1);
        i += 10;
    }
    return (0);
}

all_t click_p(all_t all)
{
    if (check_click(all.tex.p1, 240, 218, all) == 1 &&
        all.cn.money >= 250)
        all.cn.tower = 1;
    if (check_click(all.tex.p2, 240, 218, all) == 1 &&
        all.cn.money >= 400)
        all.cn.tower = 2;
    if (check_click(all.tex.p3, 240, 218, all) == 1 &&
        all.cn.money >= 600)
        all.cn.tower = 3;
    if (check_click(all.tex.p4, 240, 218, all) == 1 &&
        all.cn.money >= 1500)
        all.cn.tower = 4;
    if (check_click(all.tex.pic[0], 67, 51, all) == 1 &&
        all.cn.money >= 100)
        all.cn.tower = 5;
    return (all);
}