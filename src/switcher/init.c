/*
** init.c for rush in /home/ethan/rush/src/switcher/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Sat Apr  1 18:00:18 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 18:14:31 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

t_switcher      *switcher_create()
{
    t_switcher  *data;

    if ((data = malloc(sizeof(t_switcher))) != NULL)
    {
        data->texture = TEX("assets/switcher.jpg", &INTRECT(0, 0, 1920, 1080));
        data->sprite = sfSprite_create();
        if (data->texture != NULL)
            sfSprite_setTexture(data->sprite, data->texture, sfTrue);
        data->opacity = 0;
        data->multiplier = 512;
    }
    return (data);
}

void    switcher_destroy(t_switcher *data)
{
    if (data != NULL)
    {
        sfSprite_destroy(data->sprite);
        sfTexture_destroy(data->texture);
        free(data);
    }
}
