/*
** EPITECH PROJECT, 2020
** waves
** File description:
** waves
*/

#include "my.h"

all_t find_path_map1(all_t all);

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

all_t add_speed(all_t all, int i)
{
    if (all.str.line[i] == '1') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b1.png");
        all.cn.spd[i] = 1;
    }
    if (all.str.line[i] == '2') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b2.png");
        all.cn.spd[i] = 1;
    }
    if (all.str.line[i] == '3') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b3.png");
        all.cn.spd[i] = 1;
    }
    if (all.str.line[i] == '4') {
        all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b4.png");
        all.cn.spd[i] = 3;
    }
    return all;
}
all_t create_sprite_tab(all_t all)
{
    static int i = 0;

    if (i == 0) {
        all.cn.spd = malloc(sizeof(int) *1000);
        all.cn.line = compt_bal(all.str.line);
        all.tex.tab = malloc(sizeof(sfSprite *) * 10000);
    }
    while (i != all.cn.line) {
        all = add_speed(all, i);
        if (all.str.line[i] == '5') {
            all.tex.tab[i] = create_sprite(all.tex.tab[i], "files/b5.png");
            all.cn.spd[i] = 2;
        }
        set_pos(all.tex.tab[i], 350, 870);
        i++;
    }
    all = find_path_map1(all);
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
    int i = 0, j = 0, k = 0;
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
all_t find_path_map1_second_part(all_t all, int i)
{
    while (i != all.cn.max) {
        all.pos.ballon = sfSprite_getPosition(all.tex.tab[i]);
        all.cn.road_x = all.pos.ballon.x / 10;
        all.cn.road_y = (all.pos.ballon.y / 10) - 1;
        if (all.str.map1[all.cn.road_y - 1][all.cn.road_x] == 'H') {
            all.pos.up.y = -all.cn.spd[i];
            sfSprite_move(all.tex.tab[i], all.pos.up);
        }
        if (all.str.map1[all.cn.road_y + 1][all.cn.road_x] == 'S') {
            all.pos.down.y = all.cn.spd[i];
            sfSprite_move(all.tex.tab[i], all.pos.down);
        }
        if (all.str.map1[all.cn.road_y][all.cn.road_x + 1] == 'X') {
            all.pos.right.x = all.cn.spd[i];
            sfSprite_move(all.tex.tab[i], all.pos.right);
        }
        all = gest_life(all, all.cn.spd[i]);
        i++;
    }
    return all;
}
all_t find_path_map1(all_t all)
{
    static int v = 0;
    int i = 0;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.map)) > 1) {
        if (all.cn.line != 1 && v != all.cn.line - 1) {
            all.pos.ballon = sfSprite_getPosition(all.tex.tab[v]);
            if (all.pos.ballon.x > 390) {
                all.cn.max++;
                v++;
            }
        }
        all = find_path_map1_second_part(all, i);
        sfClock_restart(all.cl.map);
    }
    return (all);
}

all_t init_waves(all_t all)
{
    static int i = 0;
    char *map;

    if (i == 0) {
        map = read_map("src/map1.txt");
        all.str.map1 = str_to_chartab(map);
        i++;
    }
    all = create_sprite_tab(all);
    return (all);
}
