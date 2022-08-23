// SOURCE TANKS GAME PRODUCT BY QUANHOANG
#include "Func.h"
#include "Bullet.h"
#include "Tanks.h"
#include <thread>
using namespace std;
int main(int argc, char* argv[]){

	char tilte[] = { "TANK GAME" }; //tieu de cho game
	initwindow(730, 495,tilte);			//khoi tao windows
		
	int a=0;
	bool Pause=false;
	TANK player;

	TANK bota({ 430,20 }, SPEED_SHOT_BOT, _BOT, 5);
	TANK botb({ 430,430 }, SPEED_SHOT_BOT, _BOT, 5);
	TANK botc({ 20,430 }, SPEED_SHOT_BOT, _BOT, 5);
	vector <TANK> bot;
	bot.push_back(bota);
	bot.push_back(botc);
	bot.push_back(botb);

	DIRECTION tt = DOWN;
	bool GAMEOVER = FALSE;

	//char* s = new char[5];
	draw_loading();
	int mode;
	menu(mode);
	setbkcolor(LIGHTGRAY);
	cleardevice();



	if (mode == 4);
	if (mode == 3) about();
	if(mode==0)
	while (!GAMEOVER)
	{
		cleardevice();
		//setcolor(3);

		map1({ 0, 0}, HEIGHT, WIDTH, 5, 3);
		display();
		//dieu kien xa tang
		if (kbhit()) {
			 a = getch();
			if (a == 72) tt = UP;
			if (a == 80) tt = DOWN;
			if (a == 75) tt = LEFT;
			if (a == 77) tt = RIGHT;
			if (a == VK_SPACE)
				player.shot = true;
			if (a == VK_ESCAPE) break;
			if (a == 13) Pause = true;
			player.tt = tt;
		}
		//vexetang

		for (int i = 0; i < bot.size(); i++)
			player.isDead(bot[i].bullets);

		for (int i = 0; i < bot.size(); i++)
			bot[i].isDead(player.bullets);
		
	

		for (int i = 0; i < bot.size(); i++)
			bot[i].draw_TankMove();
		player.draw_TankMove();
		this_thread::sleep_for(0.02s);
	
		if (!player.islive)GAMEOVER = TRUE;
		if (Pause) {
			getch();
			Pause = false;
		}
	}

	closegraph();
	// pause screen	
	return 0;
}

