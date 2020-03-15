/*
** EPITECH PROJECT, 2020
** display3
** File description:
** m
*/

#include "my.h"

void display_pause(all_t all)
{
    sfRenderWindow_drawSprite(all.window, all.tex.cache, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.pause, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.restart, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.exitt, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.acceuil, NULL);
    sfRenderWindow_drawText(all.window, all.tx.pause, NULL);
}

void display_bl(all_t all)
{
    int i = 0;

    while (i != all.cn.line) {
        sfRenderWindow_drawSprite(all.window, all.tex.tab[i], NULL);
        i++;
    }
}

void display_tower(all_t all)
{
    for (int i = 0; i != all.cn.nb_t1; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p1_l0[i], NULL);
    for (int i = 0; i != all.cn.nb_t2; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p2_l0[i], NULL);
    for (int i = 0; i != all.cn.nb_t3; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p3_l0[i], NULL);
    for (int i = 0; i != all.cn.nb_t4; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p4_l0[i], NULL);
    for (int i = 0; i != all.cn.nb_pic; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.pic[i], NULL);
}

void display_choose_map(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.back, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.hud2[0], NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.hud2[1], NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.map1, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.map2, NULL);
    sfRenderWindow_drawText(all.window, all.tx.choose, NULL);
    sfRenderWindow_display(all.window);
}

void display_title(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.title, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.play, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.setting, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.lboard, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.exit, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.htp_icon, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.tower_icon, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.cache, NULL);
    if (all.cn.luffy == 1)
        sfRenderWindow_drawSprite(all.window, all.tex.luffy, NULL);
    sfRenderWindow_display(all.window);
}