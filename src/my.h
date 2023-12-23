/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** setting up
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Window.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Window.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#ifndef TEST_H_
    #define TEST_H_
typedef struct dis {
    sfTexture  *texture2;
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *bird;
    sfVector2f pos_bird;
    int score;
    char life;
    int x;
} struct_t;

typedef struct curs {
    sfTexture *texture4;
    sfSprite *cursor;
} struct2_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_nbr_uns(int nb);
int cond3(int i, const char *format, va_list list);
int cond2(int i, const char *format, va_list list);
int cond(int i, const char *format, va_list list);
int mini_printf(const char *format, ...);
void manage_mouse_click(sfMouseButtonEvent event, struct_t *dis);
void display_sprite(struct_t *dis, sfEvent event, sfIntRect *rect);
void analyse_events(struct_t *dis, sfEvent event);
int display_background(struct_t *dis);
int display_text(struct_t *dis);
void init(struct_t *dis, sfEvent event, sfClock *, struct2_t *cursor);
sfIntRect set_rect(int top, int left, int width, int height);
int hunter(void);
int help(void);
sfIntRect set_rect2(void);
void time1(sfClock *clock, sfIntRect *rect);
void move_rect(sfIntRect *rect, int offset, int max_value);
void move2(struct_t *dis);
void display_cursor(struct_t *dis, struct2_t *cursor);
int display_text2(struct_t *dis);
void loop(struct_t *dis, sfEvent event, struct2_t curs);
int display_score(struct_t *dis);
char *int_to_string(struct_t *dis);
char *int_to_string2(struct_t *dis);
int display_life(struct_t *dis);
#endif /* TEST_H_ */
