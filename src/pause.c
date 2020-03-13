/*
** EPITECH PROJECT, 2020
** pause
** File description:
** m
*/

#include "my.h"

all_t game_pause(all_t all)
{
    sfIntRect rect = {0, 0, 1920, 1080};

    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        sfSprite_setTextureRect(all.tex.cache, rect);
        all.cn.pause = 1;
        set_pos(all.tex.exitt, 980, 600);
        set_pos(all.tex.cache, 0, 0);
        while (all.cn.pause == 1) {
            if (check_click(all.tex.restart, 138, 125, all) == 1)
                all.cn.pause = 0;
            all = endgame_part(all);
            display_play(all);
        }
        set_pos(all.tex.exitt, 1160, 600);
        set_pos(all.tex.cache, 2000, 2000);
    }
    return (all);
}