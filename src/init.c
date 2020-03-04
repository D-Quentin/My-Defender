/*
** EPITECH PROJECT, 2020
** init
** File description:
** m
*/

#include "my.h"

all_t init(all_t all)
{
    all = init_clock(all);
    all = init_malloc(all);
    all = init_tex(all);
    all = init_tex2(all);
    all = init_counter(all);
    all = init_text(all);
    all = init_rect(all);
    all = init_music(all);
    all = init_posi(all);
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
    all.tex.p1_l1 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p1_l2 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p2_l0 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p2_l1 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p2_l2 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p3_l0 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p3_l1 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p3_l2 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p4_l0 = malloc(sizeof(sfSprite *) * 100);
    all.tex.p4_l1 = malloc(sizeof(sfSprite *) * 100);
    all.pos.tower = malloc(sizeof(sfVector2i) * 50);
    return (all);
}

void init_pos(all_t all)
{
    set_pos(all.tex.play, 730, 820);
    set_pos(all.tex.setting, 30, 840);
    set_pos(all.tex.lboard, 30, 950);
    set_pos(all.tex.exit, 1750, 900);
    set_pos(all.tex.home, 1750, 900);
    set_pos(all.tex.slid[0], 1050, 400);
    set_pos(all.tex.slid2[0], 1668, 394);
    set_pos(all.tex.slid[1], 1050, 600);
    set_pos(all.tex.slid2[1], 1668, 594);
    set_pos(all.tex.slid[2], 150, 800);
    set_pos(all.tex.slid2[2], 750, 794);
    set_pos(all.tex.hud[0], 200, 300);
    set_pos(all.tex.hud[1], 200, 500);
    set_pos(all.tex.arrow, 50, 522);
    set_pos(all.tex.map1, 320, 375);
    set_pos(all.tex.map2, 1125, 375);
    set_pos(all.tex.hud2[0], 285, 340);
    set_pos(all.tex.hud2[1], 1090, 340);
    set_pos(all.tex.p1, 40, 10);
    set_pos(all.tex.p2, 40, 280);
    set_pos(all.tex.p3, 40, 540);
    set_pos(all.tex.p4, 40, 800);
    set_pos(all.tex.p1_l0[0], 2000, 2000);
    set_pos(all.tex.p2_l0[0], 2000, 2000);
    set_pos(all.tex.p3_l0[0], 2000, 2000);
    set_pos(all.tex.p4_l0[0], 2000, 2000);
    set_pos(all.tex.c_green, 2000, 2000);
    set_pos(all.tex.c_red, 2000, 2000);
}

all_t init_tex(all_t all)
{
    all.tex.title = create_sprite(all.tex.title, "files/title.png");
    all.tex.play = create_sprite(all.tex.play, "files/play.png");
    all.tex.bal_lvl1 = create_sprite(all.tex.bal_lvl1, "files/bal_lvl1.png");
    all.tex.bal_lvl2 = create_sprite(all.tex.bal_lvl2, "files/bal_lvl2.png");
    all.tex.bal_lvl3 = create_sprite(all.tex.bal_lvl3, "files/bal_lvl3.png");
    all.tex.bal_lvl4 = create_sprite(all.tex.bal_lvl4, "files/bal_lvl4.png");
    all.tex.bal_lvl5 = create_sprite(all.tex.bal_lvl5, "files/bal_lvl5.png");
    all.tex.map1 = create_sprite(all.tex.map1, "files/map1.png");
    all.tex.map2 = create_sprite(all.tex.map2, "files/map2.png");
    all.tex.setting = create_sprite(all.tex.setting, "files/setting.png");
    all.tex.lboard = create_sprite(all.tex.lboard, "files/lboard.png");
    all.tex.exit = create_sprite(all.tex.exit, "files/exit.png");
    all.tex.home = create_sprite(all.tex.home, "files/home.png");
    all.tex.back = create_sprite(all.tex.back, "files/back.png");
    all.tex.slid[0] = create_sprite(all.tex.slid[0], "files/slid.png");
    all.tex.slid2[0] = create_sprite(all.tex.slid2[0], "files/slid2.png");
    all.tex.slid[1] = create_sprite(all.tex.slid[1], "files/slid.png");
    all.tex.slid2[1] = create_sprite(all.tex.slid2[1], "files/slid2.png");
    all.tex.slid[2] = create_sprite(all.tex.slid[2], "files/slid.png");
    all.tex.slid2[2] = create_sprite(all.tex.slid2[2], "files/slid2.png");
    all.tex.hud[0] = create_sprite(all.tex.hud[0], "files/hud.png");
    all.tex.hud[1] = create_sprite(all.tex.hud[1], "files/hud.png");
    all.tex.hud2[0] = create_sprite(all.tex.hud2[0], "files/hud2.png");
    all.tex.hud2[1] = create_sprite(all.tex.hud2[1], "files/hud2.png");
    all.tex.arrow = create_sprite(all.tex.arrow, "files/arrow.png");
    return (all);
}

