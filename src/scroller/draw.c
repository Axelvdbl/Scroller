/*
** draw.c for rush in /home/ethan/rush/src/scroller/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Sat Apr  1 15:51:00 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 17:29:49 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

static void     scroller_check_collisions(t_scroller *data, t_window *win)
{
    if (data->pos.x <= 0)
    {
        data->pos.x = 0;
        data->dir.x = -data->dir.x;
    }
    else if (data->pos.y <= 0)
    {
        data->pos.y = 0;
        data->dir.y = -data->dir.y;
    }
    if (data->pos.x + 683 >= win->width)
    {
        data->pos.x = win->width - 683;
        data->dir.x = -data->dir.x;
    }
    else if (data->pos.y + 91 >= win->height)
    {
        data->pos.y = win->height - 91;
        data->dir.y = -data->dir.y;
    }
}

void    scroller_animate(t_scroller *data, t_window *win)
{
    if (data->sprite != NULL)
    {
        data->pos.x += 500 * data->dir.x * win->elapsed;
        data->pos.y += 500 * data->dir.y * win->elapsed;
        sfSprite_setPosition(data->sprite, data->pos);
        scroller_check_collisions(data, win);
    }
}

void    scroller_draw(t_scroller *data, t_window *win)
{
    if (data->sprite != NULL)
        sfRenderWindow_drawSprite(win->handle, data->sprite, NULL);
}
