/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** m
*/

#include <SFML/Window.h>
#include <SFML/Config.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Sensor.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <SFML/System/Time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio.h>

typedef struct texture_s texture_t;
struct texture_s {
};

typedef struct counter_s counter_t;
struct counter_s {
};

typedef struct rect_s rect_t;
struct rect_s {
};

typedef struct text_s text_t;
struct text_s {
};

typedef struct clocks_s clocks_t;
struct clocks_s {
};

typedef struct music_s music_t;
struct music_s {
};

typedef struct str_s str_t;
struct str_s {
};

typedef struct all_s all_t;
struct all_s {
    sfRenderWindow *window;
    sfEvent event;
    str_t str;
    texture_t tex;
    clocks_t cl;
    counter_t cn;
    text_t tx;
    rect_t re;
    music_t mu;
};

sfSprite *create_sprite(sfSprite *sprite, char *file);
sfRenderWindow *set_win(char *title, int fps, int fullscreen);
all_t init(all_t all);
void init_pos(all_t all);
all_t init_tex(all_t all);
all_t init_counter(all_t all);
all_t init_text(all_t all);
all_t init_rect(all_t all);
all_t init_clock(all_t all);
all_t init_music(all_t all);
void set_pos(sfSprite *sprite, int x, int y);
all_t analyse_event(all_t all);
all_t close_window(all_t all);
int check_click(sfSprite *sprite, int x, int y, all_t all);
sfText *create_text(sfText *text, int size, char *str);
void set_pos_text(sfText *text, int x, int y);
sfIntRect create_rect(sfIntRect rect, int width, int height);
all_t set_fps(all_t all);
all_t set_window(all_t all);
char *read_high_score(all_t all);
char *write_high_score(char *buffer, all_t all);
