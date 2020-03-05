/*
** EPITECH PROJECT, 2020
** life
** File description:
** life
*/

#include "my.h"

all_t gest_life(all_t all, int spd)
{
    char *life = malloc(sizeof(char) * 4);
    
    if (spd == 1 && all.pos.ballon.x == 1460)
        all.cn.life = all.cn.life - 1;
    if (spd == 3 && all.pos.ballon.x == 1460)
        all.cn.life = all.cn.life - 2;
    if (spd == 2 && all.pos.ballon.x == 1460)
        all.cn.life = all.cn.life - 5;

    life = my_itoa(all.cn.life);
    sfText_setString(all.tx.life, life);
    sfRenderWindow_drawText(all.window, all.tx.life, NULL);
    return (all);
}

