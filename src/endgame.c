/*
** EPITECH PROJECT, 2020
** endgame
** File description:
** defender
*/

#include "my.h"

all_t acceuil_button(all_t all)
{
    all.cn.title = 1;
    all.cn.pause = 0;
    all.cn.play = 0;
    all.cn.life = 150;
    all.cn.money = 3000;
    all.cn.map = 0;
    all.cn.reset_map = 0;
    all.cn.reset_map_v = 0;
    all.cn.max = 1;
    all.cn.number_waves = 1;
    all.cn.place_bl = 0;
    all.cn.waiting_time = 80;
    all.cn.reset_best_score = 0;
    all.str.line = split_line(read_fonction("src/create_waves.txt"), 1, all);
    all = destroy_tower(all);
    set_pos(all.tex.cache, 2000, 2000);
    return all;
}

all_t restart_button(all_t all)
{
    all.cn.life = 150;
    all.cn.money = 3000;
    all.cn.reset_map = 0;
    all.cn.reset_map_v = 0;
    all.cn.number_waves = 1;
    all.cn.place_bl = 0;
    all.str.line = split_line(read_fonction("src/create_waves.txt"), 1, all);
    all.cn.max = 1;
    all = destroy_tower(all);
    all.cn.waiting_time = 80;
    all.cn.reset_best_score = 0;
    set_pos(all.tex.cache, 2000, 2000);
    return all;
}

all_t endgame_part(all_t all)
{
    if (check_click(all.tex.exitt, 138, 125, all) == 1 &&
        (all.cn.life == 0 || all.cn.pause == 1)) {
        all.cn.play = 0;
        all.cn.pause = 0;
        sfRenderWindow_close(all.window);
    }
    if (check_click(all.tex.acceuil, 138, 125, all) == 1 &&
        (all.cn.life == 0 || all.cn.pause == 1)) {
        all = acceuil_button(all);
    }
    if (check_click(all.tex.restart, 138, 125, all) == 1 && all.cn.life == 0) {
        all = restart_button(all);
    }
    if (check_click(all.tex.trophe, 138, 125, all) == 1 && all.cn.life == 0)
        aff_highscore(all);
    return (all);
}

all_t destroy_tower2(all_t all)
{
    all.cn.nb_t1 = 1;
    all.cn.nb_t2 = 1;
    all.cn.nb_t3 = 1;
    all.cn.nb_t4 = 1;
    all.cn.nb_t = 0;
    all.cn.nb_pic = 2;
    return all;
}

all_t destroy_tower(all_t all)
{
    int i = 0;
    sfVector2i reset = {2000, 2000};

    while (i != 100) {
        all.str.nb_dart[i] = '0';
        all.str.nb_fireball[i] = '0';
        all.str.nb_shuriken[i] = '0';
        all.str.nb_laser[i] = '0';
        all.pos.tower[all.cn.nb_t] = reset;
        all.cn.lvl1[i] = 0;
        all.cn.lvl2[i] = 0;
        all.cn.lvl3[i] = 0;
        all.cn.lvl4[i] = 0;
        i++;
    }
    all = destroy_tower2(all);
    return (all);
}