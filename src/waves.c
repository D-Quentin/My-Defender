/*
** EPITECH PROJECT, 2020
** waves
** File description:
** waves
*/

#include "my.h"

char *read_fonction(char *file)
{
    int fd = open(file, O_RDONLY);
    int size = 5000;
    char *buffer = malloc(sizeof(char) * size);

    read(fd, buffer, size);
    return (buffer);
}

char *read_map(char *file)
{
    int size = 21000;
    char *buffer = malloc(sizeof(char) * size);
    int fd = open(file, O_RDONLY);

    read(fd, buffer, size);
    return (buffer);
}

int compt_bal(char *str)
{
    int i = 0;

    while (str[i] >= '1' && str[i] <= '5')
        i++;
    return i;
}

all_t max_waves(char *str, all_t all)
{
    char *new_line = malloc(sizeof(char) * my_strlen(str) + 1);
    char **waves_round = str_to_chartab(str);
    static int b = 0;

    all.cn.max_waves = my_getnbr(waves_round[0]);
    b++;
    return all;
}