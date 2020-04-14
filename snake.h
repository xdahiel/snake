#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>


#define LENTH_WALL 25   //墙的长度
#define WIDTH_WALL 50   //墙的宽度

//用单链表定义蛇
struct Snake{
	int x, y;
	struct Snake* next;
};
typedef struct Snake* snake;	//蛇指针
typedef struct Snake SNAKE;		//蛇


//用结构体定义食物
typedef struct Food{
    int x, y;
}food;

/*************全局变量*********************/
int game_score;							//游戏得分
char Map[LENTH_WALL+1][WIDTH_WALL+1];	//地图
int Difficulty_Level;					//难度等级
food fd;								//食物


extern void menu_print();
extern void print_snake(snake s);
extern int place_ok(int x, int y, snake s);
extern void food_generate(snake s);
extern void map_printf();
extern void game_over();
extern int is_eat_food(snake s);
extern int is_alive(snake s);
extern void snake_forward_move(snake s, int dir);
extern void snake_move(snake s);
extern void HiddenConsoleCursor();
extern void gotoxy(int x, int y);


#endif