/*
** EPITECH PROJECT, 2020
** wave
** File description:
** wave
*/

#include "my.h"

char **str_to_chartab(char *str)
{
    int i = 0, j = 0, k = 0;
    char **map = malloc(sizeof(char *) * 12000);

    while (str[i] != '\0') {
        map[j] = malloc(sizeof(char) * 20000);
        while (str[i] != '\n' && str[i] != '\0') {
            map[j][k] = str[i];
            i++;
            k++;
        }
        map[j][k] = '\0';
        if (str[i - 1] == '\0')
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
        all = gest_life(all, all.tex.tab[i], i);
        i++;
    }
    return all;
}

all_t wait(all_t all)
{
    static int mpol = 0;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.sablier)) >
        all.cn.waiting_time) {
        mpol++;
        if (mpol == 5) {
            mpol = 0;
            all.cn.waiting = 2;
            return all;
        }
        sfClock_restart(all.cl.sablier);
    }
    return all;
}

all_t find_path_map1(all_t all)
{
    int i = 0;
    int b = all.cn.reset_map_v;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.map)) > 1) {
        if (all.cn.line != 1 && b != all.cn.line - 1) {
            all.pos.ballon = sfSprite_getPosition(all.tex.tab[b]);
            all = wait(all);
            if (all.cn.waiting == 2) {
                all.cn.waiting = 0;
                all.cn.max++;
                b++;
            }
        }
        all.cn.reset_map_v = b;
        all = find_path_map1_second_part(all, i);
        sfClock_restart(all.cl.map);
    }
    if (check_end_round(all) == 1)
        all = next_wave(all);
    return (all);
}

all_t init_waves(all_t all)
{
    static int i = 0;
    char *map;

    if (i == 0) {
        all = max_waves(read_fonction("src/create_waves.txt"), all);
        map = read_map("src/map1.txt");
        all.str.map1 = str_to_chartab(map);
        i++;
    }
    all = create_sprite_tab(all);
    return (all);
}
