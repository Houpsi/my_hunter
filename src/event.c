/*
** EPITECH PROJECT, 2023
** hunter
** File description:
** csfml
*/
#include "my.h"

void manage_mouse_click(sfMouseButtonEvent event, struct_t *dis)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(dis->bird);
    sfColor invisibleColor;
    sfColor visibleColor;
    float y = rand() % 700;

    if (event.button == sfMouseRight || event.button == sfMouseLeft) {
        if (sfFloatRect_contains(&bounds, event.x, event.y)) {
            invisibleColor = sfColor_fromRGBA(255, 255, 255, 0);
            sfSprite_setColor(dis->bird, invisibleColor);
            sfSprite_setPosition(dis->bird, (sfVector2f) {0, y});
            visibleColor = sfColor_fromRGBA(255, 255, 255, 255);
            sfSprite_setColor(dis->bird, visibleColor);
            sfRenderWindow_drawSprite(dis->window, dis->bird, NULL);
            dis->score += 1;
            dis->x ++;
        }
    }
}

void analyse_events(struct_t *dis, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(dis->window);
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, dis);
}
