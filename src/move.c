/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** display struct
*/
#include "my.h"

sfIntRect set_rect2(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 200;
    rect.height = 200;
    return rect;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value)
        rect->left = 0;
    else
        rect->left += offset;
}

void move2(struct_t *dis)
{
    sfVector2f pos_bird = sfSprite_getPosition(dis->bird);
    float y = rand() % 700;

    sfSprite_move(dis->bird, (sfVector2f) { 12 + dis->x, 0});
    if (pos_bird.x >= 1900) {
        dis->life -= 1;
        sfSprite_setPosition( dis->bird, (sfVector2f) {0, y});
        dis->x ++;
    }
    if (dis->life <= 0)
        sfRenderWindow_close(dis->window);
}

void time1(sfClock *clock, sfIntRect *rect)
{
    sfTime elapsed;

    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 0.18) {
        move_rect(rect, 200, 400);
        sfClock_restart(clock);
    }
}
