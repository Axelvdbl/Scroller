/*
** main.c for rush in /home/ethan/rush/src/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Fri Mar 31 21:05:06 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 15:56:31 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

int             main()
{
    t_window    *win;

    srand(time(NULL));
    if (!(win = window_create()))
    {
        fprintf(stderr, "Error : failed to initialize window\n");
        return (84);
    }
    window_loop(win);
    window_destroy(win);
    return (0);
}
