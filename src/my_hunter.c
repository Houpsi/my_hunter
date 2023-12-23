/*
** EPITECH PROJECT, 2023
** hunter
** File description:
** csfml
*/
#include "my.h"


void init(struct_t *dis, sfEvent event, sfClock *clock, struct2_t *cursor)
{
    sfIntRect rect = sfSprite_getTextureRect(dis->bird);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(dis->window);
    sfRenderWindow_clear(dis->window, sfWhite);
    display_background(dis);
    move2(dis);
    time1(clock, &rect);
    display_sprite(dis, event, &rect);
    display_text(dis);
    display_text2(dis);
    display_cursor(dis, cursor);
    sfRenderWindow_display(dis->window);
}

void loop(struct_t *dis, sfEvent event, struct2_t curs)
{
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(dis->window)) {
        while (sfRenderWindow_pollEvent(dis->window, &event))
            analyse_events(dis, event);
        init(dis, event, clock, &curs);
    }
    sfClock_destroy(clock);
    sfSprite_destroy(dis->bird);
    sfSprite_destroy(curs.cursor);
    sfTexture_destroy(dis->texture);
    sfTexture_destroy(curs.texture4);
    sfRenderWindow_destroy(dis->window);
}

int hunter(void)
{
    sfVideoMode mode = {1920, 1080, 64};
    sfEvent event;
    float y = rand() % 700;
    sfIntRect rect = set_rect2();
    struct_t dis = {sfTexture_createFromFile("assert/fond.jpg", NULL),
        sfRenderWindow_create(mode, "My Window", sfResize | sfClose, NULL),
        sfTexture_createFromFile("assert/birds.png", NULL),
        sfSprite_create(), {0, y}, 0, 3, 0};
    struct2_t curs = {sfTexture_createFromFile("assert/cursor.png",
        NULL), sfSprite_create()};

    sfSprite_setTexture(curs.cursor, curs.texture4, sfTrue);
    sfSprite_setTextureRect(dis.bird, rect);
    sfRenderWindow_setFramerateLimit(dis.window, 60);
    srand( time( NULL));
    sfSprite_setPosition(dis.bird, (sfVector2f){0, y});
    loop(&dis, event, curs);
}

int main(int argc, char **argv, char **env)
{
    if (env[0] == NULL)
        return 84;
    if (argc == 1)
        hunter();
    if (argc == 2 && argv[1][1] == 'h')
        help();
    return 0;
}
