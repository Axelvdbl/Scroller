/*
** scroller.h for rush in /home/ethan/rush/include/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Fri Mar 31 21:05:57 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 19:00:35 2017 Ethan MARGAILLAN
*/

#ifndef SCROLLER_H_
# define SCROLLER_H_

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <math.h>
# include <SFML/System.h>
# include <SFML/Window.h>
# include <SFML/Graphics.h>

# define TEX(path, area) (sfTexture_createFromFile(path, area))

# define INTRECT(x, y, w, h) ((sfIntRect) { x, y, w, h })

# define VECT2I(x, y) ((sfVector2i) { x, y })
# define VECT2F(x, y) ((sfVector2f) { x, y })
# define VECT3I(x, y, z) ((sfVector3i) { x, y, z })
# define VECT3F(x, y, z) ((sfVector3f) { x, y, z })

# define RGB(r, g, b) ((sfColor) { r, g, b, 255 })
# define RGBA(r, g, b, a) ((sfColor) { r, g, b, a })

typedef struct      s_window
{
    sfRenderWindow  *handle;
    size_t          width;
    size_t          height;
    int             scene;
    int             next_scene;
    int             scene_count;
    bool            switching;
    bool            paused;
    float           elapsed;
} t_window;

typedef struct  s_switcher
{
    sfTexture   *texture;
    sfSprite    *sprite;
    int         opacity;
    int         multiplier;
} t_switcher;

typedef struct  s_parallax
{
    sfTexture   *layers[7];
    sfSprite    *sprites[7];
    size_t      depth[7];
    float       pos[7];
    int         dir;
} t_parallax;

typedef struct  s_scroller
{
    sfTexture   *texture;
    sfSprite    *sprite;
    sfVector2f  pos;
    sfVector2f  dir;
} t_scroller;

typedef struct  s_scenes
{
    t_switcher  *switcher;
    t_scroller  *scroller;
    t_parallax  *parallax;
} t_scenes;

float           random_float();
sfVector2f      random_dir();

t_window        *window_create();
void            window_destroy(t_window *win);
void            window_poll_events(t_window *win, sfEvent *evt, t_scenes *s);
void            window_loop(t_window *win);

t_scenes        *scenes_create();
void            scenes_destroy();

void            switch_scenes(t_window *win, int scene_id);
void            switch_scenes_handler(t_scenes *s, t_window *w, sfKeyCode k);
void            switch_scenes_animate(t_scenes *scenes, t_window *win);
void            switch_scenes_draw(t_scenes *scenes, t_window *win);

t_switcher      *switcher_create();
void            switcher_destroy();
void            switcher_animate(t_switcher *data, t_window *win);
void            switcher_draw(t_switcher *data, t_window *win);

t_parallax      *parallax_create();
void            parallax_destroy(t_parallax *data);
void            parallax_handler(t_parallax *data, sfKeyCode key);
void            parallax_animate(t_parallax *data, t_window *win);
void            parallax_draw(t_parallax *data, t_window *win);

t_scroller      *scroller_create();
void            scroller_destroy(t_scroller *data);
void            scroller_animate(t_scroller *data, t_window *win);
void            scroller_draw(t_scroller *data, t_window *win);

#endif /* !SCROLLER_H_ */
