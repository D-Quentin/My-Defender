/*
** EPITECH PROJECT, 2020
** music
** File description:
** music
*/

#include "my.h"

void backgound_music(all_t all)
{
    sfMusic_play(all.mu.music);
    sfMusic_setLoop(all.mu.music, sfTrue);
}

void sound_shoot(all_t all)
{
    sfMusic_stop(all.mu.shoot);
    sfMusic_play(all.mu.shoot);
}

void sound_upgrade(all_t all)
{
    sfMusic_stop(all.mu.upgrade);
    sfMusic_play(all.mu.upgrade);
}