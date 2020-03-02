/*
** EPITECH PROJECT, 2020
** path
** File description:
** path
*/

#include "my.h"

all_t first_path(all_t all)
{
    display_map1(all);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.map)) > 1) {
        all.pos.ballon = sfSprite_getPosition(all.tex.bal_lvl1);
        if (all.pos.ballon.x > 455 && all.pos.ballon.y > 200 &&
            all.pos.ballon.x < 690 || all.pos.ballon.x > 1425 &&
            all.pos.ballon.y > 200)
            sfSprite_move(all.tex.bal_lvl1, all.pos.up);
        else if (all.pos.ballon.x >= 690 && all.pos.ballon.y < 416 &&
                 all.pos.ballon.x < 1400 || all.pos.ballon.x >= 925 &&
                 all.pos.ballon.y < 636 && all.pos.ballon.x < 1400 ||
                 all.pos.ballon.x >= 1205 && all.pos.ballon.y < 876 &&
                 all.pos.ballon.x < 1400)
            sfSprite_move(all.tex.bal_lvl1, all.pos.down);
        else
            sfSprite_move(all.tex.bal_lvl1, all.pos.right);
        sfClock_restart(all.cl.map);
    }
    return (all);
}

all_t second_path(all_t all)
{
    sfVector2f moove_up_right = {1, -1};
    sfVector2f moove_down_right = {1, 1};
    sfVector2f moove_down_left = {-1, 1};
    sfVector2f moove_up_left = {-1, -1};
    
    display_map2(all);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(all.cl.map)) > 1) {
        all.pos.b = sfSprite_getPosition(all.tex.bal_lvl1);
        if (all.pos.b.x < 742 && all.pos.b.x > 0 ||
            all.pos.b.x >= 1170 && all.pos.b.y > 715 ||
            all.pos.b.x >= 1169 && all.pos.b.y <= 506 &&
            all.pos.b.y > 290 || all.pos.b.y <= 75 ) {
            sfSprite_move(all.tex.bal_lvl1, moove_up_right);
            my_putchar('a');
        }
        if (all.pos.b.x >= 742 && all.pos.b.x < 950 &&
            all.pos.b.y > 20 && all.pos.b.y < 286  ||
            all.pos.b.x >= 750 && all.pos.b.x < 1170 && all.pos.b.y >= 486) {
            sfSprite_move(all.tex.bal_lvl1, moove_down_right);
            my_putchar('b');
        }
        if (all.pos.b.x <= 950 && all.pos.b.x > 745 &&
            all.pos.b.y >= 286 && all.pos.b.y < 505) {
            sfSprite_move(all.tex.bal_lvl1, moove_down_left);
            my_putchar('c');
        }
        if (all.pos.b.y <= 715 && all.pos.b.x > 1170 &&
            all.pos.b.y > 506 && all.pos.b.y > 75 ||
            all.pos.b.y <= 290 && all.pos.b.x > 1171 &&
            all.pos.b.y > 75) {
            sfSprite_move(all.tex.bal_lvl1, moove_up_left);
            my_putchar('d');
        }
        sfClock_restart(all.cl.map);
    }
    return (all);
}
