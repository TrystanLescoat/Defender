/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** destroy_components.c
*/

#include <my_defender.h>

void destroy_game_scene(scene_t *scene)
{
    destroy_map(&scene->map);
    sfTexture_destroy(scene->img);
    sfSprite_destroy(scene->sprite);
    destroy_buttons(&scene->buttons);
}

void destroy_window(window_t *win, scene_t *scene, var_t *var)
{
    sfMusic_stop(var->sound.music);
    sfMusic_destroy(var->sound.music);
    sfMusic_destroy(var->sound.money_sfx);
    sfMusic_destroy(var->sound.hit_sfx);
    destroy_map(&scene[3].map);
    destroy_global(&var->money);
    destroy_global(&var->life);
    destroy_global(&var->wave);
    for (int i = 0; i < var->nb_scenes; i++) {
        sfTexture_destroy(scene[i].img);
        sfSprite_destroy(scene[i].sprite);
        destroy_buttons(&scene[i].buttons);
    }
    sfFont_destroy(scene[2].write.font);
    sfText_destroy(scene[2].write.text);
    sfSprite_destroy(var->m_sprite);
    framebuffer_destroy(win->buffer);
    sfRenderWindow_destroy(win->window);
    sfClock_destroy(win->clock);
}