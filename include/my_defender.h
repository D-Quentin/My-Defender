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
    sfSprite *title;
    sfSprite *back;
    sfSprite *play;
    sfSprite *bal_lvl1;
    sfSprite *bal_lvl2;
    sfSprite *bal_lvl3;
    sfSprite *bal_lvl4;
    sfSprite *bal_lvl5;
    sfSprite **case1;
    sfSprite **case2;
    sfSprite **case3;
    sfSprite **case4;
    sfSprite **case5;
    sfSprite *map1;
    sfSprite *map2;
    sfSprite *fullmap1;
    sfSprite *fullmap2;
    sfSprite *fullmap1bis;
    sfSprite *fullmap2bis;
    sfSprite *p1_lvl0;
    sfSprite *p1_lvl1;
    sfSprite *p1_lvl2;
    sfSprite *p2_lvl0;
    sfSprite *p2_lvl1;
    sfSprite *p2_lvl2;
    sfSprite *p3_lvl0;
    sfSprite *p3_lvl1;
    sfSprite *p3_lvl2;
    sfSprite *p4_lvl0;
    sfSprite *p4_lvl1;
    sfSprite *setting;
    sfSprite *lboard;
    sfSprite *exit;
    sfSprite *home;
    sfSprite **slid;
    sfSprite **slid2;
    sfSprite **hud;
    sfSprite *arrow;
    sfSprite *fond3;
};

typedef struct counter_s counter_t;
struct counter_s {
    int title;
    int setting;
    int scoreboard;
    int play;
    int music;
    int sound;
    int fps;
    int window;
};

typedef struct rect_s rect_t;
struct rect_s {
};

typedef struct text_s text_t;
struct text_s {
    sfText *nb_music;
    sfText *nb_sound;
    sfText *nb_fps;
    sfText *music;
    sfText *sound;
    sfText *fps;
    sfText *windowed;
    sfText *fullscreen;
};

typedef struct clocks_s clocks_t;
struct clocks_s {
    sfClock *map;
};

typedef struct music_s music_t;
struct music_s {
};

typedef struct str_s str_t;
struct str_s {
};

typedef struct pos_s pos_t;
struct pos_s {
    sfVector2f b;
    sfVector2f ballon;
    sfVector2f right;
    sfVector2f down;
    sfVector2f up;
    sfVector2f pb;
    sfVector2f up_right;
    sfVector2f down_right;
    sfVector2f down_left;
    sfVector2f up_left;
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
    pos_t pos;
};

sfSprite *create_sprite(sfSprite *sprite, char *file);
sfRenderWindow *set_win(char *title, int fps, int fullscreen);
all_t init(all_t all);
void init_pos(all_t all);
all_t init_tex(all_t all);
all_t init_tex2(all_t all);
all_t init_counter(all_t all);
all_t init_text(all_t all);
all_t init_rect(all_t all);
all_t init_clock(all_t all);
all_t init_music(all_t all);
all_t init_posi(all_t all);
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
all_t setting(all_t all);
all_t title(all_t all);
void display_title(all_t all);
all_t analyse_event(all_t all);
all_t close_window(all_t all);
all_t init_malloc(all_t all);
void display_setting(all_t all);
all_t gest_slider(all_t all, sfSprite *sprite, int x, int nb);
void init_pos_text(all_t all);
all_t volume_music(all_t all, int nb);
all_t set_textfps(all_t all, int nb);
all_t first_path(all_t all);
void display_map1(all_t all);
void display_map2(all_t all);
all_t second_path(all_t all);
