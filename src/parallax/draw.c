/*
** draw.c for rush in /home/ethan/rush/src/parallax/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Sat Apr  1 13:17:45 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 19:01:45 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

void            parallax_animate(t_parallax *data, t_window *win)
{
    sfIntRect   area;
    size_t      i;

    i = 0;
    while (i < 7)
    {
        if (data->sprites[i] != NULL)
        {
            area = sfSprite_getTextureRect(data->sprites[i]);
            data->pos[i] += data->depth[i] * win->elapsed * data->dir;
            while (data->pos[i] >= 1920.0f)
            {
                data->pos[i] -= 1920.0f;
            }
            area.left = data->pos[i];
            sfSprite_setTextureRect(data->sprites[i], area);
        }
        ++i;
    }
}

void        parallax_draw(t_parallax *data, t_window *win)
{
    size_t  off;
    size_t  i;

    i = 0;
    while (i < 7)
    {
        off = 6 - i;
        if (data->sprites[off] != NULL)
            sfRenderWindow_drawSprite(win->handle, data->sprites[off], NULL);
        ++i;
    }
}
