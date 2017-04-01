/*
** switch.c for rush in /home/ethan/rush/src/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Sat Apr  1 17:23:41 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 19:38:52 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

void    switch_scenes(t_window *win, int scene_id)
{
    if (!win->switching)
    {
        if (scene_id < 0)
            win->next_scene = win->scene_count - 1;
        else if (scene_id >= win->scene_count)
            win->next_scene = 0;
        else
            win->next_scene = scene_id;
        win->switching = true;
    }
}

void    switch_scenes_handler(t_scenes *scenes, t_window *win, sfKeyCode key)
{
    if (win->paused)
        return ;
    if (win->scene == 1)
        parallax_handler(scenes->parallax, key);
}

void    switch_scenes_animate(t_scenes *scenes, t_window *win)
{
    if (win->switching)
        switcher_animate(scenes->switcher, win);
    if (win->paused)
        return ;
    if (win->scene == 0)
        scroller_animate(scenes->scroller, win);
    else if (win->scene == 1)
        parallax_animate(scenes->parallax, win);
}

void    switch_scenes_draw(t_scenes *scenes, t_window *win)
{
    if (win->scene == 0)
        scroller_draw(scenes->scroller, win);
    else if (win->scene == 1)
        parallax_draw(scenes->parallax, win);
    if (win->switching)
        switcher_draw(scenes->switcher, win);
}
