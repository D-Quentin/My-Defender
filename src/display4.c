/*
** EPITECH PROJECT, 2020
** display4
** File description:
** m
*/

#include "my.h"

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
    display_setting2(all);
}

void display_setting2(all_t all)
{
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