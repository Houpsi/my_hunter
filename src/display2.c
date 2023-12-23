/*
** EPITECH PROJECT, 2023
** my hunter
** File description:
** display score and life
*/
#include "my.h"

char *int_to_string(struct_t *dis)
{
    int number = dis->score;
    int length = 1;
    int temp = number;
    char *result;

    temp = temp / 10;
    while (temp) {
        length++;
        temp = temp / 10;
    }
    result = (char *)malloc((length + 1) * sizeof(char));
    result[length] = '\0';
    length--;
    while (length >= 0) {
        result[length] = '0' + number % 10;
        number /= 10;
        length--;
    }
    return result;
}

char *int_to_string2(struct_t *dis)
{
    int number = dis->life;
    int length = 1;
    int temp = number;
    char *result;

    temp = temp / 10;
    while (temp)
        length++;
    result = (char *)malloc((length + 1) * sizeof(char));
    result[length] = '\0';
    length--;
    while (length == 0) {
        result[length] = '0' + number % 10;
        number /= 10;
        length--;
    }
    return result;
}

int display_score(struct_t *dis)
{
    sfFont *font = sfFont_createFromFile("assert/04B_30__.TTF");
    sfText *text2 = sfText_create();
    sfVector2f text_pos2 = {20, 10};
    sfVector2f scale2 = {1.5, 1.5};

    if (!font)
        return 84;
    sfText_setColor(text2, sfBlack);
    sfText_setFont(text2, font);
    sfText_setCharacterSize(text2, 26);
    sfText_setString(text2, "Score :");
    sfText_setPosition(text2, text_pos2);
    sfText_setScale(text2, scale2);
    sfRenderWindow_drawText(dis->window, text2, NULL);
}

int display_life(struct_t *dis)
{
    sfFont *font = sfFont_createFromFile("assert/04B_30__.TTF");
    sfText *text2 = sfText_create();
    sfVector2f text_pos2 = {1670, 10};
    sfVector2f scale2 = {1.5, 1.5};

    if (!font)
        return 84;
    sfText_setColor(text2, sfBlack);
    sfText_setFont(text2, font);
    sfText_setCharacterSize(text2, 26);
    sfText_setString(text2, "Life :");
    sfText_setPosition(text2, text_pos2);
    sfText_setScale(text2, scale2);
    sfRenderWindow_drawText(dis->window, text2, NULL);
}
