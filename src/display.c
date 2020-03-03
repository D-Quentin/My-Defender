/*
** EPITECH PROJECT, 2020
** display
** File description:
** m
*/

#include "my.h"

void display_play(all_t all)
{
//    sfRenderWindow_clear(all.window, sfBlack);
    /*
    if (all.cn.map == 1) {
        sfRenderWindow_drawSprite(all.window, all.tex.fullmap1bis, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.fullmap1, NULL);
    } else {
        sfRenderWindow_drawSprite(all.window, all.tex.fullmap2bis, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.fullmap2, NULL);
    }
    sfRenderWindow_drawSprite(all.window, all.tex.bal_lvl1, NULL);
    */
    //  sfRenderWindow_display(all.window);
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
