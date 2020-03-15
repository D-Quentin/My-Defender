/*
** EPITECH PROJECT, 2020
** display
** File description:
** m
*/

#include "my.h"

void display_highscore(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.highscore, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.home, NULL);
    sfRenderWindow_drawText(all.window, all.tx.name1, NULL);
    sfRenderWindow_drawText(all.window, all.tx.name2, NULL);
    sfRenderWindow_drawText(all.window, all.tx.name3, NULL);
    sfRenderWindow_drawText(all.window, all.tx.wave1, NULL);
    sfRenderWindow_drawText(all.window, all.tx.wave2, NULL);
    sfRenderWindow_drawText(all.window, all.tx.wave3, NULL);
    sfRenderWindow_display(all.window);
}

void display_play(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    if (all.cn.map == 1) {
        sfRenderWindow_drawSprite(all.window, all.tex.fullmap1bis, NULL);
        display_bl(all);
        sfRenderWindow_drawSprite(all.window, all.tex.fullmap1, NULL);
    } else {
        sfRenderWindow_drawSprite(all.window, all.tex.fullmap2bis, NULL);
        display_bl(all);
        sfRenderWindow_drawSprite(all.window, all.tex.fullmap2, NULL);
    }
    sfRenderWindow_drawSprite(all.window, all.tex.desc1, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.desc2, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.desc3, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.desc4, NULL);
    display_play2(all);
    display_play3(all);
}

void display_play2(all_t all)
{
    sfRenderWindow_drawSprite(all.window, all.tex.up1_1, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.up1_2, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.up2_1, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.up2_2, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.up3_1, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.up3_2, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.up4_1, NULL);
    display_life(all);
    sfRenderWindow_drawText(all.window, all.tx.print_waves, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.p1, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.p2, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.p3, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.p4, NULL);
}

void display_play3(all_t all)
{
    display_tower(all);
    display_money(all);
    display_waves(all);
    display_endscreen(all);
    sfRenderWindow_drawSprite(all.window, all.tex.c_green, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.c_red, NULL);
    display_shoot(all);
    sfRenderWindow_drawSprite(all.window, all.tex.sablier, NULL);
    if (all.cn.pause == 1)
        display_pause(all);
    sfRenderWindow_display(all.window);
}