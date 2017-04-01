/*
** draw.c for rush in /home/ethan/rush/src/switcher/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Sat Apr  1 18:00:07 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 18:21:33 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

void    switcher_animate(t_switcher *data, t_window *win)
{
    if (data->sprite != NULL)
    {
        data->opacity += data->multiplier * win->elapsed;
        if (data->opacity >= 255)
        {
            data->opacity = 255;
            data->multiplier = -512;
            win->scene = win->next_scene;
        }
        else if (data->multiplier < 0 && data->opacity <= 0)
        {
            data->opacity = 0;
            data->multiplier = 512;
            win->switching = false;
        }
        sfSprite_setColor(data->sprite, RGBA(255, 255, 255, data->opacity));
    }
}

void    switcher_draw(t_switcher *data, t_window *win)
{
    if (data->sprite != NULL)
        sfRenderWindow_drawSprite(win->handle, data->sprite, NULL);
}
