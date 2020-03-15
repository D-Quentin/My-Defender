/*
** EPITECH PROJECT, 2020
** init_counter
** File description:
** m
*/

#include "my.h"

all_t init_counter(all_t all)
{
    all.cn.title = 1;
    all.cn.setting = 0;
    all.cn.scoreboard = 0;
    all.cn.window = 1;
    all.cn.fps = 144;
    all.cn.map = 0;
    all.cn.play = 0;
    all.cn.place_bl = 0;
    all.cn.tower = 0;
    all.cn.money = 3000;
    all.cn.nb_t1 = 1;
    all.cn.nb_t2 = 1;
    all.cn.nb_t3 = 1;
    all.cn.nb_t4 = 1;
    all.cn.nb_t = 0;
    all.cn.luffyette.height = 198;
    all = init_counter2(all);
    all = init_counter3(all);
    all = init_counter4(all);
    return (all);
}

all_t init_counter2(all_t all)
{
    all.cn.life = 1;
    all.cn.line = 0;
    all.cn.max = 1;
    all.str.line = split_line(read_fonction("src/create_waves.txt"), 1, all);
    all.cn.s_play[0] = 446;
    all.cn.s_play[1] = 133;
    all.cn.s_play[2] = 730;
    all.cn.s_play[3] = 820;
    all.cn.s_setting[0] = 92;
    all.cn.s_setting[1] = 94;
    all.cn.s_setting[2] = 30;
    all.cn.s_setting[3] = 840;
    all.cn.s_htp[0] = 96;
    all.cn.s_htp[1] = 96;
    all.cn.s_htp[2] = 30;
    all.cn.s_htp[3] = 730;
    all.cn.s_tower[0] = 70;
    all.cn.s_tower[1] = 90;
    return (all);
}

all_t init_counter3(all_t all)
{
    all.cn.s_tower[2] = 30;
    all.cn.s_tower[3] = 620;
    all.cn.s_lboard[0] = 92;
    all.cn.s_lboard[1] = 83;
    all.cn.s_lboard[2] = 30;
    all.cn.s_lboard[3] = 950;
    all.cn.s_exit[0] = 128;
    all.cn.s_exit[1] = 128;
    all.cn.s_exit[2] = 1750;
    all.cn.s_exit[3] = 900;
    all.cn.s_home[0] = 128;
    all.cn.s_home[1] = 128;
    all.cn.s_home[2] = 1750;
    all.cn.s_home[3] = 900;
    all.cn.s_hud1[0] = 465;
    all.cn.s_hud1[1] = 146;
    all.cn.s_hud1[2] = 200;
    all.cn.s_hud1[3] = 300;
    return (all);
}

all_t init_counter4(all_t all)
{
    all.cn.s_hud2[0] = 465;
    all.cn.s_hud2[1] = 146;
    all.cn.s_hud2[2] = 200;
    all.cn.s_hud2[3] = 500;
    all.cn.click = 0;
    all.cn.luffy = 0;
    all.cn.sablier.width = 91;
    all.cn.sablier.height = 730;
    all.cn.reset_map = 0;
    all.cn.reset_map_v = 0;
    all.cn.number_waves = 1;
    all.cn.max_waves = 0;
    all.cn.waiting = 0;
    all.cn.waiting_time = 80;
    all.cn.pause = 0;
    all.cn.nb_pic = 2;
    all.cn.reset_best_score = 0;
    all.cn.luffyette.width = 41;
    return (all);
}