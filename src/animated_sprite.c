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
    
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.luffy)) > 150) {
        mpol = mpol + 39,6;
        all.cn.luffy.left = mpol;
        if (mpol >= 158) {
            all.cn.luffy.left = 0;
            mpol = 39,6;
            sfClock_restart(all.cl.luffy);
        }
        sfSprite_setTextureRect(all.tex.luffy, all.cn.luffy);
        sfClock_restart(all.cl.luffy);
    }
    return all;
    /*
    sfRenderWindow_drawSprite(all.window, all.tex.luffy, NULL);
    */
}
