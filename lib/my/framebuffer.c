/*
** EPITECH PROJECT, 2020
** IntroCSFML
** File description:
** framebuffer.c
*/

#include "../../include/framebuffer.h"
#include <stdlib.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *frame;

    frame = malloc(sizeof(framebuffer_t));
    frame->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    frame->width = width;
    frame->height = height;
    return (frame);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
    return;
}

void my_put_pixel(framebuffer_t *b, unsigned int x, unsigned int y, sfColor c)
{
    int pos = (b->width * y + x) * 4;

    b->pixels[pos + 0] = c.r;
    b->pixels[pos + 1] = c.g;
    b->pixels[pos + 2] = c.b;
    b->pixels[pos + 3] = c.a;
    return;
}