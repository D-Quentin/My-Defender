/*
** EPITECH PROJECT, 2020
** init_pos
** File description:
** m
*/

#include "my.h"

void init_pos(all_t all)
{
    set_pos(all.tex.play, 730, 820);
    set_pos(all.tex.setting, 30, 840);
    set_pos(all.tex.lboard, 30, 950);
    set_pos(all.tex.htp_icon, 30, 730);
    set_pos(all.tex.tower_icon, 30, 620);
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
    init_pos2(all);
    init_pos3(all);
}

void init_pos2(all_t all)
{
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
    set_pos(all.tex.cache, 2000, 2000);
    set_pos(all.tex.up1_1, 2000, 2000);
    set_pos(all.tex.up1_2, 2000, 2000);
    set_pos(all.tex.up2_1, 2000, 2000);
    set_pos(all.tex.up2_2, 2000, 2000);
    set_pos(all.tex.up3_1, 2000, 2000);
    set_pos(all.tex.up3_2, 2000, 2000);
}

void init_pos3(all_t all)
{
    set_pos(all.tex.up4_1, 2000, 2000);
    set_pos(all.tex.desc1, 2000, 2000);
    set_pos(all.tex.desc2, 2000, 2000);
    set_pos(all.tex.desc3, 2000, 2000);
    set_pos(all.tex.desc4, 2000, 2000);
    set_pos(all.tex.sablier, 10000, 900);
    set_pos(all.tex.acceuil, 620, 600);
    set_pos(all.tex.restart, 800, 600);
    set_pos(all.tex.trophe, 980, 600);
    set_pos(all.tex.exitt, 1160, 600);
    set_pos(all.tex.pause, 510, 370);
    set_pos(all.tex.pic[0], 1615, 995);
    set_pos(all.tex.pic[1], 2000, 2000);
    set_pos(all.tex.luffy, 941, 540);
}

all_t init_posi(all_t all)
{
    all.pos.b.x = 340;
    all.pos.b.y = 480;
    all.pos.up.x = 0;
    all.pos.up.y = -1;
    all.pos.right.x = 1;
    all.pos.right.y = 0;
    all.pos.left.x = -1;
    all.pos.left.y = 0;
    all.pos.down.y = 1;
    all.pos.down.x = 0;
    all = init_posi2(all);
    return (all);
}

all_t init_posi2(all_t all)
{
    all.pos.up_right.x = 1;
    all.pos.up_right.y = -1;
    all.pos.up_left.x = -1;
    all.pos.up_left.y = -1;
    all.pos.down_right.x = 1;
    all.pos.down_right.y = 1;
    all.pos.down_left.x = -1;
    all.pos.down_left.y = 1;
    all.pos.scale.x = 1.1;
    all.pos.scale.y = 1.1;
    all.pos.rescale.x = 1;
    all.pos.rescale.y = 1;
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
    set_pos_text(all.tx.life, 1710, 5);
    set_pos_text(all.tx.money, 1710, 100);
    set_pos_text(all.tx.waves, 520, 0);
    set_pos_text(all.tx.print_waves, 320, 0);
    set_pos_text(all.tx.pause, 710, 350);
}