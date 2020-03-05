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
    sfSprite **p1_l0;
    sfSprite **p1_l1;
    sfSprite **p1_l2;
    sfSprite **p2_l0;
    sfSprite **p2_l1;
    sfSprite **p2_l2;
    sfSprite **p3_l0;
    sfSprite **p3_l1;
    sfSprite **p3_l2;
    sfSprite **p4_l0;
    sfSprite **p4_l1;
    sfSprite *setting;
    sfSprite *lboard;
    sfSprite *exit;
    sfSprite *home;
    sfSprite **slid;
    sfSprite **slid2;
    sfSprite **hud;
    sfSprite *arrow;
    sfSprite *fond3;
    sfSprite **hud2;
    sfSprite *p1;
    sfSprite *p2;
    sfSprite *p3;
    sfSprite *p4;
    sfSprite *c_red;
    sfSprite *c_green;
    sfSprite **tab_sprite;
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
    int map;
    int tower;
    int money;
    int nb_t;
    int nb_t1;
    int nb_t2;
    int nb_t3;
    int nb_t4;
    int place_bl;
    int line;
    int life;
    int road_x;
    int road_y;
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
    sfText *choose;
    sfText *life;
    sfText *money;
};

typedef struct clocks_s clocks_t;
struct clocks_s {
    sfClock *map;
    sfClock *d;
};

typedef struct music_s music_t;
struct music_s {
};

typedef struct str_s str_t;
struct str_s {
    char **tab_waves;
    char *line;
    char **map1;
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
    sfVector2i *tower;
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
all_t choose_map(all_t all);
void display_choose_map(all_t all);
all_t play(all_t all);
all_t second_path_end(all_t all);
void display_play(all_t all);
all_t init_waves(all_t all);
all_t gest_drag(all_t all);
all_t click_p(all_t all);
all_t drag1(all_t all, sfVector2i mouse);
all_t drag2(all_t all, sfVector2i mouse);
all_t drag3(all_t all, sfVector2i mouse);
all_t drag4(all_t all, sfVector2i mouse);
int check_place(all_t all, sfVector2i mouse);
all_t set_tower1(all_t all, sfVector2i mouse);
all_t set_tower2(all_t all, sfVector2i mouse);
all_t set_tower3(all_t all, sfVector2i mouse);
all_t set_tower4(all_t all, sfVector2i mouse);
void display_tower(all_t all);
all_t set_pos_drag(all_t all, sfVector2i mouse);
void display_bl(all_t all);
all_t gest_life(all_t all, int spd);
void display_life(all_t all);
char *split_line(char *str);
char *read_fonction(char *file);
void display_money(all_t all);
