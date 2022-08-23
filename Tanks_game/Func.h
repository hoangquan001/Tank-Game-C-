#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BGI/graphics.h"
#include <cwchar>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <vector>
#define HEIGHT 480
#define WIDTH 480
#define SPEED_DAN 10
#define SPEED_TANK 5
#define SPEED_TANK_0 0
#define SPEED_SHOT 15
#define SPEED_SHOT_BOT 25
#define _PLAYER 1
#define _BOT 0
//struct POINT
//{
//	int x; int y;
//
//};
enum DIRECTION
{
	UP, DOWN, LEFT, RIGHT
};


void draw_rect(POINT A, int h, int w, int size, int colors);
void map1(POINT A, int h, int w, int size, int colors); 
void display();
bool isTouch_wall(POINT pos,int x,int y); 
void draw_loading();
void about();
void menu(int &mode);