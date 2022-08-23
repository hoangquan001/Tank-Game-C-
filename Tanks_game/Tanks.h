#pragma once
#include "Func.h"
#include "Bullet.h"
class TANK {
public:
	POINT pos;       //vi tri cua xe tank
	DIRECTION tt;    // huong di chuyen cua xe tang
	BULLETS bullets; // dan cua xe tang
	int color;
	bool shot;      // xe tang co lenh ban khong
	bool islive;    //xe tang da trung dan hay khong
	int speed_shoot; // toc do bam
	int speed_tank;	// toc do di chuyen
	//int mode;   //che do ban
	bool driver;  ///true may player false =bot
public:
	TANK() {//mac dinh la player
		pos = { 5,5 };
		tt = DOWN;
		driver = _PLAYER;
		islive = true;// chua trung dan ?
		shot = false;// co lenh ban
		speed_shoot = SPEED_SHOT + 1;
		speed_tank = SPEED_TANK;
		color = 4;
		bullets.color = color;
	}
	TANK(POINT POS, int speed_shoot, bool driver, int color) {
		pos = POS;
		tt = LEFT;
		islive = true;
		shot = true;
		this->speed_shoot = speed_shoot;
		speed_tank = SPEED_TANK;
		this->color = color;
		bullets.color = color;
		this->driver = driver;
	}

	void isDead(BULLETS pbullet) {
		for (int i = 0; i < pbullet.soluong_dan; i++)
		{
			POINT A = pbullet.dan[i].P_Bullet;
			POINT B = this->pos;
			if (A.x > B.x - 30 && A.x<B.x + 30 && A.y>B.y - 30 && A.y < B.y + 30)
			{
				//	pbullet.xoadan();
				this->islive = false;
				return;
			}
		}
	}
	void draw_tank()
	{
		draw_rect(this->pos, 30, 30, 0, this->color);
		rectangle(this->pos.x + 6, this->pos.y + 6, this->pos.x + 24, this->pos.y + 24);
		int x1 = 0, y1 = 0;
		int x2 = 0, y2 = 0;
		if (tt == UP) {
			x1 = 12; x2 = 17; y2 = 15;
		}
		if (tt == DOWN) {
			x1 = 12; x2 = 17; y2 = 15; y1 = 30;
		}
		if (tt == LEFT) {
			x2 = 17; y1 = 12; y2 = 17;
		}
		if (tt == RIGHT) {
			x1 = 15; x2 = 30; y1 = 12; y2 = 17;
		}
		rectangle(pos.x + x1, pos.y + y1, pos.x + x2, pos.y + y2);
	}

	void auto_Driver() {
		if (isTouch_wall(this->pos, -30, 0)) {
			int ran = rand() % 4;
			if (ran == 0) this->tt = UP;
			if (ran == 1) this->tt = DOWN;
			if (ran == 2) this->tt = LEFT;
			if (ran == 3) this->tt = RIGHT;
		}
		else
		{
			int ran1 = rand() % 100;
			if (ran1 == 0) this->tt = UP;
			if (ran1 == 1) this->tt = DOWN;
			if (ran1 == 2) this->tt = LEFT;
			if (ran1 == 3) this->tt = RIGHT;
		}
	}
	void draw_TankMove() {
		POINT pos_prev = pos;

		if (tt == UP)
			pos.y -= speed_tank;
		if (tt == DOWN)
			pos.y += speed_tank;
		if (tt == LEFT)
			pos.x -= speed_tank;
		if (tt == RIGHT)
			pos.x += speed_tank;
		//doi voi may thi bat che do auto drive
		if (this->driver == false)
			auto_Driver();
		//kiem tra co cham vao tuong hay khong ?neu co thi dung lai.
		if (isTouch_wall(pos, -30, 0))
			pos = pos_prev;

		//ve xe tang
		if (islive == true)
		{
			draw_tank();
			//xu ly dan
			if (this->speed_shoot <= SPEED_SHOT) this->speed_shoot++;
			else if (this->speed_shoot > SPEED_SHOT + 1) speed_shoot = SPEED_SHOT + 1;
			if (this->shot && this->speed_shoot > SPEED_SHOT)//&& tocdoban > SPEED_SHOT)
			{

				bullets.setSoluongdan();
				bullets.settrangthai(this->tt);
				bullets.setPoint(this->pos);
				if (this->driver == true)
					this->shot = false;
				speed_shoot = 0;
				//PlaySoundW(TEXT("shoot.wav"), NULL, SND_ASYNC);
			}

		}
		bullets.draw_bullets();

		// ve dan

	}
};