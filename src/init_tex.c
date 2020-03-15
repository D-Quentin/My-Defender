/*
** EPITECH PROJECT, 2020
** init_tex
** File description:
** m
*/

#include "my.h"

all_t init_tex(all_t all)
{
    all.tex.title = create_sprite(all.tex.title, "files/title.png");
    all.tex.play = create_sprite(all.tex.play, "files/play.png");
    all.tex.b1 = create_sprite(all.tex.b1, "files/b1.png");
    all.tex.b2 = create_sprite(all.tex.b2, "files/b2.png");
    all.tex.b3 = create_sprite(all.tex.b3, "files/b3.png");
    all.tex.b4 = create_sprite(all.tex.b4, "files/b4.png");
    all.tex.b5 = create_sprite(all.tex.b5, "files/b5.png");
    all.tex.map1 = create_sprite(all.tex.map1, "files/map1.png");
    all.tex.map2 = create_sprite(all.tex.map2, "files/map2.png");
    all.tex.setting = create_sprite(all.tex.setting, "files/setting.png");
    all.tex.lboard = create_sprite(all.tex.lboard, "files/lboard.png");
    all.tex.exit = create_sprite(all.tex.exit, "files/exit.png");
    all.tex.home = create_sprite(all.tex.home, "files/home.png");
    all.tex.back = create_sprite(all.tex.back, "files/back.png");
    all = init_tex3(all);
    return (all);
}

all_t init_tex3(all_t all)
{
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
    all.tex.pic[0] = create_sprite(all.tex.pic[0], "files/pic.png");
    all.tex.pic[1] = create_sprite(all.tex.pic[1], "files/pic.png");
    all.tex.p1 = create_sprite(all.tex.p1, "files/p1.png");
    all.tex.p2 = create_sprite(all.tex.p2, "files/p2.png");
    all.tex.p3 = create_sprite(all.tex.p3, "files/p3.png");
    all.tex.p4 = create_sprite(all.tex.p4, "files/p4.png");
    all.tex.fullmap1 = create_sprite(all.tex.fullmap1, "files/fullmap1.png");
    all.tex.fullmap1bis = create_sprite(all.tex.fullmap1bis, "files/m1b.png");
    all.tex.fullmap2 = create_sprite(all.tex.fullmap2, "files/fullmap2.png");
    all.tex.fullmap2bis = create_sprite(all.tex.fullmap2bis, "files/m2b.png");
    all.tex.c_green = create_sprite(all.tex.c_green, "files/c_green.png");
    all = init_tex4(all);
    all = init_tex5(all);
    return (all);
}

all_t init_tex4(all_t all)
{
    all.tex.c_red = create_sprite(all.tex.c_red, "files/c_red.png");
    all.tex.cache = create_sprite(all.tex.cache, "files/cache.png");
    all.tex.desc1 = create_sprite(all.tex.desc1, "files/desc1.png");
    all.tex.desc2 = create_sprite(all.tex.desc2, "files/desc2.png");
    all.tex.desc3 = create_sprite(all.tex.desc3, "files/desc3.png");
    all.tex.desc4 = create_sprite(all.tex.desc4, "files/desc4.png");
    all.tex.up1_1 = create_sprite(all.tex.up1_1, "files/up1_1.png");
    all.tex.up1_2 = create_sprite(all.tex.up1_2, "files/up1_2.png");
    all.tex.up2_1 = create_sprite(all.tex.up2_1, "files/up2_1.png");
    all.tex.up2_2 = create_sprite(all.tex.up2_2, "files/up2_2.png");
    all.tex.up3_1 = create_sprite(all.tex.up3_1, "files/up3_1.png");
    all.tex.up3_2 = create_sprite(all.tex.up3_2, "files/up3_2.png");
    all.tex.up4_1 = create_sprite(all.tex.up4_1, "files/up4_1.png");
    all.tex.sablier = create_sprite(all.tex.sablier, "files/sablier.png");
    all.tex.restart = create_sprite(all.tex.restart, "files/restart.png");
    all.tex.exitt = create_sprite(all.tex.exitt, "files/exitt.png");
    return (all);
}

all_t init_tex5(all_t all)
{
    all.tex.acceuil = create_sprite(all.tex.acceuil, "files/acceuil.png");
    all.tex.trophe = create_sprite(all.tex.trophe, "files/trophé.png");
    all.tex.lose = create_sprite(all.tex.lose, "files/defaite.png");
    all.tex.pause = create_sprite(all.tex.pause, "files/pause.png");
    all.tex.highscore = create_sprite(all.tex.highscore, "files/hs.png");
    all.tex.htp_icon = create_sprite(all.tex.htp_icon, "files/htp_icon.png");
    all.tex.htp = create_sprite(all.tex.htp, "files/htp.png");
    all.tex.list_tower = create_sprite(all.tex.list_tower, "files/lt.png");
    all.tex.tower_icon = create_sprite(all.tex.tower_icon, "files/ti.png");
    all.tex.luffy = create_sprite(all.tex.luffy, "files/luffy.png");
    return (all);
}