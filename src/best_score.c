/*
** EPITECH PROJECT, 2020
** best
** File description:
** score
*/

#include "my.h"

char *write_high_score(char *buffer, char *file, all_t all)
{
    write(open(file, O_WRONLY | O_TRUNC), buffer, 100);
    return buffer;
}

char *read_high_score(char *file, all_t all)
{
    char *buffer = malloc(sizeof(char) * 10);

    read(open(file, O_RDONLY), buffer, 100);

    return buffer;
}

char *recup_nbr(char *str)
{
    int i = 0;
    int a = 0;
    char *number = malloc(sizeof(char) * 4);
    
    while (str[i] != ' ')
        i++;
    while (str[i] != '\0') {
        number[a] = str[i];
        a++;
        i++;
    }
    return number;
}
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
all_t check_best_score(all_t all)
{
    char *name1 = "src/name1.txt";
    char *name2 = "src/name2.txt";
    char *name3 = "src/name3.txt";
    char *nbr1 = "src/num_1.txt";
    char *nbr2 = "src/num_2.txt";
    char *nbr3 = "src/num_3.txt";
    int a;
    int b;
    int c;
    char *n1;
    char *n2;
    char *n3;
    static int x = 0;
    
    if (all.cn.life == 0 && x == 0) {
        a = my_getnbr(read_high_score(nbr1, all));
        b = my_getnbr(read_high_score(nbr2, all));
        c = my_getnbr(read_high_score(nbr3, all));
        n1 = read_high_score(name1, all);
        n2 = read_high_score(name2, all);
        n3 = read_high_score(name3, all);
        if (all.cn.number_waves >= a && all.cn.number_waves >= b && all.cn.number_waves >= c) {
            write_high_score(n2, name3, all);
            write_high_score(n1, name2, all);
            write_high_score(all.str.name, name1, all);
            write_high_score(my_itoa(b), nbr3, all);
            write_high_score(my_itoa(a), nbr2, all);
            write_high_score(my_itoa(all.cn.number_waves), nbr1, all);
        }
        if (all.cn.number_waves < a && all.cn.number_waves >= b && all.cn.number_waves >= c) {
            write_high_score(n2, name3, all);
            write_high_score(all.str.name, name2, all);
            write_high_score(my_itoa(b), nbr3, all);
            write_high_score(my_itoa(all.cn.number_waves), nbr2, all);
        }
        if (all.cn.number_waves < a && all.cn.number_waves < b && all.cn.number_waves >= c) {
            write_high_score(all.str.name, name3, all);
            write_high_score(my_itoa(all.cn.number_waves), nbr3, all);
        }
        x++;
    }
}
