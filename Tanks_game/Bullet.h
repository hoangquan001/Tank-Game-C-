#pragma once
#include "Func.h"


struct BULLET {
	DIRECTION tt;
	POINT P_Bullet;
	bool isLive;
};

class BULLETS {
public:
	BULLET dan[100];
	int soluong_dan;
	int color;
public:
	BULLETS() {
		this->soluong_dan = 0;
		for (int i = 0; i < 100; i++)
		{
			dan[i].isLive = true;
		}
		color = 2;
	}
	BULLETS(int color) {
		this->soluong_dan = 0;
		for (int i = 0; i < 100; i++)
		{
			dan[i].isLive = true;
		}
		this->color = color;
	}
	~BULLETS()
	{

	}
	void settrangthai(DIRECTION t=DOWN) {
		dan[soluong_dan - 1].tt = t;
	}
	void setSoluongdan() {
		this->soluong_dan++;
	}
	void setPoint(POINT p) {
		dan[soluong_dan - 1].P_Bullet.x= p.x+15;
		dan[soluong_dan - 1].P_Bullet.y = p.y + 15;

	}


	void draw_bullets();
	void xoadan();
};

//
void BULLETS::draw_bullets() {
	this->xoadan();
	for (int i = 0; i < this->soluong_dan; i++)
	{
		if (isTouch_wall(dan[i].P_Bullet,-5,5))
		{
			dan[i].isLive = false;
			continue;
		}
		if (dan[i].tt == UP)
			dan[i].P_Bullet.y -= SPEED_DAN;
		if (dan[i].tt == DOWN)
			dan[i].P_Bullet.y += SPEED_DAN;
		if (dan[i].tt == LEFT)
			dan[i].P_Bullet.x -= SPEED_DAN;
		if (dan[i].tt == RIGHT)
			dan[i].P_Bullet.x += SPEED_DAN;
		setcolor(this->color);

			circle(dan[i].P_Bullet.x , dan[i].P_Bullet.y ,5);
	}
}
void BULLETS::xoadan()
{
	int count = 0;
	int j = 0;
	for (int i = 0; i < soluong_dan; i++)
		if (dan[i].isLive == false)
		{
			count++;
			
			dan[i].isLive = true;
		}
		else dan[j++] = dan[i];
	soluong_dan -= count;
}
