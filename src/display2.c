/*
** EPITECH PROJECT, 2020
** display2
** File description:
** m
*/

#include "my.h"

void display_life(all_t all)
{
    char *life;

    if (all.cn.life == 0)
        life = "0";
    else
        life = my_itoa(all.cn.life);
    sfText_setString(all.tx.life, life);
    sfRenderWindow_drawText(all.window, all.tx.life, NULL);
}

void display_money(all_t all)
{
    char *money;

    if (all.cn.money == 0)
        money = "0";
    else
        money = my_itoa(all.cn.money);
    sfText_setString(all.tx.money, money);
    sfRenderWindow_drawText(all.window, all.tx.money, NULL);
}

void display_waves(all_t all)
{
    char *waves = malloc(sizeof(char) * 10);

    waves = my_itoa(all.cn.number_waves);
    sfText_setString(all.tx.waves, waves);
    sfRenderWindow_drawText(all.window, all.tx.waves, NULL);
}
void display_endscreen(all_t all)
{
    sfIntRect rect = {0, 0, 1920, 1080};

    if (all.cn.life == 0) {
        sfSprite_setTextureRect(all.tex.cache, rect);
        set_pos(all.tex.cache, 0, 0);
        sfRenderWindow_drawSprite(all.window, all.tex.cache, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.lose, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.restart, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.exitt, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.acceuil, NULL);
        sfRenderWindow_drawSprite(all.window, all.tex.trophe, NULL);
    }
}
void display_shoot(all_t all)
{
    int i = 0;

    while (i != 100) {
        if (all.str.nb_dart[i] == '1') {
            sfRenderWindow_drawSprite(all.window, all.tex.dart[i], NULL);
        }
         if (all.str.nb_shuriken[i] == '1') {
            sfRenderWindow_drawSprite(all.window, all.tex.shuriken[i], NULL);
        }
         if (all.str.nb_fireball[i] == '1') {
            sfRenderWindow_drawSprite(all.window, all.tex.fireball[i], NULL);
        }
         if (all.str.nb_laser[i] == '1') {
            sfRenderWindow_drawSprite(all.window, all.tex.laser[i], NULL);
        }
        i++;
    }
}