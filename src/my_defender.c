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
    all = main_loop(all);
    destroy(all);
    return (0);
}

all_t main_loop(all_t all)
{
    while (sfRenderWindow_isOpen(all.window)) {
        if (all.cn.title == 1)
            all = title(all);
        if (all.cn.setting == 1)
            all = setting(all);
        if (all.cn.play == 1)
            all = play(all);
    }
    return (all);
}

void destroy(all_t all)
{
    sfMusic_stop(all.mu.music);
    sfMusic_destroy(all.mu.music);
    sfMusic_stop(all.mu.shoot);
    sfMusic_destroy(all.mu.shoot);
    sfMusic_stop(all.mu.upgrade);
    sfMusic_destroy(all.mu.upgrade);
}