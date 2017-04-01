/*
** rand.c for rush in /home/ethan/rush/src/
**
** Made by Ethan MARGAILLAN
** Login   <ethan.margaillan@epitech.eu>
**
** Started on  Sat Apr  1 16:02:19 2017 Ethan MARGAILLAN
** Last update Sat Apr  1 16:47:53 2017 Ethan MARGAILLAN
*/

#include "scroller.h"

float       random_float()
{
    float   res;

    res = (float) rand() / (float) RAND_MAX;
    res = res * 2.0f - 1.0f;
    return (res);
}

sfVector2f      random_dir()
{
    sfVector2f  res;
    float       rnd;

    rnd = random_float();
    res.x = cos(rnd);
    res.y = sin(rnd);
    return (res);
}
