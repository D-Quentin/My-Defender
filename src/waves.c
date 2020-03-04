/*
** EPITECH PROJECT, 2020
** waves
** File description:
** waves
*/

#include "my.h"

char *read_fonction(char *file)
{
    int size = 10000;
    char *buffer = malloc(sizeof(char) * 1000);
    read(open(file, O_RDONLY), buffer, size);
    return (buffer);
}

int compt_bal(char *str)
{
    int i = 0;
    
    while (str[i] != '\0')
        i++;
    if (str[i - 2] == '\n')
        i = i - 2;
    else
        i = i - 1;    
    return i;
}

all_t first_path12(all_t all, float *spd)
{
    static int i = 0;
    static int w = 1;
    static int v = 0;
    display_bl(all);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.map)) > 1) {
        if (all.cn.line != 1 && v != all.cn.line - 1) {
            all.pos.ballon = sfSprite_getPosition(all.tex.tab_sprite[v]);
            if (all.pos.ballon.x > 390) {
                w++;
                v++;
            }
        }
        while (i != w) {
            all.pos.ballon = sfSprite_getPosition(all.tex.tab_sprite[i]);
            if (all.pos.ballon.x > 455 && all.pos.ballon.y > 200 &&
                all.pos.ballon.x < 690 || all.pos.ballon.x > 1425 &&
                all.pos.ballon.y > 200) {
                all.pos.up.y = -spd[i];
                sfSprite_move(all.tex.tab_sprite[i], all.pos.up);
            }
            else if (all.pos.ballon.x >= 690 && all.pos.ballon.y < 416 &&
                     all.pos.ballon.x < 1400 || all.pos.ballon.x >= 925 &&
                     all.pos.ballon.y < 636 && all.pos.ballon.x < 1400 ||
                     all.pos.ballon.x >= 1205 && all.pos.ballon.y < 876 &&
                     all.pos.ballon.x < 1400) {
                all.pos.down.y = spd[i];
                sfSprite_move(all.tex.tab_sprite[i], all.pos.down);
            }
            else {
                all.pos.right.x = spd[i];
                sfSprite_move(all.tex.tab_sprite[i], all.pos.right);
            }
            i++;
        }
        i = 0;
        sfClock_restart(all.cl.map);
    }
    return (all);
}

all_t create_sprite_tab(all_t all)
{
    static int i = 0;
    static float *spd;

    if (i == 0) {
        spd = malloc(sizeof(int) *1000);
        all.cn.line = compt_bal(all.str.line);
        all.tex.tab_sprite = malloc(sizeof(sfSprite *) * 10000);
    }
    while (i != all.cn.line) {
        if (all.str.line[i] == '1') {
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl1.png");
            spd[i] = 1;
        }
        if (all.str.line[i] == '2') {
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl2.png");
            spd[i] = 1.3;
        }
        if (all.str.line[i] == '3') {
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl3.png");
            spd[i] = 1.5;
        }
        if (all.str.line[i] == '4') {
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl4.png");
            spd[i] = 2;
        }
        if (all.str.line[i] == '5') {
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl5.png");
            spd[i] = 1.6;
        }
        set_pos(all.tex.tab_sprite[i], 350, 870);            
        i++;
    }
    all = first_path12(all, spd);
    return all;
}

char *split_line(char *str)
{
    int i = 0;
    int c = 0;
    char *new_line;

    while (str[i] != '\n' && str[i] != '\0')
        i++;
    new_line = malloc(sizeof(char *) * i);
    while (c != i) {
        new_line[c] = str[c];
        c++;
    }
    return new_line;
}

all_t init_waves(all_t all)
{
    char *waves = read_fonction("src/create_waves.txt");
    all.str.line = split_line(waves);
    all = create_sprite_tab(all);
    return (all);
}
