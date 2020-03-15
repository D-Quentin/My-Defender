/*
** EPITECH PROJECT, 2020
** best
** File description:
** score
*/

#include "my.h"

char *my_write(char *buffer, char *file, all_t all)
{
    int i = my_strlen(buffer);

    write(open(file, O_WRONLY | O_TRUNC), buffer, i);
    return buffer;
}

char *my_read(char *file, all_t all)
{
    char *buffer = malloc(sizeof(char) * 10);
    int i = 0;

    while (i != 10) {
        buffer[i] = '\0';
        i++;
    }
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