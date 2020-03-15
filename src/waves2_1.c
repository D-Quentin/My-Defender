/*
** EPITECH PROJECT, 2020
** fafa
** File description:
** gag
*/

#include "my.h"

all_t wait_sablier(all_t all)
{
    int static mpol = 0;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.sablier)) > 500) {
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

all_t next_wave2(all_t all)
{
    int i = all.cn.number_waves;
    char *str;

    i++;
    if (i != all.cn.max_waves + 1) {
        all.cn.reset_map = 0;
        all.cn.reset_map_v = 0;
        all.cn.max = 1;
        all.cn.money = all.cn.money + 150;
        str = split_line(read_fonction("src/create_waves.txt"), i, all);
    }
    all.str.line = str;
    all.cn.number_waves = i;
    return all;
}

all_t next_wave(all_t all)
{
    static int c = 0;

    set_pos(all.tex.sablier, 1500, 900);
    all = wait_sablier(all);
    if (all.cn.sablier_gest == 2) {
        if (all.cn.waiting_time >= 1) {
            all.cn.waiting_time = all.cn.waiting_time - 4;
        }
        all.cn.sablier_gest = 1;
        set_pos(all.tex.sablier, 10000, 900);
        if (c == 0) {
            all = max_waves(read_fonction("src/create_waves.txt"), all);
            c++;
        }
        all = next_wave2(all);
    }
    return all;
}

all_t find_path_map2(all_t all)
{
    int i = 0, v = all.cn.reset_map_v;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.map)) > 1) {
        if (all.cn.line != 1 && v != all.cn.line - 1) {
            all.pos.ballon = sfSprite_getPosition(all.tex.tab[v]);
            all = wait(all);
            if (all.cn.waiting == 2) {
                all.cn.waiting = 0;
                all.cn.max++;
                v++;
            }
        }
        all.cn.reset_map_v = v;
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