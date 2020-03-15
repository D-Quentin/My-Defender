/*
** EPITECH PROJECT, 2020
** event
** File description:
** m
*/

#include "my.h"

all_t analyse_event(all_t all)
{
    while (sfRenderWindow_pollEvent(all.window, &all.event)) {
        all = close_window(all);
    }
    return (all);
}

all_t close_window(all_t all)
{
    if (all.event.type == sfEvtClosed ||
        (check_release(all.tex.exit, 128, 128, all) == 1 &&
        all.cn.title == 1)) {
        sfRenderWindow_close(all.window);
        all.cn.title = 0;
        all.cn.play = 0;
        all.cn.setting = 0;
    }
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