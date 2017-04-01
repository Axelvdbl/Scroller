/*
** window.c for rush in /home/ethan/rush/src/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Fri Mar 31 21:04:55 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 19:38:25 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

t_window            *window_create()
{
    t_window        *win;
    sfVideoMode     mode;

    if ((win = malloc(sizeof(t_window))) != NULL)
    {
        mode = sfVideoMode_getDesktopMode();
        win->handle = sfRenderWindow_create(mode, "Rush Scroller",
                                            sfFullscreen, NULL);
        if (!win->handle)
        {
            free(win);
            return (NULL);
        }
        sfRenderWindow_setVerticalSyncEnabled(win->handle, sfTrue);
        sfRenderWindow_setMouseCursorVisible(win->handle, sfFalse);
        win->height = mode.height;
        win->width = mode.width;
        win->scene = 0;
        win->next_scene = 0;
        win->scene_count = 2;
        win->switching = false;
        win->paused = false;
    }
    return (win);
}

void    window_destroy(t_window *win)
{
    if (win != NULL)
    {
        sfRenderWindow_destroy(win->handle);
        free(win);
    }
}

void    window_poll_events(t_window *win, sfEvent *event, t_scenes *scenes)
{
    while (sfRenderWindow_pollEvent(win->handle, event))
    {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(win->handle);
        else if (event->type == sfEvtKeyPressed)
        {
            if (event->key.code == sfKeyEscape)
                sfRenderWindow_close(win->handle);
            else if (event->key.code == sfKeySpace)
                win->paused = !win->paused;
            else if (event->key.code == sfKeyLeft)
                switch_scenes(win, win->scene + 1);
            else if (event->key.code == sfKeyRight)
                switch_scenes(win, win->scene - 1);
            else
                switch_scenes_handler(scenes, win, event->key.code);
        }
    }
}

void            window_loop(t_window *win)
{
    sfClock     *timer;
    sfEvent     event;
    sfTime      microsecs;
    t_scenes    *scenes;

    scenes = scenes_create();
    timer = sfClock_create();
    if (scenes != NULL && timer != NULL)
    {
        while (sfRenderWindow_isOpen(win->handle))
        {
            microsecs = sfClock_restart(timer);
            win->elapsed = microsecs.microseconds / 1000000.0f;
            window_poll_events(win, &event, scenes);
            sfRenderWindow_clear(win->handle, RGB(138, 146, 160));
            switch_scenes_animate(scenes, win);
            switch_scenes_draw(scenes, win);
            sfRenderWindow_display(win->handle);
        }
    }
    scenes_destroy(scenes);
    sfClock_destroy(timer);
}
