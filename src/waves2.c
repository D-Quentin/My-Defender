/*
** EPITECH PROJECT, 2020
** second
** File description:
** wave
*/

#include "my.h"

all_t find_path_map2(all_t all);

all_t create_sprite_tab2(all_t all)
{
    static int i = 0;

    if (i == 0) {
        all.cn.spd = malloc(sizeof(int) *1000);
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
    all = find_path_map2(all);
    return all;
}

all_t find_path_map2_second_part(all_t all, int i)
{
    while (i != all.cn.max) {
        all.pos.ballon = sfSprite_getPosition(all.tex.tab[i]);
        all.cn.road_x = all.pos.ballon.x / 10;
        all.cn.road_y = (all.pos.ballon.y / 10) - 1;
        if (all.str.map1[all.cn.road_y - 1][all.cn.road_x] == 'H') {
            all.pos.up.y = -all.cn.spd[i];
            sfSprite_move(all.tex.tab[i], all.pos.up);
        }
        if (all.str.map1[all.cn.road_y + 1][all.cn.road_x] == 'S') {
            all.pos.down.y = all.cn.spd[i];
            sfSprite_move(all.tex.tab[i], all.pos.down);
        }
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
all_t find_path_map2(all_t all)
{
    static int v = 0;
    int i = 0;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.map)) > 1) {
        if (all.cn.line != 1 && v != all.cn.line - 1) {
            all.pos.ballon = sfSprite_getPosition(all.tex.tab[v]);
            if (all.pos.ballon.x > 390) {
                all.cn.max++;
                v++;
            }
        }
        all = find_path_map2_second_part(all, i);
        sfClock_restart(all.cl.map);
    }
    return (all);
}

all_t init_waves_second(all_t all)
{
    static int i = 0;
    char *map;

    if (i == 0) {
        map = read_map("src/map2.txt");
        all.str.map1 = str_to_chartab(map);
        i++;
    }
    all = create_sprite_tab2(all);
    return (all);
}
