/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** m
*/

#include "my.h"

int main(int ac, char **av)
{
    all_t all;

    if (ac != 1)
        return (84);
    all = init(all);
    while (sfRenderWindow_isOpen(all.window)) {
        if (all.cn.title == 1)
            all = title(all);
        if (all.cn.setting == 1)
            all = setting(all);
    }
    return (0);
}
