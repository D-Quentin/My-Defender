/*
** EPITECH PROJECT, 2020
** sprite
** File description:
** animé
*/

#include "my.h"

all_t animated_sprite(all_t all)
{
    int static mpol = 0;
    
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.sablier)) > 1000) {
        all.cn.sablier.left = mpol;
        if (mpol >= 728) {
            all.cn.sablier.left = 0;
            mpol = 0;
            sfClock_restart(all.cl.sablier);
        }
        mpol = mpol + 91;
        sfSprite_setTextureRect(all.tex.sablier, all.cn.sablier);
        sfClock_restart(all.cl.sablier);
    }
    return all;
}
