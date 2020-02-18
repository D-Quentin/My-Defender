/*
** EPITECH PROJECT, 2020
** init
** File description:
** m
*/

#include "my.h"

all_t init(all_t all)
{
    all.window = set_win("My Defender", 60, 1);
    all = init_clock(all);
    all = init_tex(all);
    all = init_tex2(all);
    all = init_counter(all);
    all = init_text(all);
    all = init_rect(all);
    all = init_music(all);
    init_pos(all);
    return (all);
}

void init_pos(all_t all)
{
    set_pos(all.tex.play, 730, 820);
}

all_t init_tex(all_t all)
{
    all.tex.title = create_sprite(all.tex.title, "files/title.png");
    all.tex.play = create_sprite(all.tex.play, "files/play.png");
    all.tex.bal_lvl1 = create_sprite(all.tex.bal_lvl1, "files/bal_lvl1.png");
    all.tex.bal_lvl2 = create_sprite(all.tex.bal_lvl2, "files/bal_lvl2.png");
    all.tex.bal_lvl3 = create_sprite(all.tex.bal_lvl3, "files/bal_lvl3.png");
    all.tex.bal_lvl4 = create_sprite(all.tex.bal_lvl4, "files/bal_lvl4.png");
    all.tex.bal_lvl5 = create_sprite(all.tex.bal_lvl5, "files/bal_lvl5.png");
    all.tex.bal_lvl6 = create_sprite(all.tex.bal_lvl6, "files/bal_lvl6.png");
    all.tex.case1 = create_sprite(all.tex.case1, "files/case1.png");
    all.tex.case2 = create_sprite(all.tex.case2, "files/case2.png");
    all.tex.case3 = create_sprite(all.tex.case3, "files/case3.png");
    all.tex.case4 = create_sprite(all.tex.case4, "files/case4.png");
    all.tex.case5 = create_sprite(all.tex.case5, "files/case5.png");
    all.tex.map1 = create_sprite(all.tex.map1, "files/map1.png");
    all.tex.map2 = create_sprite(all.tex.map2, "files/map2.png");
    return (all);
}

all_t init_tex2(all_t all)
{
    all.tex.p1_lvl0 = create_sprite(all.tex.p1_lvl0, "files/p1_lvl0.png");
    all.tex.p1_lvl1 = create_sprite(all.tex.p1_lvl1, "files/p1_lvl1.png");
    all.tex.p1_lvl2 = create_sprite(all.tex.p1_lvl2, "files/p1_lvl2.png");
    all.tex.p2_lvl0 = create_sprite(all.tex.p2_lvl0, "files/p2_lvl0.png");
    all.tex.p2_lvl1 = create_sprite(all.tex.p2_lvl1, "files/p2_lvl1.png");
    all.tex.p2_lvl2 = create_sprite(all.tex.p2_lvl2, "files/p2_lvl2.png");
    all.tex.p3_lvl0 = create_sprite(all.tex.p3_lvl0, "files/p3_lvl0.png");
    all.tex.p3_lvl1 = create_sprite(all.tex.p3_lvl1, "files/p3_lvl1.png");
    all.tex.p3_lvl2 = create_sprite(all.tex.p3_lvl2, "files/p3_lvl2.png");
    all.tex.p4_lvl0 = create_sprite(all.tex.p4_lvl0, "files/p4_lvl0.png");
    all.tex.p1_lvl1 = create_sprite(all.tex.p1_lvl1, "files/p1_lvl1.png");
    return (all);
}

all_t init_counter(all_t all)
{
    all.cn.title = 1;
    all.cn.setting = 0;
    all.cn.scoreboard = 0;
    return (all);
}

all_t init_text(all_t all)
{
}

all_t init_rect(all_t all)
{
}

all_t init_clock(all_t all)
{
}

all_t init_music(all_t all)
{
}
