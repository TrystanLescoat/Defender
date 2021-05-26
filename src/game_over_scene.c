/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** game_over_scene.c
*/

#include <my_defender.h>

void empty_game_over(var_t *var)
{
    return;
}

void reset_game_scene(scene_t *scene, var_t *var)
{
    var->carried_stats = NULL;
    var->stat.power = 0;
    var->stat.radius = 0;
    var->stat.speed = 0;
    var->nb_end = 0;
    var->quit = 0;
    var->reset = 0;
    var->nb_scenes = 6;
    var->cost = 0;
    var->menu = 0;
    var->image = NULL;
    var->money.value = 400;
    var->life.value = 100;
    var->wave.value = 1;
    var->spawn_time = rand_nbr(1, 4);
    var->nb_enemies = var->wave.value * rand_nbr(1, 3);
}

void create_lose_scene(scene_t *lose, char **array)
{
    lose->img = sfTexture_createFromFile("assets/plain_back.png", NULL);
    lose->sprite = sfSprite_create();
    sfSprite_setTexture(lose->sprite, lose->img, sfTrue);
    create_buttons_array(&lose->buttons);
    add_button(&lose->buttons, array[4], back_button);
    add_graphics(array[4], &lose->buttons.all[lose->buttons.size - 1]);
    add_button(&lose->buttons, array[9], play_button);
    add_graphics(array[9], &lose->buttons.all[lose->buttons.size - 1]);
    add_button(&lose->buttons, array[1], quit_button);
    add_graphics(array[1], &lose->buttons.all[lose->buttons.size - 1]);
    add_button(&lose->buttons, array[11], empty_game_over);
    add_graphics(array[11], &lose->buttons.all[lose->buttons.size - 1]);
    add_button(&lose->buttons, array[2], score_button);
    add_graphics(array[2], &lose->buttons.all[lose->buttons.size - 1]);
    lose->map.nb_obj = 0;
    lose->map.nb_tile = 0;
    lose->map.arr_map = NULL;
}