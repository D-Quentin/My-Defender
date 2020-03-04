/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** Navy
*/

#include "my.h"

int count_l(char *str)
{
    int countline = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            countline++;
        }
        i++;
    }
    return (countline);
}

int count_c(char *str, int i)
{
    int countcarac = 0;

    while (str[i] != '\0') {
        if (str[i] != '\n')
            countcarac++;
        i++;
    }
    return (countcarac);
}

char **my_strtowordarray(char *str)
{
    int countl = count_l(str);
    char **tab = malloc(sizeof(char *) * (countl + 1));
    int i = 0;
    int tab1 = 0;
    int tab2 = 0;

    while (tab1 != countl) {
        tab[tab1] = malloc(sizeof(char) * (count_c(str, i) + 1));
        while (str[i] != '\n' && str[i] != '\0'){
            tab[tab1][tab2] = str[i];
            i++;
            tab2 ++;
        }
        tab[tab1][tab2] = '\0';
        tab2 = 0;
        tab1 ++;
        i++;
    }
    tab[tab1] = NULL;
    return (tab);
}
