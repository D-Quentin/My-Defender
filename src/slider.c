/*
** EPITECH PROJECT, 2020
** slider
** File description:
** m
*/

#include "my.h"

all_t gest_slider(all_t all, sfSprite *sprite, int x, int nb)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all.window);
    int move = 0;
    sfVector2f new_pos;

    if (check_click(sprite, 52, 100, all) == 1) {
        while (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            if (sfMouse_getPositionRenderWindow(all.window).x > x &&
                sfMouse_getPositionRenderWindow(all.window).x < x + 618) {
                move = sfMouse_getPositionRenderWindow(all.window).x - mouse.x;
                mouse = sfMouse_getPositionRenderWindow(all.window);
                new_pos.x = move;
                new_pos.y = 0;
                sfSprite_move(sprite, new_pos);
            }
            all = volume_music(all, nb);
            all = set_textfps(all, nb);
            display_setting(all);
        }
    }
    return (all);
}

all_t set_textfps(all_t all, int nb)
{
    if (nb == 2)
    {
        nb = sfSprite_getPosition(all.tex.slid2[2]).x - 160;
        nb = (nb * 144) / 580;
        if (nb <= 10)
            sfText_setString(all.tx.nb_fps, "10");
        else if (nb >= 144)
            sfText_setString(all.tx.nb_fps, "144");
        else
            sfText_setString(all.tx.nb_fps, my_itoa(nb));
        if (nb <= 10)
            sfRenderWindow_setFramerateLimit(all.window, 10);
        else
            sfRenderWindow_setFramerateLimit(all.window, nb);
    }
    return (all);
}

all_t volume_music(all_t all, int nb)
{
    if (nb == 0) {
        nb = sfSprite_getPosition(all.tex.slid2[0]).x - 1082;
        nb = (nb * 100) / 580;
        if (nb <= 0) {
            sfText_setString(all.tx.nb_music, "0%");
            sfMusic_setVolume(all.mu.music, 0);
        } else if (nb >= 100) {
            sfText_setString(all.tx.nb_music, "100%");
            sfMusic_setVolume(all.mu.music, 100);
        } else {
            sfText_setString(all.tx.nb_music, my_strcat(my_itoa(nb), "%"));
            sfMusic_setVolume(all.mu.music, nb);
        }
    } else if (nb == 1) {
        nb = sfSprite_getPosition(all.tex.slid2[1]).x - 1082;
        nb = (nb * 100) / 580;
        if (nb <= 0) {
            sfText_setString(all.tx.nb_sound, "0%");
            sfMusic_setVolume(all.mu.shoot, 0);
            sfMusic_setVolume(all.mu.upgrade, 0);
        } else if (nb >= 100) {
            sfText_setString(all.tx.nb_sound, "100%");
            sfMusic_setVolume(all.mu.shoot, 100);
            sfMusic_setVolume(all.mu.upgrade, 100);
        } else {
            sfText_setString(all.tx.nb_sound, my_strcat(my_itoa(nb), "%"));
            sfMusic_setVolume(all.mu.shoot, nb);
            sfMusic_setVolume(all.mu.upgrade, nb);
        }
    }
    return (all);
}