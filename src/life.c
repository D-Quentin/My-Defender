/*
** EPITECH PROJECT, 2020
** life
** File description:
** life
*/

#include "my.h"

all_t gest_life(all_t all, sfSprite *sprite, int i)
{
    char *life = malloc(sizeof(char) * 4);

    if (all.str.line[i] == '1' && all.pos.ballon.x >= 1490) {
        all.cn.life = all.cn.life - 1;
        set_pos(sprite, 20, 20);
    }
    if (all.str.line[i] == '2' && all.pos.ballon.x >= 1490) {
        all.cn.life = all.cn.life - 2;
        set_pos(sprite, 20, 20);
    }
    if (all.str.line[i] == '3' && all.pos.ballon.x >= 1490) {
        all.cn.life = all.cn.life - 3;
        set_pos(sprite, 20, 20);
    }
    if (all.str.line[i] == '4' && all.pos.ballon.x >= 1490) {
        all.cn.life = all.cn.life - 4;
        set_pos(sprite, 20, 20);
    }
    if (all.str.line[i] == '5' && all.pos.ballon.x >= 1490) {
        all.cn.life = all.cn.life - 5;
        set_pos(sprite, 20, 20);
    }
    if (all.cn.life < 0)
        all.cn.life = 0;
    return (all);
}

all_t gest_life2(all_t all, sfSprite *sprite, int i)
{
    char *life = malloc(sizeof(char) * 4);

    if (all.str.line[i] == '1' && all.pos.ballon.y <= 36) {
        all.cn.life = all.cn.life - 1;
        set_pos(sprite, 20, 40);
    }
    if (all.str.line[i] == '2' && all.pos.ballon.y <= 36) {
        all.cn.life = all.cn.life - 2;
        set_pos(sprite, 20, 40);
    }
    if (all.str.line[i] == '3' && all.pos.ballon.y <= 36) {
        all.cn.life = all.cn.life - 3;
        set_pos(sprite, 20, 40);
    }
    if (all.str.line[i] == '4' && all.pos.ballon.y <= 36) {
        all.cn.life = all.cn.life - 4;
        set_pos(sprite, 20, 40);
    }
    if (all.str.line[i] == '5' && all.pos.ballon.y <= 36) {
        all.cn.life = all.cn.life - 5;
        set_pos(sprite, 20, 40);
    }
    if (all.cn.life < 0)
        all.cn.life = 0;
    return (all);
}