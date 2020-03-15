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

    if (all.cn.life == 0)
        life = "0";
    else
        life = my_itoa(all.cn.life);
    sfText_setString(all.tx.life, life);
    sfRenderWindow_drawText(all.window, all.tx.life, NULL);
}

void display_money(all_t all)
{
    char *money;

    if (all.cn.money == 0)
        money = "0";
    else
        money = my_itoa(all.cn.money);
    sfText_setString(all.tx.money, money);
    sfRenderWindow_drawText(all.window, all.tx.money, NULL);
}

void display_waves(all_t all)
{
    char *waves = malloc(sizeof(char) * 10);

    waves = my_itoa(all.cn.number_waves);
    sfText_setString(all.tx.waves, waves);
    sfRenderWindow_drawText(all.window, all.tx.waves, NULL);
}
void display_endscreen(all_t all)
{
    sfIntRect rect = {0, 0, 1920, 1080};

    if (all.cn.life == 0) {
        sfSprite_setTextureRect(all.tex.cache, rect);
        set_pos(all.tex.cache, 0, 0);
        sfRenderWindow_drawSprite(all.window, all.tex.cache, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.lose, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.restart, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.exitt, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.acceuil, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.trophe, NULL);
    }
}
void display_shoot(all_t all)
{
    int i = 0;

    while (i != 100) {
        if (all.str.nb_dart[i] == '1') {
            sfRenderWindow_drawSprite(all.window, all.tex.dart[i], NULL);
        }
         if (all.str.nb_shuriken[i] == '1') {
            sfRenderWindow_drawSprite(all.window, all.tex.shuriken[i], NULL);
        }
         if (all.str.nb_fireball[i] == '1') {
            sfRenderWindow_drawSprite(all.window, all.tex.fireball[i], NULL);
        }
         if (all.str.nb_laser[i] == '1') {
            sfRenderWindow_drawSprite(all.window, all.tex.laser[i], NULL);
        }
        i++;
    }
}

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
    for(int i = 0; i != all.cn.nb_t1; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p1_l0[i], NULL);
    for(int i = 0; i != all.cn.nb_t2; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p2_l0[i], NULL);
    for(int i = 0; i != all.cn.nb_t3; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p3_l0[i], NULL);
    for(int i = 0; i != all.cn.nb_t4; i++)
        sfRenderWindow_drawSprite(all.window, all.tex.p4_l0[i], NULL);
    for(int i = 0; i != all.cn.nb_pic; i++)
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
    sfRenderWindow_drawSprite(all.window, all.tex.cache, NULL);
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

void display_htp(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.htp, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.home, NULL);
    sfRenderWindow_display(all.window);
}

void display_list_tower(all_t all)
{
    sfRenderWindow_clear(all.window, sfBlack);
    sfRenderWindow_drawSprite(all.window, all.tex.list_tower, NULL);
    sfRenderWindow_drawSprite(all.window, all.tex.home, NULL);
    sfRenderWindow_display(all.window);
}