/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** create_menus.c
*/

#include <my_defender.h>

void create_score_menu(scene_t *score, char **array)
{
    score->img = sfTexture_createFromFile("assets/plain_back.png", NULL);
    score->sprite = sfSprite_create();
    sfSprite_setTexture(score->sprite, score->img, sfTrue);
    create_buttons_array(&score->buttons);
    add_button(&score->buttons, array[4], back_button);
    add_graphics(array[4], &score->buttons.all[score->buttons.size - 1]);
    score->map.nb_obj = 0;
    score->map.nb_tile = 0;
    score->map.arr_map = NULL;
    create_stat(&score->write, (sfVector2f){700, 350});
}

void create_how_menu(scene_t *how, char **array)
{
    how->img = sfTexture_createFromFile("assets/how_to_play.png", NULL);
    how->sprite = sfSprite_create();
    sfSprite_setTexture(how->sprite, how->img, sfTrue);
    create_buttons_array(&how->buttons);
    add_button(&how->buttons, array[4], back_button);
    add_graphics(array[4], &how->buttons.all[how->buttons.size - 1]);
    how->map.nb_obj = 0;
    how->map.nb_tile = 0;
    how->map.arr_map = NULL;
}

void create_main_menu(scene_t *menu, char **array)
{
    menu->img = sfTexture_createFromFile("assets/plain_back.png", NULL);
    menu->sprite = sfSprite_create();
    sfSprite_setTexture(menu->sprite, menu->img, sfTrue);
    create_buttons_array(&menu->buttons);
    add_button(&menu->buttons, array[0], play_button);
    add_graphics(array[0], &menu->buttons.all[menu->buttons.size - 1]);
    add_button(&menu->buttons, array[1], quit_button);
    add_graphics(array[1], &menu->buttons.all[menu->buttons.size - 1]);
    add_button(&menu->buttons, array[2], score_button);
    add_graphics(array[2], &menu->buttons.all[menu->buttons.size - 1]);
    add_button(&menu->buttons, array[3], how_button);
    add_graphics(array[3], &menu->buttons.all[menu->buttons.size - 1]);
    menu->map.nb_obj = 0;
    menu->map.nb_tile = 0;
    menu->map.arr_map = NULL;
}

void create_main_scene(scene_t *main, char **array, char **map)
{
    main->img = sfTexture_create(1, 1);
    main->sprite = sfSprite_create();
    sfSprite_setTexture(main->sprite, main->img, sfTrue);
    create_buttons_array(&main->buttons);
    add_button(&main->buttons, array[4], back_button);
    add_graphics(array[4], &main->buttons.all[main->buttons.size - 1]);
    init_map(&main->map, map);
    create_build_menu(main->map.menu, array);
}

void create_pause_menu(scene_t *pause, char **array)
{
    pause->img = sfTexture_createFromFile("assets/plain_back.png", NULL);
    pause->sprite = sfSprite_create();
    sfSprite_setTexture(pause->sprite, pause->img, sfTrue);
    create_buttons_array(&pause->buttons);
    add_button(&pause->buttons, array[4], back_button);
    add_graphics(array[4], &pause->buttons.all[pause->buttons.size - 1]);
    add_button(&pause->buttons, array[0], play_button);
    add_graphics(array[0], &pause->buttons.all[pause->buttons.size - 1]);
    add_button(&pause->buttons, array[1], quit_button);
    add_graphics(array[1], &pause->buttons.all[pause->buttons.size - 1]);
    pause->map.nb_obj = 0;
    pause->map.nb_tile = 0;
    pause->map.arr_map = NULL;
}