/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** object.c
*/

#include <my_defender.h>

void draw_tower(sfRenderWindow *win, tower_t tower)
{
    sfVector2i int_mouse_pos = sfMouse_getPositionRenderWindow(win);
    sfVector2f m_pos = (sfVector2f){int_mouse_pos.x, int_mouse_pos.y};
    int hover = 0;

    if (tower.stat.power) {
        hover = rect_clicked(tower.rect, tower.pos, m_pos);
        if (tower.circle && hover)
            sfRenderWindow_drawCircleShape(win, tower.circle, NULL);
        sfRenderWindow_drawSprite(win, tower.sprite, NULL);
    }
}

void show_map(sfRenderWindow *win, map_t *map)
{
    for (int i = 0; i < map->nb_tile; i++)
        sfRenderWindow_drawSprite(win, map->tiles[i].sprite, NULL);
    for (int i = 0; i < map->nb_obj; i++)
        draw_tower(win, map->objects[i]);
}

void destroy_enemies(enemy_t *enemies, int size)
{
    for (int i = 0; i < size; i++) {
        destroy_paths(&enemies[i].path);
        sfTexture_destroy(enemies[i].texture);
        sfSprite_destroy(enemies[i].sprite);
        sfClock_destroy(enemies[i].clock);
    }
}

void destroy_menus(container_t *menu)
{
    for (int i = 0; i < 6; i++) {
        destroy_buttons(&menu[i].buttons);
        sfTexture_destroy(menu[i].image);
        sfSprite_destroy(menu[i].sprite);
        menu[i].buttons.size = 0;
        if (menu[i].power.text) {
            sfFont_destroy(menu[i].speed.font);
            sfText_destroy(menu[i].speed.text);
            sfFont_destroy(menu[i].radius.font);
            sfText_destroy(menu[i].radius.text);
            sfFont_destroy(menu[i].power.font);
            sfText_destroy(menu[i].power.text);
        }
    }
}

void destroy_map(map_t *map)
{
    tower_t tower;

    destroy_menus(map->menu);
    for (int i = 0; i < map->nb_obj; i++) {
        tower = map->objects[i];
        if (tower.type == TOWER || tower.type == D_TOWER) {
            sfCircleShape_destroy(tower.circle);
            sfClock_destroy(tower.clock);
        }
        sfTexture_destroy(tower.texture);
        sfSprite_destroy(tower.sprite);
    }
    for (int i = 0; i < map->nb_tile; i++) {
        sfTexture_destroy(map->tiles[i].texture);
        sfSprite_destroy(map->tiles[i].sprite);
    }
    destroy_enemies(map->enemies, map->nb_e);
}