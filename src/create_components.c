/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** create_components.c
*/

#include <my_defender.h>

void create_window(window_t *win)
{
    sfVideoMode mode = {1920, 1080, 32};
    char *name = "My Defender";

    win->clock = sfClock_create();
    win->buffer = framebuffer_create(1920, 1080);
    win->window = sfRenderWindow_create(mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(win->window, 60);
}

sfMusic *create_music(char *file, sfBool my_bool, int vol)
{
    sfMusic *music;

    music = sfMusic_createFromFile(file);
    sfMusic_setVolume(music, vol);
    sfMusic_setLoop(music, my_bool);
    return (music);
}

sfText *create_text(sfText *text, sfVector2f pos, sfFont *font, int size)
{
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    return (text);
}

void draw_text(sfRenderWindow *window, global_t *global, char *str)
{
    sfVector2f new_pos = (sfVector2f){global->pos.x, global->pos.y};

    new_pos.x -= my_strlen(str) * 40;
    sfText_setString(global->text, str);
    sfText_setPosition(global->text, new_pos);
    sfRenderWindow_drawText(window, global->text, NULL);
    free(str);
}

void draw_menu_text(sfRenderWindow *window, write_t *text, int stat, int cost)
{
    sfVector2f new_pos = text->pos;
    char *stat_str;
    char *cost_str;

    if (stat == 0)
        return;
    stat_str = to_str(stat);
    cost_str = to_str(cost);
    sfText_setString(text->text, stat_str);
    sfText_setPosition(text->text, new_pos);
    sfRenderWindow_drawText(window, text->text, NULL);
    new_pos.y += 45;
    new_pos.x -= 17;
    sfText_setString(text->text, cost_str);
    sfText_setPosition(text->text, new_pos);
    sfRenderWindow_drawText(window, text->text, NULL);
    free(stat_str);
    free(cost_str);
}