all_t init_tex2(all_t all)
{
    all.tex.p1_l0[0] = create_sprite(all.tex.p1_l0[0], "files/p1_l0.png");
    all.tex.p2_l0[0] = create_sprite(all.tex.p2_l0[0], "files/p2_l0.png");
    all.tex.p3_l0[0] = create_sprite(all.tex.p3_l0[0], "files/p3_l0.png");
    all.tex.p4_l0[0] = create_sprite(all.tex.p4_l0[0], "files/p4_l0.png");
    all.tex.p1 = create_sprite(all.tex.p1, "files/p1.png");
    all.tex.p2 = create_sprite(all.tex.p2, "files/p2.png");
    all.tex.p3 = create_sprite(all.tex.p3, "files/p3.png");
    all.tex.p4 = create_sprite(all.tex.p4, "files/p4.png");
    all.tex.fullmap1 = create_sprite(all.tex.fullmap1, "files/fullmap1.png");
    all.tex.fullmap1bis = create_sprite(all.tex.fullmap1bis, "files/map1bis.png");
    all.tex.fullmap2 = create_sprite(all.tex.fullmap2, "files/fullmap2.png");
    all.tex.fullmap2bis = create_sprite(all.tex.fullmap2bis, "files/map2bis.png");
    all.tex.c_green = create_sprite(all.tex.c_green, "files/c_green.png");
    all.tex.c_red = create_sprite(all.tex.c_red, "files/c_red.png");
    return (all);
}

all_t init_counter(all_t all)
{
    all.cn.title = 1;
    all.cn.setting = 0;
    all.cn.scoreboard = 0;
    all.cn.window = 1;
    all.cn.fps = 144;
    all.cn.map = 0;
    all.cn.play = 0;
    all.cn.place_bl = 0;
    all.cn.tower = 0;
    all.cn.money = 3000;
    all.cn.nb_t1 = 1;
    all.cn.nb_t2 = 1;
    all.cn.nb_t3 = 1;
    all.cn.nb_t4 = 1;
    all.cn.nb_t = 0;
    return (all);
}

all_t init_text(all_t all)
{
    all.tx.nb_music = create_text(all.tx.nb_music, 80, "100%");
    all.tx.nb_sound = create_text(all.tx.nb_sound, 80, "100%");
    all.tx.nb_fps = create_text(all.tx.nb_sound, 80, "144");
    all.tx.music = create_text(all.tx.music, 80, "MUSIC");
    all.tx.sound = create_text(all.tx.sound, 80, "SOUND EFFECT");
    all.tx.fps = create_text(all.tx.fps, 80, "FPS");
    all.tx.windowed = create_text(all.tx.windowed, 80, "WINDOWED");
    all.tx.fullscreen = create_text(all.tx.fullscreen, 80, "FULLSCREEN");
    all.tx.choose = create_text(all.tx.choose, 120, "CHOOSE YOUR MAP");
    return (all);
}

all_t init_rect(all_t all)
{
}

all_t init_clock(all_t all)
{
    all.cl.map = sfClock_create();
    all.cl.d = sfClock_create();
    return (all);
}

all_t init_music(all_t all)
{
}

all_t init_posi(all_t all)
{
    all.pos.b.x = 340;
    all.pos.b.y = 480;
    all.pos.up.y = -1;
    all.pos.right.x = 1;
    all.pos.down.y = 1;
    all.pos.up_right.x = 1;
    all.pos.up_right.y = -1;
    all.pos.up_left.x = -1;
    all.pos.up_left.y = -1;
    all.pos.down_right.x = 1;
    all.pos.down_right.y = 1;
    all.pos.down_left.x = -1;
    all.pos.down_left.y = 1;
    return (all);
}

void init_pos_text(all_t all)
{
    set_pos_text(all.tx.nb_music, 1750, 390); 
    set_pos_text(all.tx.nb_sound, 1750, 590);
    set_pos_text(all.tx.nb_fps, 30, 790);
    set_pos_text(all.tx.music, 1300, 300);
    set_pos_text(all.tx.sound, 1150, 500);
    set_pos_text(all.tx.fps, 400, 700);
    set_pos_text(all.tx.windowed, 270, 320);
    set_pos_text(all.tx.fullscreen, 230, 520);
    set_pos_text(all.tx.choose, 500, 140);
}
