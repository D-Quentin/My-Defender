/*
** EPITECH PROJECT, 2020
** init
** File description:
** m
*/

#include "my.h"

all_t init(all_t all)
{
    all = init_malloc(all);
    all = init_tex(all);
    all = init_tex2(all);
    all = init_counter(all);
    all = init_text(all);
    all = init_rect(all);
    all = init_music(all);
    all = init_posi(all);
    all = init_str(all);
    all = init_clock(all);
    init_pos(all);
    init_pos_text(all);
    all.window = set_win("My Runner", all.cn.fps, 1);
    return (all);
}

all_t init_malloc(all_t all)
{
    all.tex.slid = malloc(sizeof(sfSprite *) * 3);
    all.tex.slid2 = malloc(sizeof(sfSprite *) * 3);
    all.tex.hud = malloc(sizeof(sfSprite *) * 2);
    all.tex.hud2 = malloc(sizeof(sfSprite *) * 2);
    all.tex.p1_l0 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p2_l0 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p3_l0 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p4_l0 = malloc(sizeof(sfSprite *) * 100);
    all.pos.tower = malloc(sizeof(sfVector2i) * 100);
    all.tex.dart = malloc(sizeof(sfSprite *) * 100);
    all.tex.laser = malloc(sizeof(sfSprite *) * 100);
    all.tex.fireball = malloc(sizeof(sfSprite *) * 100);
    all.tex.shuriken = malloc(sizeof(sfSprite *) * 100);
    all.str.nb_dart = malloc(sizeof(char) * 100);
    all.str.nb_fireball = malloc(sizeof(char) * 100);
    all.str.nb_laser = malloc(sizeof(char) * 100);
    all = init_malloc2(all);
    return (all);
}

all_t init_malloc2(all_t all)
{
    all.str.nb_shuriken = malloc(sizeof(char) * 100);
    all.cl.dart = malloc(sizeof(sfClock *) * 100);
    all.cl.shuriken = malloc(sizeof(sfClock *) * 100);
    all.cl.fireball = malloc(sizeof(sfClock *) * 100);
    all.cl.laser = malloc(sizeof(sfClock *) * 100);
    all.cn.lvl1 = malloc(sizeof(float) * 100);
    all.cn.lvl2 = malloc(sizeof(float) * 100);
    all.cn.lvl3 = malloc(sizeof(float) * 100);
    all.cn.lvl4 = malloc(sizeof(float) * 100);
    all.cn.dura_pic = malloc(sizeof(int) * 100);
    all.pos.pic = malloc(sizeof(sfVector2i) * 100);
    all.tex.pic = malloc(sizeof(sfSprite *) * 100);
    return (all);
}

all_t init_str(all_t all)
{
    int i = 0;

    while (i != 100) {
        all.str.nb_dart[i] = '0';
        all.str.nb_fireball[i] = '0';
        all.str.nb_laser[i] = '0';
        all.str.nb_shuriken[i] = '0';
        i++;
    }
    return (all);
}

all_t init_te(all_t all)
{
    all.te.b1 = sfTexture_createFromFile("files/b1.png", NULL);
    all.te.b2 = sfTexture_createFromFile("files/b2.png", NULL);
    all.te.b3 = sfTexture_createFromFile("files/b3.png", NULL);
    all.te.b4 = sfTexture_createFromFile("files/b4.png", NULL);
    all.te.b5 = sfTexture_createFromFile("files/b5.png", NULL);
    return (all);
}