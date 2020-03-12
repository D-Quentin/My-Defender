/*
** EPITECH PROJECT, 2020
** endgame
** File description:
** defender
*/

#include "my.h"

all_t endgame_part(all_t all)
{
    if (check_click(all.tex.exitt, 138, 125, all) == 1 && all.cn.life == 0) {
        all.cn.play = 0;
        sfRenderWindow_close(all.window);
    }
    if (check_click(all.tex.acceuil, 138, 125, all) == 1 && all.cn.life == 0) {
        all.cn.title = 1;
        all.cn.play = 0;
        all.cn.life = 150;
        all.cn.money = 3000;
        all.cn.map = 0;
        all.cn.reset_map = 0;
        all.cn.reset_map_v = 0;
        all.cn.max = 1;
        all.cn.number_waves = 1;
        all.str.line = split_line(read_fonction("src/create_waves.txt"), 0, all);
    }
    if (check_click(all.tex.restart, 138, 125, all) == 1 && all.cn.life == 0) {
        all.cn.life = 150;
        all.cn.money = 3000;
        all.cn.reset_map = 0;
        all.cn.reset_map_v = 0;
        all.cn.number_waves = 1;
        all.str.line = split_line(read_fonction("src/create_waves.txt"), 0, all);
        all.cn.max = 1;
    }
    return (all);
}
