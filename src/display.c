/*
** EPITECH PROJECT, 2020
** display
** File description:
** m
*/

#include "my.h"

void display_life(all_t all)
{
    char *life;

    life = my_itoa(all.cn.life);
    sfText_setString(all.tx.life, life);
    sfRenderWindow_drawText(all.window, all.tx.life, NULL);
}

void display_money(all_t all)
{
    char *money;

    money = my_itoa(all.cn.money);
    sfText_setString(all.tx.money, money);
    sfRenderWindow_drawText(all.window, all.tx.money, NULL);
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
    display_life(all);
    sfRenderWindow_drawSprite(all.window, all.tex.p1, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.p2, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.p3, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.p4, NULL);
    display_tower(all);
    display_money(all);
    sfRenderWindow_drawSprite(all.window, all.tex.c_green, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.c_red, NULL);
    sfRenderWindow_display(all.window);
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
    for(int i = 0; i != all.cn.nb_t1; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p1_l0[i], NULL);
    for(int i = 0; i != all.cn.nb_t2; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p2_l0[i], NULL);
    for(int i = 0; i != all.cn.nb_t3; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p3_l0[i], NULL);
    for(int i = 0; i != all.cn.nb_t4; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p4_l0[i], NULL);
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
    sfRenderWindow_display(all.window);
}

void display_setting(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.back, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.home, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.slid[0], NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.slid2[0], NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.slid[1], NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.slid2[1], NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.slid[2], NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.slid2[2], NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.hud[0], NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.hud[1], NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.arrow, NULL);
    sfRenderWindow_drawText(all.window, all.tx.nb_music, NULL);
    sfRenderWindow_drawText(all.window, all.tx.nb_sound, NULL);
    sfRenderWindow_drawText(all.window, all.tx.nb_fps, NULL);
    sfRenderWindow_drawText(all.window, all.tx.fps, NULL);
    sfRenderWindow_drawText(all.window, all.tx.sound, NULL);
    sfRenderWindow_drawText(all.window, all.tx.music, NULL);
    sfRenderWindow_drawText(all.window, all.tx.windowed, NULL);
    sfRenderWindow_drawText(all.window, all.tx.fullscreen, NULL);
    sfRenderWindow_display(all.window);
}
