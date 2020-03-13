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
    if (all.cn.reset_map == 0) {
        all.cn.spd = malloc(sizeof(int) *1000);
        all.cn.line = compt_bal(all.str.line);
        all.tex.tab = malloc(sizeof(sfSprite *) * 10000);
    }
    while (all.cn.reset_map != all.cn.line) {
        all = add_speed(all, all.cn.reset_map);
        if (all.str.line[all.cn.reset_map] == '5') {
            all.tex.tab[all.cn.reset_map] = create_sprite(all.tex.tab[all.cn.reset_map], "files/b5.png");
            all.cn.spd[all.cn.reset_map] = 2;
        }
        set_pos(all.tex.tab[all.cn.reset_map], 340, 675);
        all.cn.reset_map++;
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

all_t wait_sablier(all_t all)
{
    int static mpol = 0;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.sablier)) > 1000) {
        all.cn.sablier.left = mpol;
        if (mpol >= 728) {
            all.cn.sablier_gest = 2;
            all.cn.sablier.left = 0;
            mpol = 0;
            sfClock_restart(all.cl.sablier);
        }
        mpol = mpol + 91;
        sfSprite_setTextureRect(all.tex.sablier, all.cn.sablier);
        sfClock_restart(all.cl.sablier);
    }
    return all;
}
all_t next_wave(all_t all)
{
    static int c = 0;
    set_pos(all.tex.sablier, 1500, 900);
    all = wait_sablier(all);
    if (all.cn.sablier_gest == 2) {
        all.cn.waiting_time--;
        all.cn.sablier_gest = 1;
        set_pos(all.tex.sablier, 10000, 900);
        if (c == 0) {
            all = max_waves(read_fonction("src/create_waves.txt"), all);
            c++;
        }
        all.cn.number_waves++;
        if (all.cn.number_waves != all.cn.max_waves + 1) {
            all.cn.reset_map = 0;
            all.cn.reset_map_v = 0;
            all.cn.max = 1;
            all.cn.money = all.cn.money + 150;
            all.str.line = split_line(read_fonction("src/create_waves.txt"), all.cn.number_waves, all);
        }
    }
    return all;
}
all_t find_path_map2(all_t all)
{
    int i = 0;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.map)) > 1) {
        if (all.cn.line != 1 && all.cn.reset_map_v != all.cn.line - 1) {
            all.pos.ballon = sfSprite_getPosition(all.tex.tab[all.cn.reset_map_v]);
            all = wait(all);
            if (all.cn.waiting == 2) {
                all.cn.waiting = 0;
                all.cn.max++;
                all.cn.reset_map_v++;
            }            
        }
        all = find_path_map2_second_part(all, i);
        sfClock_restart(all.cl.map);
    }
    if (check_end_round(all) == 1)
        all = next_wave(all);
    return (all);
}

all_t init_waves_second(all_t all)
{
    static int i = 0;
    char *map;

    if (i == 0) {
        all = max_waves(read_fonction("src/create_waves.txt"), all);
        map = read_map("src/map2.txt");
        all.str.map1 = str_to_chartab(map);
        i++;
    }
    all = create_sprite_tab2(all);
    return (all);
}
