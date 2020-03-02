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
    if ((all.event.type == sfEvtClosed ||
        check_click(all.tex.exit, 128, 128, all) == 1) &&
        all.cn.setting != 1) {
        sfRenderWindow_close(all.window);
        all.cn.title = 0;
        all.cn.play = 0;
        all.cn.setting = 0;
    }
    return (all);
}