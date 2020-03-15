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
    sfSprite *b1;
    sfSprite *b2;
    sfSprite *b3;
    sfSprite *b4;
    sfSprite *b5;
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
    sfSprite **tab;
    sfSprite *cache;
    sfSprite **dart;
    sfSprite **laser;
    sfSprite **fireball;
    sfSprite **shuriken;
    sfSprite **pic;
    sfSprite *up1_1;
    sfSprite *up1_2;
    sfSprite *up2_1;
    sfSprite *up2_2;
    sfSprite *up3_1;
    sfSprite *up3_2;
    sfSprite *up4_1;
    sfSprite *desc1;
    sfSprite *desc2;
    sfSprite *desc3;
    sfSprite *desc4;
    sfSprite *sablier;
    sfSprite *lose;
    sfSprite *restart;
    sfSprite *exitt;
    sfSprite *acceuil;
    sfSprite *trophe;
    sfSprite *pause;
    sfSprite *highscore;
    sfSprite *htp;
    sfSprite *htp_icon;
    sfSprite *list_tower;
    sfSprite *tower_icon;
    sfSprite *luffy;
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
    int nb_pic;
    int place_bl;
    int line;
    int life;
    int road_x;
    int road_y;
    int max;
    float *spd;
    int s_play[4];
    int s_setting[4];
    int s_exit[4];
    int s_home[4];
    int s_hud1[4];
    int s_hud2[4];
    int s_tower[4];
    int s_htp[4];
    int s_lboard[4];
    int no_life;
    float *lvl1;
    float *lvl2;
    float *lvl3;
    float *lvl4;
    int *dura_pic;
    int click;
    int reset_map;
    int reset_map_v;
    int number_waves;
    int max_waves;
    int sablier_gest;
    int waiting;
    int waiting_time;
    int pause;
    int reset_best_score;
    int luffy;
    sfIntRect sablier;
    sfIntRect luffyette;
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
    sfText *waves;
    sfText *print_waves;
    sfText *pause;
    sfText *name1;
    sfText *name2;
    sfText *name3;
    sfText *wave1;
    sfText *wave2;
    sfText *wave3;
};

typedef struct clocks_s clocks_t;
struct clocks_s {
    sfClock *map;
    sfClock *d;
    sfClock **dart;
    sfClock **shuriken;
    sfClock **fireball;
    sfClock **laser;
    sfClock *sablier;
    sfClock *luffy;
};

typedef struct music_s music_t;
struct music_s {
    sfMusic *music;
    sfMusic *shoot;
    sfMusic *upgrade;
};

typedef struct str_s str_t;
struct str_s {
    char **tab_waves;
    char *line;
    char **map1;
    char *nb_dart;
    char *nb_laser;
    char *nb_fireball;
    char *nb_shuriken;
    char *name;
};

typedef struct pos_s pos_t;
struct pos_s {
    sfVector2f b;
    sfVector2f ballon;
    sfVector2f right;
    sfVector2f down;
    sfVector2f up;
    sfVector2f pb;
    sfVector2f left;
    sfVector2f up_right;
    sfVector2f down_right;
    sfVector2f down_left;
    sfVector2f up_left;
    sfVector2i *tower;
    sfVector2i *pic;
    sfVector2f scale;
    sfVector2f rescale;
};

typedef struct te_s te_t;
struct te_s {
    sfTexture *b1;
    sfTexture *b2;
    sfTexture *b3;
    sfTexture *b4;
    sfTexture *b5;
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
    te_t te;
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
all_t set_pos_drag(all_t all, sfVector2i mouse, float scale);
void display_bl(all_t all);
all_t gest_life(all_t all, sfSprite *sprite, int i);
void display_life(all_t all);
char *read_fonction(char *file);
void display_money(all_t all);
int check_on(sfSprite *sprite, int x, int y, all_t all);
all_t scale_tex(sfSprite *sprite, int *size, all_t all);
int check_release(sfSprite *sprite, int x, int y, all_t all);
all_t init_waves_second(all_t all);
char *read_fonction(char *file);
char *read_map(char *file);
int compt_bal(char *str);
all_t add_speed(all_t all, int i);
all_t create_sprite_tab(all_t all);
char *split_line(char *str, int i, all_t all);
char **str_to_chartab(char *str);
all_t gest_life2(all_t all, sfSprite *sprite, int i);
int check_on(sfSprite *sprite, int x, int y, all_t all);
all_t scale_tex(sfSprite *sprite, int *size, all_t all);
int check_release(sfSprite *sprite, int x, int y, all_t all);
all_t tower(all_t all);
all_t click_tower1(all_t all);
all_t click_tower2(all_t all);
all_t click_tower3(all_t all);
all_t click_tower4(all_t all);
all_t check_range(sfSprite *sprite, float range, int tower, all_t all);
all_t create_shoot1(all_t all, int i, float range, int tower);
all_t create_shoot2(all_t all, int i, float range, int tower);
all_t create_shoot3(all_t all, int i, float range, int tower);
all_t create_shoot4(all_t all, int i, float range, int tower);
all_t move_shoot(all_t all, int i, float range, sfSprite *sprite);
all_t init_str(all_t all);
all_t kill_ballon(all_t all, int i , int range);
int check_click_tower(sfSprite *sprite, int x, int y, all_t all);
all_t up1(all_t all, int i);
all_t up2(all_t all, int i);
all_t up3(all_t all, int i);
all_t up4(all_t all, int i);
all_t animated_sprite(all_t all);
all_t endgame_part(all_t all);
all_t max_waves(char *str, all_t all);
int check_end_round(all_t all);
all_t next_wave(all_t all);
void reset_pos_up(all_t all, int i);
sfSprite *set_scale(sfSprite *sprite, float x, float y);
all_t game_pause(all_t all);
all_t wait(all_t all);
void display_pause(all_t all);
void backgound_music(all_t all);
void sound_shoot(all_t all);
void sound_upgrade(all_t all);
char *my_write(char *buffer, char *file, all_t all);
char *my_read(char *file, all_t all);
all_t check_best_score(all_t all);
all_t drag_pic(all_t all, sfVector2i mouse);
all_t set_pic(all_t all, sfVector2i mouse);
all_t set_pos_drag_pic(all_t all, sfVector2i mouse, float scale);
all_t check_pic(all_t all);
void display_highscore(all_t all);
void aff_highscore(all_t all);
void display_htp(all_t all);
all_t aff_htp(all_t all);
all_t aff_list_tower(all_t all);
void display_list_tower(all_t all);
all_t destroy_tower(all_t all);
all_t animated_luffy(all_t all);
