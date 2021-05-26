/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** build_menu.c
*/

#include <my_defender.h>

void create_stat(write_t *text, sfVector2f pos)
{
    text->pos = pos;
    text->font = sfFont_createFromFile("assets/font_menu.TTF");
    text->text = create_text(text->text, text->pos, text->font, 16);
    sfText_setFillColor(text->text, sfBlack);
}

void create_attack_build_menu(container_t *attack, char **array)
{
    create_stat(&attack->power, (sfVector2f){545, 908});
    create_stat(&attack->speed, (sfVector2f){868, 908});
    create_stat(&attack->radius, (sfVector2f){1192, 908});
    attack->image = sfTexture_createFromFile("assets/attack_menu.png", NULL);
    attack->sprite = sfSprite_create();
    sfSprite_setTexture(attack->sprite, attack->image, sfTrue);
    sfSprite_setPosition(attack->sprite, (sfVector2f){0, 780});
    add_button(&attack->buttons, array[10], build_menu);
    add_graphics(array[10], &attack->buttons.all[attack->buttons.size - 1]);
    add_button(&attack->buttons, array[12], upgrade_power);
    add_graphics(array[12], &attack->buttons.all[attack->buttons.size - 1]);
    add_button(&attack->buttons, array[13], upgrade_speed);
    add_graphics(array[13], &attack->buttons.all[attack->buttons.size - 1]);
    add_button(&attack->buttons, array[14], upgrade_radius);
    add_graphics(array[14], &attack->buttons.all[attack->buttons.size - 1]);
    add_button(&attack->buttons, array[15], close_menu);
    add_graphics(array[15], &attack->buttons.all[attack->buttons.size - 1]);
    add_button(&attack->buttons, array[16], remove_tower);
    add_graphics(array[16], &attack->buttons.all[attack->buttons.size - 1]);
}

void create_slow_build_menu(container_t *slow, char **array)
{
    create_stat(&slow->power, (sfVector2f){545, 908});
    create_stat(&slow->speed, (sfVector2f){868, 908});
    create_stat(&slow->radius, (sfVector2f){1192, 908});
    slow->image = sfTexture_createFromFile("assets/slow_menu.png", NULL);
    slow->sprite = sfSprite_create();
    sfSprite_setTexture(slow->sprite, slow->image, sfTrue);
    sfSprite_setPosition(slow->sprite, (sfVector2f){0, 780});
    add_button(&slow->buttons, array[10], build_menu);
    add_graphics(array[10], &slow->buttons.all[slow->buttons.size - 1]);
    add_button(&slow->buttons, array[12], upgrade_power);
    add_graphics(array[12], &slow->buttons.all[slow->buttons.size - 1]);
    add_button(&slow->buttons, array[13], upgrade_speed);
    add_graphics(array[13], &slow->buttons.all[slow->buttons.size - 1]);
    add_button(&slow->buttons, array[14], upgrade_radius);
    add_graphics(array[14], &slow->buttons.all[slow->buttons.size - 1]);
    add_button(&slow->buttons, array[15], close_menu);
    add_graphics(array[15], &slow->buttons.all[slow->buttons.size - 1]);
    add_button(&slow->buttons, array[16], remove_tower);
    add_graphics(array[16], &slow->buttons.all[slow->buttons.size - 1]);
}

void create_earn_build_menu(container_t *money, char **array)
{
    sfVector2f pos = {0, 780};

    create_stat(&money->power, (sfVector2f){545, 908});
    create_stat(&money->speed, (sfVector2f){868, 908});
    create_stat(&money->radius, (sfVector2f){1192, 908});
    money->image = sfTexture_createFromFile("assets/money_menu.png", NULL);
    money->sprite = sfSprite_create();
    sfSprite_setTexture(money->sprite, money->image, sfTrue);
    sfSprite_setPosition(money->sprite, pos);
    add_button(&money->buttons, array[10], build_menu);
    add_graphics(array[10], &money->buttons.all[money->buttons.size - 1]);
    add_button(&money->buttons, array[12], upgrade_power);
    add_graphics(array[12], &money->buttons.all[money->buttons.size - 1]);
    add_button(&money->buttons, array[13], upgrade_speed);
    add_graphics(array[13], &money->buttons.all[money->buttons.size - 1]);
    add_button(&money->buttons, array[15], close_menu);
    add_graphics(array[15], &money->buttons.all[money->buttons.size - 1]);
    add_button(&money->buttons, array[16], remove_tower);
    add_graphics(array[16], &money->buttons.all[money->buttons.size - 1]);
}

void create_heal_build_menu(container_t *heal, char **array)
{
    sfVector2f pos = {0, 780};

    create_stat(&heal->power, (sfVector2f){545, 908});
    create_stat(&heal->speed, (sfVector2f){868, 908});
    create_stat(&heal->radius, (sfVector2f){1192, 908});
    heal->image = sfTexture_createFromFile("assets/heal_menu.png", NULL);
    heal->sprite = sfSprite_create();
    sfSprite_setTexture(heal->sprite, heal->image, sfTrue);
    sfSprite_setPosition(heal->sprite, pos);
    add_button(&heal->buttons, array[10], build_menu);
    add_graphics(array[10], &heal->buttons.all[heal->buttons.size - 1]);
    add_button(&heal->buttons, array[12], upgrade_power);
    add_graphics(array[12], &heal->buttons.all[heal->buttons.size - 1]);
    add_button(&heal->buttons, array[13], upgrade_speed);
    add_graphics(array[13], &heal->buttons.all[heal->buttons.size - 1]);
    add_button(&heal->buttons, array[15], close_menu);
    add_graphics(array[15], &heal->buttons.all[heal->buttons.size - 1]);
    add_button(&heal->buttons, array[16], remove_tower);
    add_graphics(array[16], &heal->buttons.all[heal->buttons.size - 1]);
}