/*
** EPITECH PROJECT, 2020
** second
** File description:
** wave
*/

#include "my.h"

all_t create_sprite_tab2(all_t all)
{
    int i = all.cn.reset_map;

    if (i == 0) {
        all.cn.spd = malloc(sizeof(int) * 1000);
        all.cn.line = compt_bal(all.str.line);
        all.tex.tab = malloc(sizeof(sfSprite *) * 10000);
    }
    while (i != all.cn.line) {
        all = add_speed(all, i);
        if (all.str.line[i] == '5') {
            all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b5.png");
            all.cn.spd[i] = 2;
        }
        set_pos(all.tex.tab[i], 340, 675);
        i++;
    }
    all.cn.reset_map = i;
    all = find_path_map2(all);
    return all;
}

all_t find_path_map2_second_part2(all_t all, int i)
{
    if (all.str.map1[all.cn.road_y - 1][all.cn.road_x] == 'H') {
        all.pos.up.y = -all.cn.spd[i];
        sfSprite_move(all.tex.tab[i], all.pos.up);
    }
    if (all.str.map1[all.cn.road_y + 1][all.cn.road_x] == 'S') {
        all.pos.down.y = all.cn.spd[i];
        sfSprite_move(all.tex.tab[i], all.pos.down);
    }
    return all;
}

all_t find_path_map2_second_part(all_t all, int i)
{
    while (i != all.cn.max) {
        all.pos.ballon = sfSprite_getPosition(all.tex.tab[i]);
        all.cn.road_x = all.pos.ballon.x / 10;
        all.cn.road_y = (all.pos.ballon.y / 10) - 1;
        all = find_path_map2_second_part2(all, i);
        if (all.str.map1[all.cn.road_y][all.cn.road_x + 1] == 'X') {
            all.pos.right.x = all.cn.spd[i];
            sfSprite_move(all.tex.tab[i], all.pos.right);
        }
        if (all.str.map1[all.cn.road_y][all.cn.road_x - 1] == 'K') {
            all.pos.left.x = -all.cn.spd[i];
            sfSprite_move(all.tex.tab[i], all.pos.left);
        }
        all = gest_life2(all, all.tex.tab[i], i);
        i++;
    }
    return all;
}

int check_end_round(all_t all)
{
    int i = 0;
    int v = 0;
    int w = compt_bal(all.str.line);
    static int c = 0;

    if (all.cn.number_waves == all.cn.max_waves + 1) {
        return 2;
    }
    while (i != all.cn.max) {
        all.pos.ballon = sfSprite_getPosition(all.tex.tab[i]);
        if (all.pos.ballon.x == 20)
            v++;
        i++;
    }
    if (v == w)
        return 1;
    else
        return 2;
}