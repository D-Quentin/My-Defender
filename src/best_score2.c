/*
** EPITECH PROJECT, 2020
** best
** File description:
** score
*/

#include "my.h"

char *recup_name(char *str)
{
    int i = 0;
    char *name = malloc(sizeof(char) * 100);

    while (str[i] != ' ') {
        name[i] = str[i];
        i++;
    }
    name[i] = ' ';
    name[i + 1] = '\0';

    return name;
}

char *add_space(char *str)
{
    char *space = malloc(sizeof(char) * 100);
    int i = 0;

    while (str[i] != '\0') {
        space[i] = str[i];
        i++;
    }
    space[i] = ' ';
    space[i + 1] = '\0';
    return space;
}

all_t read_score(all_t all)
{
    all.cn.a = my_getnbr(my_read(all.str.nbr1, all));
    all.cn.b = my_getnbr(my_read(all.str.nbr2, all));
    all.cn.c = my_getnbr(my_read(all.str.nbr3, all));
    all.str.n1 = my_read(all.str.name1, all);
    all.str.n2 = my_read(all.str.name2, all);
    all.str.n3 = my_read(all.str.name3, all);
    if (all.cn.number_waves >= all.cn.a && all.cn.number_waves >=
        all.cn.b && all.cn.number_waves >= all.cn.c) {
        my_write(all.str.n2, all.str.name3, all);
        my_write(all.str.n1, all.str.name2, all);
        my_write(all.str.name, all.str.name1, all);
        my_write(my_itoa(all.cn.b), all.str.nbr3, all);
        my_write(my_itoa(all.cn.a), all.str.nbr2, all);
        my_write(my_itoa(all.cn.number_waves), all.str.nbr1, all);
    }
    return all;
}

all_t modif_score(all_t all)
{
    if (all.cn.number_waves < all.cn.a && all.cn.number_waves >=
        all.cn.b && all.cn.number_waves >= all.cn.c) {
        my_write(all.str.n2, all.str.name3, all);
        my_write(all.str.name, all.str.name2, all);
        my_write(my_itoa(all.cn.b), all.str.nbr3, all);
        my_write(my_itoa(all.cn.number_waves), all.str.nbr2, all);
    }
    return all;
}

all_t check_best_score(all_t all)
{
    if (all.cn.life == 0 && all.cn.reset_best_score == 0) {
        all.str.name1 = "src/n1.txt";
        all.str.name2 = "src/n2.txt";
        all.str.name3 = "src/n3.txt";
        all.str.nbr1 = "src/nu1.txt";
        all.str.nbr2 = "src/nu2.txt";
        all.str.nbr3 = "src/nu3.txt";
        all.cn.reset_best_score++;
        all = read_score(all);
        all = modif_score(all);
        if (all.cn.number_waves < all.cn.a && all.cn.number_waves < all.cn.b &&
            all.cn.number_waves >= all.cn.c) {
            my_write(all.str.name, all.str.name3, all);
            my_write(my_itoa(all.cn.number_waves), all.str.nbr3, all);
        }
    }
    return all;
}
