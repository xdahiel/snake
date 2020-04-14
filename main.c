#include "snake.h"

int main()
{
	snake s = (snake)malloc(sizeof(SNAKE));
    HiddenConsoleCursor();
    menu_print();
    map_printf();
    s->x = 25, s->y = 24, s->next = NULL;
    food_generate(s);
    snake_move(s);
    return 0;
}