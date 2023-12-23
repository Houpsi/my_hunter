/*
** EPITECH PROJECT, 2023
** csfml
** File description:
** display struct
*/

#include "my.h"

int display_background(struct_t *dis)
{
    sfSprite *fond = sfSprite_create();
    sfVector2f scale_fond = {0.75, 0.5};

    if (!fond)
        return 84;
    sfSprite_setTexture(fond, dis->texture2, sfTrue);
    sfSprite_setScale(fond, scale_fond);
    sfRenderWindow_drawSprite(dis->window, fond, NULL);
}

void display_sprite(struct_t *dis, sfEvent event, sfIntRect *rect)
{
    sfVector2f scale = {0.65, 0.65};

    sfSprite_setTexture(dis->bird, dis->texture, sfTrue);
    sfSprite_setTextureRect(dis->bird, *rect);
    sfSprite_setScale(dis->bird, scale);
    sfRenderWindow_drawSprite(dis->window, dis->bird, NULL);
}

int display_text(struct_t *dis)
{
    sfFont *font = sfFont_createFromFile("assert/04B_30__.TTF");
    sfVector2f text_pos = {260, 10};
    sfVector2f scale = {1.5, 1.5};
    sfText *text = sfText_create();
    char *scoreString = int_to_string(dis);

    if (!font)
        return 84;
    display_score(dis);
    sfText_setString(text, scoreString);
    sfText_setColor(text, sfBlack);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 26);
    sfText_setPosition(text, text_pos);
    sfText_setScale(text, scale);
    sfRenderWindow_drawText(dis->window, text, NULL);
}

int display_text2(struct_t *dis)
{
    sfFont *font = sfFont_createFromFile("assert/04B_30__.TTF");
    sfVector2f text_pos = {1860, 10};
    sfVector2f scale = {1.5, 1.5};
    sfText *text = sfText_create();
    char *scoreString = int_to_string2(dis);

    if (!font)
        return 84;
    display_life(dis);
    sfText_setString(text, scoreString);
    sfText_setColor(text, sfBlack);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 26);
    sfText_setPosition(text, text_pos);
    sfText_setScale(text, scale);
    sfRenderWindow_drawText(dis->window, text, NULL);
}

void display_cursor(struct_t *dis, struct2_t *curs)
{
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(dis->window);
    sfVector2f scale = {0.05, 0.05};

    sfRenderWindow_setMouseCursorVisible(dis->window, sfFalse);
    sfSprite_setScale(curs->cursor, scale);
    sfSprite_setPosition(curs->cursor,
        (sfVector2f){mousePosition.x, mousePosition.y});
    sfRenderWindow_drawSprite(dis->window, curs->cursor, NULL);
    sfRenderWindow_display(dis->window);
}
