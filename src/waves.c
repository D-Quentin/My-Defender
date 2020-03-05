/*
** EPITECH PROJECT, 2020
** waves
** File description:
** waves
*/

#include "my.h"

all_t find_path_map1(all_t all, float *spd);

char *read_fonction(char *file)
{
    int fd = open(file, O_RDONLY);
    int size = 6;
    char *buffer = NULL;
    
    buffer = malloc(sizeof(char) * size);
    read(fd, buffer, size);
    size = my_getnbr(buffer);
    buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    buffer[size] = '\0';
    return (buffer);
}

char *read_map(char *file)
{
    int size = 21000;
    char *buffer = malloc(sizeof(int) * size);
    int fd = open(file, O_RDONLY);
    
    read(fd, buffer, size);
    return (buffer);
}

int compt_bal(char *str)
{
    int i = 0;
    
    while (str[i] >= '1' && str[i] <= '5')
        i++;
    return i;
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
            spd[i] = 1;
        }
        if (all.str.line[i] == '3') {
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl3.png");
            spd[i] = 1;
        }
        if (all.str.line[i] == '4') {
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl4.png");
            spd[i] = 3;
        }
        if (all.str.line[i] == '5') {
            all.tex.tab_sprite[i] = create_sprite(all.tex.tab_sprite[i], "files/bal_lvl5.png");
            spd[i] = 2;
        }
        set_pos(all.tex.tab_sprite[i], 350, 870);            
        i++;
    }
    all = find_path_map1(all, spd);
    return all;
}

char *split_line(char *str)
{
    int i = 0;
    char *new_line = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str[i] != '\n' && str[i] != '\0') {
        new_line[i] = str[i];
        i++;
    }
    return new_line;
}

char **str_to_chartab(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **map = malloc(sizeof(char *) * 120);

    while (str[i] != '\0') {
        map[j] = malloc(sizeof(char) * 200);
        while (str[i] != '\n' && str[i] != '\0') {
            map[j][k] = str[i];
            i++;
            k++;
        }
        map[j][k] = '\n';
        map[j][k + 1] = '\0';
        if (str[i] == '\0')
            return map;
        k = 0;
        i++;
        j++;
    }
    return map;
}

all_t find_path_map1(all_t all, float *spd)
{
    static int v = 0;
    static int w = 1;
    static int i = 0;
    
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
            all.cn.road_x = all.pos.ballon.x / 10;
            all.cn.road_y = all.pos.ballon.y / 10;
            all.cn.road_y = all.cn.road_y - 1;
            my_put_nbr(all.cn.road_x);
            my_put_nbr(all.cn.road_y);
            if (all.str.map1[all.cn.road_y - 1][all.cn.road_x] == 'H') {
                all.pos.up.y = -spd[i];
                my_putchar('a');
                sfSprite_move(all.tex.tab_sprite[i], all.pos.up);
            }
            if (all.str.map1[all.cn.road_y + 1][all.cn.road_x] == 'S') {
                all.pos.down.y = spd[i];
                my_putchar('b');
                sfSprite_move(all.tex.tab_sprite[i], all.pos.down);
            }
            if (all.str.map1[all.cn.road_y][all.cn.road_x + 1] == 'X') {
                all.pos.right.x = spd[i];
                my_putchar('c');
                sfSprite_move(all.tex.tab_sprite[i], all.pos.right);
            }
            all = gest_life(all, spd[i]);
            i++;
        }
        i = 0;
        sfClock_restart(all.cl.map);
    }
    return (all);
}

all_t find_start_map(all_t all)
{
    int j = 0;
    int k = 0;

    while (k != 95 && j != 51) {
        while (j != 51) {
            if (all.str.map1[j][k] == 'X') {
                k++;
                j++;
                all.cn.road_x = k;
                all.cn.road_y = j;
                return (all);
            }
            j++;
        }
        j = 0;
        k++;
    }
}

all_t init_waves(all_t all)
{
    static int i = 0;
    char *map;

    if (i == 0) {
        map = read_map("src/map1.txt");
        all.str.map1 = str_to_chartab(map);
        all = find_start_map(all);
        i++;
    }
    all = create_sprite_tab(all);
    return (all);
}
