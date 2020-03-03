/*
** EPITECH PROJECT, 2020
** play
** File description:
** m
*/

#include "my.h"

all_t play(all_t all)
{
    while (all.cn.play == 1) {
        if (all.cn.map == 1)
            all = init_waves(all);
            //first_path(all);
        else
            second_path(all);
        display_play(all);
    }
    return (all);
}
