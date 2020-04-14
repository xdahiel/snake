#include "snake.h"


/****************************************************
	函数功能：隐藏控制台光标
	参数说明：无
	返回值  ：无
****************************************************/
void HiddenConsoleCursor()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(h, &cci);  //获取控制台光标信息
    cci.bVisible = 0;               //使不可见
    SetConsoleCursorInfo(h, &cci);  //设置控制台信息
}

/****************************************************
	函数功能：打印菜单， 接受并处理选项。
	参数说明：无
	返回值  ：无
****************************************************/
void menu_print()
{
	int op;
    gotoxy(10, 4);
    printf("欢迎来到贪吃蛇小游戏！(游戏时请开启大写模式，用WASD控制方向)\n");
    gotoxy(10, 10);
    printf("请选择难度：");
    gotoxy(10, 12);
    printf("1. 手残模式");
    gotoxy(10, 14);
    printf("2. 普通模式");
    gotoxy(10, 16);
    printf("3. 灵活模式");
    gotoxy(10, 18);
    printf("4. 死亡模式");
    gotoxy(10, 25);
    printf("请做出你的选择：");
    scanf("%d", &op);
    switch(op) {
        case 1: Difficulty_Level = 200; break;
        case 2: Difficulty_Level = 100; break;
        case 3: Difficulty_Level = 50; break;
        case 4: Difficulty_Level = 25; break;
    }
}


/****************************************************
	函数功能：打印蛇身
	参数说明：蛇的头指针
	返回值  ：无
****************************************************/
void print_snake(snake s)
{
    snake p = s;
    gotoxy(p->x, p->y);
    printf("*");
    while (p->next) {
        p = p->next;
        gotoxy(p->x, p->y);
        printf("o");
    }
}


/****************************************************
	函数功能：生成食物
	参数说明：蛇的头指针
	返回值  ：无
****************************************************/
void food_generate(snake s)
{
	int x, y;
    srand(time(NULL));
    x = rand()%(WIDTH_WALL-2) + 1;
    y = rand()%(LENTH_WALL-2) + 1;
    if (place_ok(x, y, s)) {
        x = rand()%(WIDTH_WALL-2) + 1;
        y = rand()%(LENTH_WALL-2) + 1;
    }
    gotoxy(x, y);
    printf("$");
    fd.x = x, fd.y = y;
}

/****************************************************
	函数功能：打印地图
	参数说明：无
	返回值  ：无
****************************************************/
void map_printf()
{
	int i, j;
    system("cls");
    for (i = 0; i < LENTH_WALL+1; ++i) {
        for (j = 0; j < WIDTH_WALL+1; ++j) {
            if (i == 0 || i == LENTH_WALL) Map[i][j] = '=';
            else if (j == 0 || j == WIDTH_WALL) Map[i][j] = '#';
            else Map[i][j] = ' ';
        }
    }
    for (i = 0; i <= LENTH_WALL; ++i) {
        for (j = 0; j <= WIDTH_WALL; ++j) printf("%c", Map[i][j]);
        printf("\n");
    }

    gotoxy(70, 10);
    printf("score: %d", game_score);
}


/****************************************************
	函数功能：打印游戏结束的画面
	参数说明：无
	返回值  ：无
****************************************************/
void game_over()
{
    system("cls");
    gotoxy(10, 10);
    printf("游戏结束！");
    gotoxy(10, 11);
    printf("您的分数为%d, 再接再厉！", game_score);
    gotoxy(10, 13);
    printf("按任意键结束……");
    getch();
    exit(0);
}