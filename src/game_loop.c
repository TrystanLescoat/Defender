/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** game_loop.c
*/

#include <my_defender.h>

void draw_gain(window_t *win, container_t menu, var_t *var)
{
    sfVector2f new_pos = {1500, 928};
    char *gain = NULL;
    stat_t stat = var->stat;
    int speed = stat.cost_speed;
    int power = stat.cost_power;

    gain = to_str(get_boost(stat.type, power, stat.cost_radius, speed));
    sfText_setString(menu.power.text, gain);
    sfText_setPosition(menu.power.text, new_pos);
    sfRenderWindow_drawText(win->window, menu.power.text, NULL);
    free(gain);
}

void draw_build_menu(window_t *win, scene_t *scene, var_t *var)
{
    sfRenderWindow *window = win->window;
    container_t menu = scene->map.menu[var->menu];
    stat_t stat = var->stat;

    sfRenderWindow_drawSprite(window, scene->map.menu[var->menu].sprite, NULL);
    display_buttons(window, &scene->map.menu[var->menu].buttons);
    if (menu.power.text) {
        if (var->stat.power != 0)
            draw_menu_text(window, &menu.power, stat.power, stat.cost_power);
        if (var->stat.radius != 0)
            draw_menu_text(window, &menu.radius, stat.radius, stat.cost_radius);
        if (var->stat.speed != 0)
            draw_menu_text(window, &menu.speed, stat.speed, stat.cost_speed);
        draw_gain(win, menu, var);
    }
}

void draw_loop(window_t *win, scene_t *scene, var_t *var)
{
    sfRenderWindow *window = win->window;

    display_enemies(window, &scene->map, var);
    sfRenderWindow_drawSprite(window, var->money.sprite, NULL);
    sfRenderWindow_drawSprite(window, var->life.sprite, NULL);
    sfRenderWindow_drawSprite(window, var->wave.sprite, NULL);
    draw_text(window, &var->money, to_str(var->money.value));
    draw_text(window, &var->life, to_str(var->life.value));
    draw_text(window, &var->wave, to_str(var->wave.value));
    draw_build_menu(win, scene, var);
}

void game_loop(window_t *win, scene_t *scene, var_t *var)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win->window);
    float time = 0;

    show_map(win->window, &scene->map);
    time = get_seconds(var->wave.clock);
    if (scene->map.nb_e <= var->nb_enemies && time >= var->spawn_time) {
        add_enemy(&scene->map, var);
        var->spawn_time = rand_nbr(1, 4);
        sfClock_restart(var->wave.clock);
    }
    update_towers(&scene->map, var);
    draw_loop(win, scene, var);
    if (var->image != NULL) {
        sfSprite_setPosition(var->m_sprite, int_vec_to_float(mouse_pos));
        sfRenderWindow_drawSprite(win->window, var->m_sprite, NULL);
    }
}

void main_loop(window_t *win, scene_t *scene, var_t *var)
{
    scene_t *current_scene = &scene[var->current];

    analyse_events(win->window, scene, var);
    if (get_seconds(win->clock) > 0.02) {
        sfRenderWindow_clear(win->window, sfBlack);
        sfRenderWindow_drawSprite(win->window, current_scene->sprite, NULL);
        if (var->current == 3)
            game_loop(win, &scene[var->current], var);
        else if (var->current == 2)
            score_loop(win, &scene[var->current], var);
        display_buttons(win->window, &current_scene->buttons);
        sfRenderWindow_display(win->window);
        sfClock_restart(win->clock);
    }
}