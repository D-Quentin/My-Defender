/*
** EPITECH PROJECT, 2020
** life
** File description:
** life
*/

#include "my.h"

all_t gest_life2(all_t all, int spd)
{
    char *life = malloc(sizeof(char) * 4);

    if (spd == 1 && all.pos.ballon.y == 36)
        all.cn.life = all.cn.life - 1;
    if (spd == 3 && all.pos.ballon.y == 36)
        all.cn.life = all.cn.life - 2;
    if (spd == 2 && all.pos.ballon.y == 36)
        all.cn.life = all.cn.life - 5;
    if (all.cn.life < 0)
        all.cn.life = 0;
    return (all);
}

all_t gest_life(all_t all, int spd)
{
    char *life = malloc(sizeof(char) * 4);

    if (spd == 1 && all.pos.ballon.x == 1490)
        all.cn.life = all.cn.life - 1;
    if (spd == 3 && all.pos.ballon.x == 1490)
        all.cn.life = all.cn.life - 2;
    if (spd == 2 && all.pos.ballon.x == 1490)
        all.cn.life = all.cn.life - 5;
    if (all.cn.life < 0)
        all.cn.life = 0;
    return (all);
}
