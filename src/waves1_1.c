/*
** EPITECH PROJECT, 2020
** wave
** File description:
** 1
*/

#include "my.h"

all_t add_speed(all_t all, int i)
{
    if (all.str.line[i] == '1') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b1.png");
        all.cn.spd[i] = 1;
    }
    if (all.str.line[i] == '2') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b2.png");
        all.cn.spd[i] = 1;
    }
    if (all.str.line[i] == '3') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b3.png");
        all.cn.spd[i] = 1;
    }
    if (all.str.line[i] == '4') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b4.png");
        all.cn.spd[i] = 3;
    }
    return all;
}

all_t create_sprite_tab(all_t all)
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
        set_pos(all.tex.tab[i], 350, 870);
        i++;
    }
    all.cn.reset_map = i;
    all = find_path_map1(all);
    return all;
}

char *split_line(char *str, int i, all_t all)
{
    char *new_line = malloc(sizeof(char) * my_strlen(str) + 1);
    char **waves_round = str_to_chartab(str);

    new_line = waves_round[i];
    return new_line;
}