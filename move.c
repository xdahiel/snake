#include "snake.h"

/****************************************************
	函数功能：使控制台光标的位置到达指定的地方
	参数说明：横纵坐标
	返回值  ：无
****************************************************/
void gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


/****************************************************
	函数功能：使蛇朝着指定的方向移动一个单位
	参数说明：蛇的头指针和方向
	返回值  ：无
****************************************************/
void snake_forward_move(snake s, int dir)
{
    int x1, y1, x2, y2;
    snake p = s, q;
    x1 = p->x, y1 = p->y;
    switch(dir) {
        case 'W': --y1; break;
        case 'S': ++y1; break;
        case 'A': --x1; break;
        case 'D': ++x1; break;
    }
    while (p) {
        q = p;
        x2 = p->x, y2 = p->y;
        p->x = x1, p->y = y1;
        x1 = x2, y1 = y2;
        p = p->next;
    }
    if (is_eat_food(s)) {
        ++game_score;
        gotoxy(77, 10);
        printf("%d", game_score);
        snake k = (snake)malloc(sizeof(SNAKE));
        q->next = k;
        k->x = x1, k->y = y1, k->next = NULL;
        food_generate(s);
    }
    else {
        gotoxy(x1, y1);
        printf(" ");
    }
    print_snake(s, dir);
}

/****************************************************
	函数功能：控制蛇的移动和游戏的运行
	参数说明：蛇的头指针
	返回值  ：无
****************************************************/
void snake_move(snake s)
{
    int dir = 'W';
    int dr = 'S', db = dir;

    while (1) {
        if (kbhit()) dir = getch();

        if (dir == dr) dir = db;
        else {
            switch(dir) {
                case 'W': dr = 'S'; break;
                case 'A': dr = 'D'; break;
                case 'D': dr = 'A'; break;
                case 'S': dr = 'W'; break;
            }
        }

        db = dir;
        if (is_alive(s)) snake_forward_move(s, dir);
        else game_over();

        Sleep(Difficulty_Level);
    }
}

