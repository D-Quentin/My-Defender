/*
** EPITECH PROJECT, 2020
** endgame
** File description:
** defender
*/

#include "my.h"

all_t endgame_part(all_t all)
{
    if (check_click(all.tex.exitt, 138, 125, all) == 1 && (all.cn.life == 0 || all.cn.pause == 1)) {
        all.cn.play = 0;
        all.cn.pause = 0;
        sfRenderWindow_close(all.window);
    }
    if (check_click(all.tex.acceuil, 138, 125, all) == 1 && (all.cn.life == 0 || all.cn.pause == 1)) {
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
        all.str.line = split_line(read_fonction("src/create_waves.txt"), 1, all);
        all = destroy_tower(all);
        set_pos(all.tex.cache, 2000, 2000);
    }
    if (check_click(all.tex.restart, 138, 125, all) == 1 && all.cn.life == 0) {
        all.cn.life = 150;
        all.cn.money = 3000;
        all.cn.reset_map = 0;
        all.cn.reset_map_v = 0;
        all.cn.number_waves = 1;
        all.cn.place_bl = 0;
        all.str.line = split_line(read_fonction("src/create_waves.txt"), 1, all);
        all.cn.max = 1;
        all = destroy_tower(all);
        set_pos(all.tex.cache, 2000, 2000);
    }
    if (check_click(all.tex.trophe, 138, 125, all) == 1 && all.cn.life == 0)
        aff_highscore(all);
    return (all);
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
    all.cn.nb_t1 = 1;
    all.cn.nb_t2 = 1;
    all.cn.nb_t3 = 1;
    all.cn.nb_t4 = 1;
    all.cn.nb_t = 0;
    all.cn.nb_pic = 2;
    return (all);
}

void aff_highscore(all_t all)
{
    all.tx.name1 = create_text(all.tx.name1, 100, my_read("src/n1.txt", all));
    all.tx.name2 = create_text(all.tx.name2, 100, my_read("src/n2.txt", all));
    all.tx.name3 = create_text(all.tx.name3, 100, my_read("src/n3.txt", all));
    all.tx.wave1 = create_text(all.tx.wave1, 100, my_read("src/nu1.txt", all));
    all.tx.wave2 = create_text(all.tx.wave2, 100, my_read("src/nu2.txt", all));
    all.tx.wave3 = create_text(all.tx.wave3, 100, my_read("src/nu3.txt", all));
    set_pos_text(all.tx.name1, 600, 420);
    set_pos_text(all.tx.name2, 600, 570);
    set_pos_text(all.tx.name3, 600, 725);
    set_pos_text(all.tx.wave1, 1310, 420);
    set_pos_text(all.tx.wave2, 1310, 570);
    set_pos_text(all.tx.wave3, 1310, 725);
    set_pos(all.tex.home, 50, 900);
    while (check_release(all.tex.home, 128, 128, all) != 1)
        display_highscore(all);
    set_pos(all.tex.home, 1750, 900);
}