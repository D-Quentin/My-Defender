/*
** EPITECH PROJECT, 2020
** setting
** File description:
** m
*/

#include "my.h"

all_t setting(all_t all)
{
    while (all.cn.setting == 1) {
        display_setting(all);
        all = analyse_event(all);
        all = gest_slider(all, all.tex.slid2[0], 1082, 0);
        all = gest_slider(all, all.tex.slid2[1], 1082, 1);
        all = gest_slider(all, all.tex.slid2[2], 182, 2);
        all = set_window(all);
        all = scale_tex(all.tex.home, all.cn.s_home, all);
        all = scale_tex(all.tex.hud[0], all.cn.s_hud1, all);
        all = scale_tex(all.tex.hud[1], all.cn.s_hud2, all);
        if (check_release(all.tex.home, 128, 127, all) == 1) {
            all.cn.title = 1;
            all.cn.setting = 0;
        }
    }
    return (all);
}

all_t set_window(all_t all)
{
    if (check_release(all.tex.hud[1], 465, 146, all) == 1 && \
        all.cn.window != 1) {
        set_pos(all.tex.arrow, 50, 522);
        sfRenderWindow_destroy(all.window);
        all.window = set_win("My Defender", all.cn.fps, 1);
        all.cn.window = 1;
    }
    else if (check_release(all.tex.hud[0], 465, 147, all) == 1 && \
        all.cn.window != 0) {
        set_pos(all.tex.arrow, 50, 322);
        sfRenderWindow_destroy(all.window);
        all.window = set_win("My Defender", all.cn.fps, 0);
        all.cn.window = 0;
    }
    return (all);
}