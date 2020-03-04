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

char **str_to_chartab(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **map = malloc(sizeof(char*) * 100000);

    while (str[i] != '\0') {
        map[j] = malloc(sizeof(char) * 100000);
        while (str[i] != '\n') {
            map[j][k] = str[i];
            i++;
            k++;
        }
        map[j][k] = str[i];
        map[j][k + 1] = '\0';
        k = 0;
        i++;
        j++;
    }
    return map;
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

all_t first_path12(all_t all)
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
                all.pos.ballon.y > 200)
                sfSprite_move(all.tex.tab_sprite[i], all.pos.up);
            else if (all.pos.ballon.x >= 690 && all.pos.ballon.y < 416 &&
                     all.pos.ballon.x < 1400 || all.pos.ballon.x >= 925 &&
                     all.pos.ballon.y < 636 && all.pos.ballon.x < 1400 ||
                     all.pos.ballon.x >= 1205 && all.pos.ballon.y < 876 &&
                     all.pos.ballon.x < 1400)
                sfSprite_move(all.tex.tab_sprite[i], all.pos.down);
            else
                sfSprite_move(all.tex.tab_sprite[i], all.pos.right);
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
    
    if (i == 0) {
        all.tex.tab_sprite = malloc(sizeof(sfSprite *) * 10000);
        all.cn.line = compt_bal(all.str.tab_waves[0]);
    }
    while (i != all.cn.line) {
        if (all.str.tab_waves[0][i] == '1')
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl1.png");
        if (all.str.tab_waves[0][i] == '2')
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl2.png");
        if (all.str.tab_waves[0][i] == '3')
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl3.png");
        if (all.str.tab_waves[0][i] == '4')
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl4.png");
        if (all.str.tab_waves[0][i] == '5')
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl5.png");
        set_pos(all.tex.tab_sprite[i], 350, 870);            
        i++;
    }
    all = first_path12(all);
    return all;
}

all_t init_waves(all_t all)
{
    char *waves = read_fonction("src/create_waves.txt");
    all.str.tab_waves = str_to_chartab(waves);
    all = create_sprite_tab(all);
    return (all);
}
