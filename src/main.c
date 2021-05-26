/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** main.c
*/

#include <my_defender.h>

void new_main_scene(var_t *var, scene_t *scene, char **arr_map, char **info)
{
    if (var->life.value <= 0) {
        var->current = 5;
        update_score(var, &scene[3].map);
    } else
        var->current = 0;
    reset_game_scene(scene, var);
    destroy_game_scene(&scene[3]);
    create_main_scene(&scene[3], info, arr_map);
    var->reset = 0;
}

void create_var(var_t *var)
{
    var->current = 0;
    var->score = read_file("assets/save_score.txt");
    var->sound.music = create_music("assets/music/main.ogg", sfTrue, 20);
    var->sound.money_sfx = create_music("assets/music/money.ogg", sfFalse, 40);
    var->sound.hit_sfx = create_music("assets/music/canon.ogg", sfFalse, 40);
    var->m_sprite = sfSprite_create();
    create_global(&var->money, 400, (sfVector2f){1500, 60}, "assets/coin.png");
    create_global(&var->life, 100, (sfVector2f){1500, 130}, "assets/heart.png");
    create_global(&var->wave, 1, (sfVector2f){700, 60}, "assets/sword.png");
}

void my_defender(scene_t *scene, char **arr_map, char **info)
{
    window_t win;
    var_t var;

    reset_game_scene(scene, &var);
    create_var(&var);
    create_window(&win);
    sfMusic_play(var.sound.music);
    while (sfRenderWindow_isOpen(win.window) && !var.quit) {
        main_loop(&win, scene, &var);
        if (var.life.value <= 0 || var.reset)
            new_main_scene(&var, scene, arr_map, info);
    }
    free_array(info);
    free_array(arr_map);
    if (var.score != NULL)
        free(var.score);
    destroy_window(&win, scene, &var);
}

int main(int argc, char **argv)
{
    scene_t scene[6];
    char **array = NULL;
    char **arr_map = NULL;

    srand(argc);
    if (get_options(argc, argv) == 0)
        return (0);
    array = read_file_array("assets/game_info.txt");
    if (array == NULL || argc != 2)
        return (84);
    arr_map = read_file_array(argv[1]);
    if (arr_map == NULL || error_map(arr_map) == 84)
        return (84);
    create_main_menu(&scene[0], array);
    create_how_menu(&scene[1], array);
    create_score_menu(&scene[2], array);
    create_main_scene(&scene[3], array, arr_map);
    create_pause_menu(&scene[4], array);
    create_lose_scene(&scene[5], array);
    my_defender(scene, arr_map, array);
}
