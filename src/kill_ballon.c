/*
** EPITECH PROJECT, 2020
** kill_ballon
** File description:
** m
*/

#include "my.h"

all_t kill_ballon(all_t all, int i , int range)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.tab[i]);

    if (all.str.line[i] == '1' || (all.str.line[i] == '2' && (range == 253 ||
        range == 235 || range == 236 || range == 336 || range == 420 ||
        range == 337 || range == 504)) || (all.str.line[i] == '3' &&
        (range == 337 || range == 504))) {
        set_pos(all.tex.tab[i], 20, 20);
        all.cn.money += 1;
        sound_shoot(all);
        return (all);
    }
    all = kill_ballon2(all, i , range);
    return (all);
}

all_t kill_ballon2(all_t all, int i , int range)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.tab[i]);

    if (all.str.line[i] == '2' || (all.str.line[i] == '3' && (range == 253 ||
        range == 235 || range == 236 || range == 336 || range == 420)) ||
        (all.str.line[i] == '4' && (range == 337 || range == 504))) {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b1.png");
        set_pos(all.tex.tab[i], pos.x, pos.y);
        all.cn.money += 2;
        all.str.line[i] = '1';
        all.cn.spd[i] = 1;
        sound_shoot(all);
        return (all);
    }
    all = kill_ballon3(all, i , range);
    return (all);
}

all_t kill_ballon3(all_t all, int i , int range)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.tab[i]);

    if (all.str.line[i] == '3' || (all.str.line[i] == '4' && (range == 253
        || range == 235 || range == 236 || range == 336 || range == 420))
        || (all.str.line[i] == '5' && (range == 337 || range == 504))) {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b2.png");
        set_pos(all.tex.tab[i], pos.x, pos.y);
        all.cn.money += 3;
        all.str.line[i] = '2';
        all.cn.spd[i] = 1;
        sound_shoot(all);
        return (all);
    }
    all = kill_ballon4(all, i , range);
    return (all);
}

all_t kill_ballon4(all_t all, int i , int range)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.tab[i]);

    if (all.str.line[i] == '4' || (all.str.line[i] == '5' && (range == 253
        || range == 235 || range == 236 || range == 336 || range == 420))) {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b3.png");
        set_pos(all.tex.tab[i], pos.x, pos.y);
        all.cn.money += 4;
        all.str.line[i] = '3';
        all.cn.spd[i] = 1;
        sound_shoot(all);
        return (all);
    }
    all = kill_ballon5(all, i , range);
    return (all);
}

all_t kill_ballon5(all_t all, int i , int range)
{
    sfVector2f pos = sfSprite_getPosition(all.tex.tab[i]);

    if (all.str.line[i] == '5') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b4.png");
        set_pos(all.tex.tab[i], pos.x, pos.y);
        all.cn.money += 5;
        all.str.line[i] = '4';
        all.cn.spd[i] = 3;
        sound_shoot(all);
    }
    return (all);
}