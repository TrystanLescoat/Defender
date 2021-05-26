/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** analyse_events.c
*/

#include <my_defender.h>

void check_buttons(sfRenderWindow *window, buttons_t *buttons, var_t *var)
{
    sfVector2i int_mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos = (sfVector2f){int_mouse_pos.x, int_mouse_pos.y};
    sfBool pressed = sfMouse_isButtonPressed(sfMouseLeft);
    button_t button;
    int hover = 0;

    for (int i = 0; i < buttons->size; i++) {
        button = buttons->all[i];
        hover = button_is_clicked(button, mouse_pos);
        if (pressed && hover) {
            button.ptr(var);
        } else if (hover) {
            sfSprite_setTexture(button.sprite, button.hover, sfTrue);
        } else {
            sfSprite_setTexture(button.sprite, button.inactive, sfTrue);
        }
    }
}

void add_tower(map_t *map, var_t *var, int i)
{
    tower_t tower;

    if (var->money.value < var->cost)
        return;
    map->tiles[i].type = TOWER;
    tower.pos = map->tiles[i].pos;
    var->money.value -= var->cost;
    init_tower(&tower, var);
    tower.stat.cost_power = var->stat.cost_power;
    tower.stat.cost_radius = var->stat.cost_radius;
    tower.stat.cost_speed = var->stat.cost_speed;
    map->objects[map->nb_obj] = tower;
    map->nb_obj += 1;
    var->image = NULL;
}

void show_tower_info(tower_t *tower, var_t *var)
{
    if (tower->stat.power == 0)
        return;
    var->carried_stats = &tower->stat;
    var->stat.power = tower->stat.power;
    var->stat.cost_power = tower->stat.cost_power;
    var->stat.radius = tower->stat.radius;
    var->stat.cost_radius = tower->stat.cost_radius;
    var->stat.speed = tower->stat.speed;
    var->stat.cost_speed = tower->stat.cost_speed;
    if (tower->stat.type == ATTACK)
        var->menu = 1;
    if (tower->stat.type == MONEY)
        var->menu = 2;
    if (tower->stat.type == SLOW)
        var->menu = 3;
    if (tower->stat.type == HEAL)
        var->menu = 4;

}

void check_placements(sfRenderWindow *window, map_t *map, var_t *var)
{
    sfVector2i int_mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f m_pos = (sfVector2f){int_mouse_pos.x, int_mouse_pos.y};
    int hover = 0;

    for (int i = 0; i < map->nb_tile; i++) {
        hover = rect_clicked(map->tiles[i].rect, map->tiles[i].pos, m_pos);
        if (var->image && map->tiles[i].type == PLACE && hover) {
            add_tower(map, var, i);
        }
    }
    for (int i = 0; i < map->nb_obj; i++) {
        hover = rect_clicked(map->objects[i].rect, map->objects[i].pos, m_pos);
        if (map->objects[i].type == TOWER && hover) {
            var->image = NULL;
            show_tower_info(&map->objects[i], var);
        }
    }
}

void analyse_events(sfRenderWindow *win, scene_t *scene, var_t *var)
{
    sfEvent event;
    int nb = var->current;
    sfKeyEvent key;

    while (sfRenderWindow_pollEvent(win, &event)) {
        check_buttons(win, &scene[var->current].buttons, var);
        if (var->current == 3)
            check_buttons(win, &scene[nb].map.menu[var->menu].buttons, var);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            check_placements(win, &scene[var->current].map, var);
        key = event.key;
        if (key.code == sfKeyEscape && key.type == sfEvtKeyReleased && nb == 3)
            var->current = 4;
        if (key.code == sfKeyEscape && key.type == sfEvtKeyReleased && nb == 4)
            var->current = 3;
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && var->current == 0)
            sfRenderWindow_close(win);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
    }
}