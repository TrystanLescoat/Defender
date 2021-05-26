/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** build_menu.c
*/

#include <my_defender.h>

int get_boost(my_type type, int power, int radius, int speed)
{
    int boost = 0;

    boost += power;
    boost += radius;
    boost += speed;
    if (type == ATTACK)
        boost += 25;
    if (type == MONEY)
        boost += 50;
    if (type == SLOW)
        boost += 100;
    if (type == HEAL)
        boost += 200;
    boost /= 2;
    return (boost);
}

void remove_tower(var_t *var)
{
    int boost = 0;
    stat_t *stats = var->carried_stats;
    int radius = 0;
    int speed = 0;

    if (stats) {
        stats->power = 0;
        radius = stats->cost_radius;
        speed = stats->cost_speed;
        boost = get_boost(stats->type, stats->cost_power, radius, speed);
        var->money.value += boost;
        if (var->menu != 5 && var->menu != 0)
            var->menu = 0;
    }
}

void create_menu_build_menu(container_t *menu, char **array)
{
    sfVector2f size = {120, 120};

    menu->image = sfTexture_createFromFile("assets/build_menu.png", NULL);
    menu->sprite = sfSprite_create();
    sfSprite_setTexture(menu->sprite, menu->image, sfTrue);
    sfSprite_setPosition(menu->sprite, (sfVector2f){0, 780});
    add_button(&menu->buttons, array[5], attack_button);
    add_graphics(array[5], &menu->buttons.all[menu->buttons.size - 1]);
    add_button(&menu->buttons, array[6], money_button);
    add_graphics(array[6], &menu->buttons.all[menu->buttons.size - 1]);
    add_button(&menu->buttons, array[7], heal_button);
    add_graphics(array[7], &menu->buttons.all[menu->buttons.size - 1]);
    add_button(&menu->buttons, array[8], slow_button);
    add_graphics(array[8], &menu->buttons.all[menu->buttons.size - 1]);
    add_button(&menu->buttons, array[15], close_menu);
    add_graphics(array[15], &menu->buttons.all[menu->buttons.size - 1]);
    for (int i = 0; i < 4; i++) {
        sfSprite_setScale(menu->buttons.all[i].sprite, (sfVector2f){2, 2});
        sfRectangleShape_setSize(menu->buttons.all[i].rect, size);
    }
}

void create_no_menu(container_t *no_menu, char **array)
{
    sfVector2f pos = {0, 780};
    sfVector2f new_pos;

    no_menu->image = sfTexture_create(1, 1);
    no_menu->sprite = sfSprite_create();
    sfSprite_setTexture(no_menu->sprite, no_menu->image, sfTrue);
    sfSprite_setPosition(no_menu->sprite, pos);
    add_button(&no_menu->buttons, array[10], build_menu);
    add_graphics(array[10], &no_menu->buttons.all[no_menu->buttons.size - 1]);
    new_pos = sfRectangleShape_getPosition(no_menu->buttons.all[0].rect);
    new_pos.y += 150;
    sfSprite_setPosition(no_menu->buttons.all[0].sprite, new_pos);
    sfRectangleShape_setPosition(no_menu->buttons.all[0].rect, new_pos);
}

void create_build_menu(container_t *menu, char **array)
{
    create_menu_build_menu(&menu[0], array);
    create_attack_build_menu(&menu[1], array);
    create_earn_build_menu(&menu[2], array);
    create_slow_build_menu(&menu[3], array);
    create_heal_build_menu(&menu[4], array);
    create_no_menu(&menu[5], array);
}