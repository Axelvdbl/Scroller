/*
** init.c for rush in /home/ethan/rush/src/scroller/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Sat Apr  1 15:45:21 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 16:51:01 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

t_scroller      *scroller_create()
{
    t_scroller  *data;

    if ((data = malloc(sizeof(t_scroller))) != NULL)
    {
        data->texture = TEX("assets/scroller.png", &INTRECT(0, 0, 683, 91));
        data->sprite = sfSprite_create();
        if (data->texture != NULL)
            sfSprite_setTexture(data->sprite, data->texture, sfTrue);
        data->pos = VECT2F(1920 / 2 - 683 / 2, 1080 / 2 - 91 / 2);
        data->dir = random_dir();
    }
    return (data);
}

void    scroller_destroy(t_scroller *data)
{
    if (data != NULL)
    {
        sfSprite_destroy(data->sprite);
        sfTexture_destroy(data->texture);
        free(data);
    }
}
