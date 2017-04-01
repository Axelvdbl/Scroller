/*
** init.c for rush in /home/ethan/rush/src/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Sat Apr  1 17:01:58 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 18:10:38 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

t_scenes        *scenes_create()
{
    t_scenes    *scenes;

    if ((scenes = malloc(sizeof(t_scenes))) != NULL)
    {
        scenes->switcher = switcher_create();
        scenes->scroller = scroller_create();
        scenes->parallax = parallax_create();
    }
    return (scenes);
}

void    scenes_destroy(t_scenes *scenes)
{
    if (scenes != NULL)
    {
        switcher_destroy(scenes->switcher);
        scroller_destroy(scenes->scroller);
        parallax_destroy(scenes->parallax);
        free(scenes);
    }
}
