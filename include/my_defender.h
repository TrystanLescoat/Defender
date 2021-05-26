/*
** EPITECH PROJECT, 2020
** My_screensaver
** File description:
** my_screensaver.h
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "framebuffer.h"
#include <my.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct var_s var_t;

typedef struct map_s map_t;

typedef enum {
    WALL,
    FLOOR,
    PLACE,
    TOWER,
    D_TOWER,
    SLOW,
    ATTACK,
    HEAL,
    MONEY,
    START,
    DEST,
    ENEMY
} my_type;

typedef struct stat_s {
    int power;
    int cost_power;
    int radius;
    int cost_radius;
    int speed;
    int cost_speed;
    my_type type;
} stat_t;

typedef struct tile_s {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    my_type type;
    sfVector2f pos;
} tile_t;

typedef struct tower_s {
    stat_t stat;
    sfIntRect rect;
    sfCircleShape *circle;
    sfTexture *texture;
    sfSprite *sprite;
    my_type type;
    sfVector2f pos;
    sfClock *clock;
    void (*ptr)(map_t *map, struct tower_s *tower, var_t *var);
} tower_t;

typedef struct path_s {
    sfVector2f pos;
    struct path_s *next;
} path_t;

typedef struct enemy_s {
    float hp;
    int gold;
    int speed;
    sfTexture *texture;
    sfSprite *sprite;
    my_type type;
    sfVector2f pos;
    path_t *path;
    sfClock *clock;
    sfIntRect rect;
} enemy_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfTexture *inactive;
    sfTexture *hover;
    sfTexture *click;
    sfSprite *sprite;
    void (*ptr)(var_t *var);
} button_t;

typedef struct buttons_s {
    button_t all[10];
    int size;
} buttons_t;

typedef struct write_s {
    sfFont *font;
    sfText *text;
    sfVector2f pos;
} write_t;

typedef struct container_s {
    buttons_t buttons;
    write_t speed;
    write_t radius;
    write_t power;
    sfTexture *image;
    sfSprite *sprite;
} container_t;

struct map_s {
    container_t menu[6];
    tile_t tiles[1000];
    tower_t objects[100];
    enemy_t enemies[100];
    sfVector2f dest;
    int nb_tile;
    int nb_obj;
    int nb_e;
    char **arr_map;
    int max_x;
    int max_y;
};

typedef struct global_s {
    int value;
    sfTexture *img;
    sfSprite *sprite;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfClock *clock;
} global_t;

typedef struct music_s {
    sfMusic *music;
    sfMusic *money_sfx;
    sfMusic *hit_sfx;
} music_t;

struct var_s {
    int quit;
    int current;
    int nb_scenes;
    int nb_end;
    int reset;
    int spawn_time;
    int nb_enemies;
    int cost;
    int menu;
    char *score;
    stat_t stat;
    stat_t *carried_stats;
    music_t sound;
    void (*ptr)(map_t *map, tower_t *tower, struct var_s *var);
    sfSprite *m_sprite;
    sfTexture *image;
    global_t money;
    global_t life;
    global_t wave;
};

typedef struct scene_s {
    buttons_t buttons;
    sfTexture *img;
    sfSprite *sprite;
    map_t map;
    write_t write;
} scene_t;

// Button functions

void play_button(var_t *var);

void quit_button(var_t *var);

void score_button(var_t *var);

void how_button(var_t *var);

void back_button(var_t *var);

void money_button(var_t *var);

void attack_button(var_t *var);

void slow_button(var_t *var);

void heal_button(var_t *var);

// Create Scenes

void create_score_menu(scene_t *score, char **array);

void create_how_menu(scene_t *how, char **array);

void create_main_menu(scene_t *menu, char **array);

void create_main_scene(scene_t *main, char **array, char **map);

void create_pause_menu(scene_t *pause, char **array);

void create_lose_scene(scene_t *lose, char **array);

void destroy_game_scene(scene_t *scene);

void reset_game_scene(scene_t *scene, var_t *var);

// Main scene variables

void create_global(global_t *global, int value, sfVector2f pos, char *img);

void destroy_global(global_t *global);

// Buttons

void create_buttons_array(buttons_t *buttons);

void add_button(buttons_t *buttons, char *info, void (*ptr)(var_t *var));

void add_graphics(char *info, button_t *button);

void display_buttons(sfRenderWindow *window, buttons_t *obj_array);

void destroy_buttons(buttons_t *obj_array);

// Window

void create_window(window_t *win);

void destroy_window(window_t *win, scene_t *scene, var_t *var);

void analyse_events(sfRenderWindow *win, scene_t *scene, var_t *var);

// Essentials

int my_strlen_array(char **array);

void free_array(char **array);

char *read_file(char *filepath);

char **read_file_array(char *filepath);

int error_map(char **map);

void nb_s_and_f(char **map, int i, int *nb_s, int *nb_f);

sfText *create_text(sfText *text, sfVector2f pos, sfFont *font, int size);

void draw_text(sfRenderWindow *window, global_t *global, char *str);

void draw_menu_text(sfRenderWindow *window, write_t *text, int stat, int cost);

int normalized_int(int nb);

float my_abs(float nb);

sfVector2f int_vec_to_float(sfVector2i int_vec);

void update_score(var_t *var, map_t *map);

// Collision

int rect_clicked(sfIntRect rect, sfVector2f r_pos, sfVector2f mouse_pos);

void attack_enemy(tower_t *tower, enemy_t *enemy, var_t *var);

void slow_enemy(tower_t *tower, enemy_t *enemy, var_t *var);

// Update map

void show_map(sfRenderWindow *win, map_t *map);

void init_tower(tower_t *tower, var_t *var);

void destroy_map(map_t *map);

// Create map

void init_map(map_t *map, char **arr_map);

void add_tile(tile_t *tile, char type);

void add_object(tower_t *object, char type);

void add_elem(map_t *map, char type, int x, int y);

char **duplicate_map(char **map);

// Enemies

void add_enemy(map_t *map, var_t *var);

void create_paths(enemy_t *enemy, char **map, sfVector2f dest);

void update_enemies(enemy_t *enemy, var_t *var);

void display_enemies(sfRenderWindow *window, map_t *map, var_t *var);

void push_back_path(path_t **paths, sfVector2f pos);

void destroy_paths(path_t **paths);

void destroy_enemies(enemy_t *enemies, int size);

// Collision Detection

int button_is_clicked(button_t button, sfVector2f mouse_pos);

int rect_clicked(sfIntRect rect, sfVector2f r_pos, sfVector2f mouse_pos);

int circle_point_collision(sfCircleShape *circle, sfVector2f pos);

sfVector2f points_distance(sfVector2f pos1, sfVector2f pos2);

// Music

sfMusic *create_music(char *file, sfBool my_bool, int vol);

// Main Loop

void main_loop(window_t *win, scene_t *scene, var_t *var);

void score_loop(window_t *win, scene_t *scene, var_t *var);

// Tower Functions

void attack_tower(map_t *map, tower_t *tower, var_t *var);

void slow_tower(map_t *map, tower_t *tower, var_t *var);

void money_tower(map_t *map, tower_t *tower, var_t *var);

void heal_tower(map_t *map, tower_t *tower, var_t *var);

void update_towers(map_t *map, var_t *var);

// Build Menu

void create_stat(write_t *text, sfVector2f pos);

void create_build_menu(container_t *build, char **array);

void create_heal_build_menu(container_t *heal, char **array);

void create_earn_build_menu(container_t *money, char **array);

void create_slow_build_menu(container_t *slow, char **array);

void create_attack_build_menu(container_t *attack, char **array);

void build_menu(var_t *var);

void close_menu(var_t *var);

void remove_tower(var_t *var);

void upgrade_power(var_t *var);

void upgrade_radius(var_t *var);

void upgrade_speed(var_t *var);

int get_boost(my_type type, int power, int radius, int speed);

// Error and help handling

int get_options(int argc, char **argv);

#endif /*DEFENDER_H*/