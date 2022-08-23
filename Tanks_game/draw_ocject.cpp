#include "Func.h"


void draw_rect(POINT A, int h,int w, int size, int colors) {

	setcolor(colors);
	for (int i = 0; i <= size; i++)
	{
		rectangle(A.x + i, A.y + i, A.x+w- i, A.y +h- i);
	}
}
void map1(POINT A, int h, int w, int size, int colors) {
	//setcolor(colors);
	bar(0, 0, h, w);
	setcolor(colors);
	rectangle(A.x, A.y, A.x + h, A.y + w);
	//draw_rect(A, h, w, 1, colors);

	int b[] = { 50,50, 50,150, 100,150, 100,100, 150,100, 150,50 };
	fillpoly(6, b);
	int c[] = { 50,330, 50,430 ,150,430 ,150,380, 100,380, 100,330 };
	fillpoly(6, c);
	int d[] = { 330,380, 330,430, 430,430, 430,330, 380,330, 380,380 };
	fillpoly(6, d);
	int e[] = { 330,50,430,50,430,150,380,150,380,100,330,100 };
	fillpoly(6, e);
	rectangle(150, 150, 200, 200);
	rectangle(150, 280, 200, 330);
	rectangle(280, 280, 330, 330);
	rectangle(280, 150, 330, 200);
};

void display() {
	 setcolor(2);
	 rectangle(500, 150, 700, 190);
	 settextstyle(0, 0, 2);
	 outtextxy(550,165,L"Score: ");

	 //setcolor(15); settextstyle(1, 0, 2); setbkcolor(0); outtextxy(750, 405, L"ENTER"); setbkcolor(LIGHTGRAY);
	 //setcolor(15); outtextxy(870, 405, L"Pause");
	 //setcolor(15); settextstyle(1, 0, 2); setbkcolor(0); outtextxy(750, 455, L"SPACE"); setbkcolor(LIGHTGRAY);
	 //setcolor(15); outtextxy(870, 455, L"Bắn ");
	 //setcolor(15); settextstyle(1, 0, 2); setbkcolor(0); outtextxy(750, 505, L"ESC     "); setbkcolor(LIGHTGRAY);
	 //setcolor(15); outtextxy(870, 505, L"Thoát ");
	 //outtextxy(750, 600, L"Sử dụng các phím mũi ");
	 //outtextxy(750, 635, L"tên để di chuyển");
}
void about() {
	//while()
	setbkcolor(LIGHTGRAY);
	cleardevice();
	settextstyle(10, 0, 6); setcolor(15);
	outtextxy(260, 20, L"ABOUT");
	settextstyle(7, 0, 5); setcolor(9);
	outtextxy(20, 100, L"Tác giả: HOÀNG ANH QUÂN");
	outtextxy(20, 170, L"Tựa Game: TANKS GAME");
	outtextxy(20, 240, L"Thể loại: Diệt Tank ");
	getch();

}
void menu(int &mode) {

	WCHAR _menu[][30]{ L"NEW GAME",
		L"CONTINUE",
		L"HIGH CORE",
		L"ABOUT",
		L"QUIT GAME"
	};
int x = 0; int y = 0;
while (true) {

	cleardevice();
	setcolor(WHITE);
	settextstyle(1, 0, 2);

	//setbkcolor(1);
	x = mousex();
	y = mousey();

	for (int i = 0, j = 0; i < 5; i++, j += 60)
		rectangle(230, 65 + j, 485, 110 + j);

	for (int i = 0, j = 0; i < 5; i++, j += 60)
		outtextxy(260, 80 + j, _menu[i]);

	for (int i = 0, j = 0; i < 5; i++, j += 60)
		if (x > 230 && x < 485 && y>65 + j && y < 110 + j) {
			setcolor(6);
			outtextxy(260, 80 + j, _menu[i]);
		}

	if (ismouseclick(WM_LBUTTONDOWN)) {

		for (int i = 0, j = 0; i < 5; i++, j += 60)
			if (x > 230 && x < 485 && y>65 + j && y < 110 + j)
				mode = i;
		break;
	}
	clearmouseclick(WM_LBUTTONDOWN);
	delay(150);

}
}

void draw_loading()
{
	setbkcolor(BLACK);
	int loadding = 180;
	int count = 8;
	int prev = 180;
	//WCHAR text[] = { L"LOADING..." };
	while (loadding != 540)
	{
		loadding = 5 * count * count - 10 * count + 30;
		if (loadding > 540) loadding = 540;
		for (int i = prev; i < loadding; i++)
			for (int j = 210; j < 266; j++)
				putpixel(i, j, 12);
		//setcolor(12);
		rectangle(179, 209, 541, 266);
		settextstyle(4, 0, 4);
		outtextxy(170, 270, L" LOADING...");

		//	this_thread::sleep_for(500ms);
		delay(250);
		prev = loadding;
		count++;
	}
}

bool isTouch_wall(POINT pos, int x, int y) {//x la be rong trai-phai, yla be rong tren duoi
	//kiem 4 buoc tuong lon
	if (pos.x<2 || pos.x>HEIGHT - 30 +y*4 ) return true;
	if (pos.y<2 || pos.y>WIDTH - 30 +y*4) return true;
	//do rong cua xe


	//tuong trai tren
	if (pos.x > 50 + x && pos.x < 150 + y && pos.y> 50 + x && pos.y < 100 + y) 	return true;
	if (pos.x > 50 + x && pos.x < 100 && pos.y < 150 && pos.y> 50)			return true;
	//tuong trai duoi
	if (pos.x > 50 + x && pos.x < 150 + y && pos.y> 380 + x && pos.y < 430 + y)		return true;
	if (pos.x > 50 + x && pos.x < 100 + y && pos.y> 330 + x && pos.y <= 380 + y)	return true;
	//tuong  phai duoi
	if (pos.x > 330 + x && pos.x < 430 + y && pos.y> 50 + x && pos.y < 100 + y)		return true;
	if (pos.x > 380 + x && pos.x < 430 + y && pos.y < 150 && pos.y >= 100 + x)	return true;
	//tuong phai tren
	if (pos.x > 330 + x && pos.x < 430 + y && pos.y> 380 + x && pos.y < 430 + y)	return true;
	if (pos.x > 380 + x && pos.x < 430 + y && pos.y> 330 + x && pos.y <= 380 + y)	return true;
	// toa do o vuong//
	if (pos.x > 150 + x && pos.x < 200 + y && pos.y> 150 + x && pos.y < 200 + y)    return true;
	if (pos.x > 280 + x && pos.x < 330 + y && pos.y> 150 + x && pos.y < 200 + y)	return true;
	if (pos.x > 150 + x && pos.x < 200 + y && pos.y> 280 + x && pos.y < 330 + y)    return true;
	if (pos.x > 280 + x && pos.x < 330 + y && pos.y> 280 + x && pos.y < 330 + y)    return true;

	return false;

}