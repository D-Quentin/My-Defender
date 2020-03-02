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
        if (check_click(all.tex.setting, 92, 94, all) == 1) {
            all.cn.setting = 1;
            all.cn.title = 0;
        }
    }
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
        if (check_click(all.tex.hud[0], 465, 146, all) == 1) {
            
        if (check_click(all.tex.home, 128, 128, all) == 1) {
            all.cn.title = 1;
            all.cn.setting = 0;
        }
    }
    return (all);
}
