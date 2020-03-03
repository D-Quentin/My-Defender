/*
** EPITECH PROJECT, 2020
** waves
** File description:
** waves
*/

#include "my.h"

char *read_fonction(char *file)
{
    int size = 10000;
    char *buffer = malloc(sizeof(char) * 1000);
    read(open(file, O_RDONLY), buffer, size);
    return (buffer);
}

int init_waves(void)
{
    char *waves = read_fonction("src/create_waves.txt");
    my_putstr(waves);
}
