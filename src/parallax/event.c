/*
** event.c for rush in /home/ethan/rush/src/parallax/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Sat Apr  1 18:55:23 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 18:59:37 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

void    parallax_handler(t_parallax *data, sfKeyCode key)
{
    if (key == sfKeyReturn)
    {
        if (data->dir >= 0)
            data->dir = -1;
        else
            data->dir = 1;
    }
}
