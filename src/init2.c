/*
** EPITECH PROJECT, 2020
** init2
** File description:
** m
*/

#include "my.h"

all_t init_text(all_t all)
{
    all.tx.nb_music = create_text(all.tx.nb_music, 80, "100%");
    all.tx.nb_sound = create_text(all.tx.nb_sound, 80, "100%");
    all.tx.nb_fps = create_text(all.tx.nb_sound, 80, "144");
    all.tx.music = create_text(all.tx.music, 80, "MUSIC");
    all.tx.sound = create_text(all.tx.sound, 80, "SOUND EFFECT");
    all.tx.fps = create_text(all.tx.fps, 80, "FPS");
    all.tx.windowed = create_text(all.tx.windowed, 80, "WINDOWED");
    all.tx.fullscreen = create_text(all.tx.fullscreen, 80, "FULLSCREEN");
    all.tx.choose = create_text(all.tx.choose, 120, "CHOOSE YOUR MAP");
    all.tx.life = create_text(all.tx.life, 85, "150");
    all.tx.money = create_text(all.tx.money, 85, "150");
    all.tx.waves = create_text(all.tx.money, 85, "1");
    all.tx.print_waves = create_text(all.tx.print_waves, 85, "WAVE ");
    all.tx.pause = create_text(all.tx.pause, 180, "PAUSE");
    return (all);
}

all_t init_rect(all_t all)
{
}

all_t init_clock(all_t all)
{
    int i = 0;

    all.cl.map = sfClock_create();
    all.cl.d = sfClock_create();
    all.cl.sablier = sfClock_create();
    all.cl.luffy = sfClock_create();
    while (i != 100) {
        all.cl.dart[i] = sfClock_create();
        all.cl.shuriken[i] = sfClock_create();
        all.cl.fireball[i] = sfClock_create();
        all.cl.laser[i] = sfClock_create();
        i++;
    }
    return (all);
}

all_t init_music(all_t all)
{
    all.mu.music = sfMusic_createFromFile("files/background_music.ogg");
    all.mu.shoot = sfMusic_createFromFile("files/pop1.wav");
    all.mu.upgrade = sfMusic_createFromFile("files/upgrade.ogg");
    return all;
}