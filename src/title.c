/*
** EPITECH PROJECT, 2020
** title
** File description:
** m
*/

#include "my.h"

all_t title(all_t all)
{
    while (all.cn.title == 1) {
        display_title(all);
        all = analyse_event(all);
        all = scale_tex(all.tex.setting, all.cn.s_setting, all);
        if (check_release(all.tex.setting, 92, 94, all) == 1) {
            all.cn.setting = 1;
            all.cn.title = 0;
        }
        all = scale_tex(all.tex.exit, all.cn.s_exit, all);
        all = scale_tex(all.tex.play, all.cn.s_play, all);
        if (check_release(all.tex.play, 446, 133, all) == 1) {
            all = choose_map(all);
        }
    }
    return (all);
}

all_t choose_map(all_t all)
{
    while (all.cn.map == 0) {
        display_choose_map(all);
        if (check_click(all.tex.map1, 474, 400, all) == 1) {
            all.cn.map = 1;
            all.pos.ballon.x = 370;
            all.pos.ballon.y = 870;
        }
        if (check_click(all.tex.map2, 474, 400, all) == 1) {
            all.cn.map = 2;
            all.pos.ballon.x = 370;
            all.pos.ballon.y = 450;
        }
    }
    set_pos(all.tex.b1, all.pos.ballon.x, all.pos.ballon.y);
    all.cn.setting = 0;
    all.cn.title = 0;
    all.cn.play = 1;
    return (all);
}    

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
        if (check_release(all.tex.home, 128, 128, all) == 1) {
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
        all.window = set_win("My Runner", all.cn.fps, 1);
        all.cn.window = 1;
    }
    else if (check_release(all.tex.hud[0], 465, 146, all) == 1 && \
             all.cn.window != 0) {
        set_pos(all.tex.arrow, 50, 322);
        sfRenderWindow_destroy(all.window);
        all.window = set_win("My Runner", all.cn.fps, 0);
        all.cn.window = 0;
    }
    return (all);
}


