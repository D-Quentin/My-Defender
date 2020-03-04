/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** kkjdk
*/

#include "../../include/my.h"

char *my_strcat(char *str1, char *str2)
{
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    char *cat = malloc(sizeof(char) * (size1 * size2));

    for (int i = 0; i < (size1 + size2); i++) {
        for (int j = 0; j < size1; j++, i++)
            cat[i] = str1[j];
        for (int k = 0; k < size2; k++, i++)
            cat[i] = str2[k];
        cat[i] = '\0';
    }
    return (cat);
}
