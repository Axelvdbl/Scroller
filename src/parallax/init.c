/*
** init.c for rush in /home/ethan/rush/src/parallax/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Sat Apr  1 12:58:24 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 18:58:12 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

static void     parallax_init(t_parallax *data)
{
    sfIntRect   area;

    area = INTRECT(0, 0, 1920, 1080);
    data->layers[0] = TEX("assets/parallax/layer_01.png", &area);
    data->layers[1] = TEX("assets/parallax/layer_02.png", &area);
    data->layers[2] = TEX("assets/parallax/layer_03.png", &area);
    data->layers[3] = TEX("assets/parallax/layer_04.png", &area);
    data->layers[4] = TEX("assets/parallax/layer_05.png", &area);
    data->layers[5] = TEX("assets/parallax/layer_06.png", &area);
    data->layers[6] = TEX("assets/parallax/layer_07.png", &area);
    data->depth[0] = 350;
    data->depth[1] = 200;
    data->depth[2] = 150;
    data->depth[3] = 75;
    data->depth[4] = 50;
    data->depth[5] = 1;
    data->depth[6] = 0;
    data->pos[0] = 0.0f;
    data->pos[1] = 0.0f;
    data->pos[2] = 0.0f;
    data->pos[3] = 0.0f;
    data->pos[4] = 0.0f;
    data->pos[5] = 0.0f;
    data->pos[6] = 0.0f;
    data->dir = 1;
}

t_parallax      *parallax_create()
{
    t_parallax  *data;
    size_t      i;

    if ((data = malloc(sizeof(t_parallax))) != NULL)
    {
        parallax_init(data);
        i = 0;
        while (i < 7)
        {
            data->sprites[i] = sfSprite_create();
            if (data->sprites[i] != NULL && data->layers[i] != NULL)
            {
                sfTexture_setRepeated(data->layers[i], sfTrue);
                sfSprite_setTexture(data->sprites[i], data->layers[i], sfTrue);
            }
            ++i;
        }
    }
    return (data);
}

void        parallax_destroy(t_parallax *data)
{
    size_t  i;

    if (data != NULL)
    {
        i = 0;
        while (i < 7)
        {
            sfSprite_destroy(data->sprites[i]);
            sfTexture_destroy(data->layers[i]);
            ++i;
        }
        free(data);
    }
}
