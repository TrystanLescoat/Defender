/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-trystan.lescoat
** File description:
** check_collisions.c
*/

#include <my_defender.h>

int button_is_clicked(button_t button, sfVector2f mouse_pos)
{
    sfVector2f b_pos = sfRectangleShape_getPosition(button.rect);
    sfVector2f b_size = sfRectangleShape_getSize(button.rect);

    if (mouse_pos.x >= b_pos.x && mouse_pos.x <= b_pos.x + b_size.x)
        if (mouse_pos.y >= b_pos.y && mouse_pos.y <= b_pos.y + b_size.y)
            return (1);
    return (0);
}

int rect_clicked(sfIntRect rect, sfVector2f r_pos, sfVector2f mouse_pos)
{
    sfVector2f r_size = (sfVector2f){rect.width, rect.height};

    if (mouse_pos.x >= r_pos.x && mouse_pos.x <= r_pos.x + r_size.x)
        if (mouse_pos.y >= r_pos.y && mouse_pos.y <= r_pos.y + r_size.y)
            return (1);
    return (0);
}

int circle_point_collision(sfCircleShape *circle, sfVector2f pos)
{
    sfVector2f c_pos = sfCircleShape_getPosition(circle);
    float radius = sfCircleShape_getRadius(circle) * 2;

    if (pos.x >= c_pos.x && pos.x <= c_pos.x + radius)
        if (pos.y >= c_pos.y && pos.y <= c_pos.y + radius)
            return (1);
    return (0);
}

sfVector2f points_distance(sfVector2f pos1, sfVector2f pos2)
{
    sfVector2f dist = {0, 0};

    dist.x = pos1.x - pos2.x;
    dist.y = pos1.y - pos2.y;
    return (dist);
}