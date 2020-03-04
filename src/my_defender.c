/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** m
*/

#include "my.h"

int main(int ac, char **av)
{
    my_putchar('t');
    all_t all;
    
    my_putchar('t');
    if (ac != 1)
        return (84);
    my_putchar('t');
    all = init(all);
    my_putchar('t');
    while (sfRenderWindow_isOpen(all.window)) {
        if (all.cn.title == 1)
            all = title(all);
        if (all.cn.setting == 1)
            all = setting(all);
        if (all.cn.play == 1)
            all = play(all);
    }
    return (0);
}
