/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** m
*/

#include "my.h"

int main(int ac, char **av, char **env)
{
    all_t all;
    
    if (env == NULL)
        return (84);
    if (ac != 2) {
        my_putstr("\n\n./my_defender (name)\n\n\n");
        return 84;
    }
    all = init(all);
    all.str.name = av[1];
    backgound_music(all);
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
