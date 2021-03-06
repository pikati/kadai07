#include "Main_game.h"
#include "Feild.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

#define FELES 0
#define FELES_EAST 1
#define FELES_WEST 2
#define FELES_PLATEAU 3
#define FELES_HIGHWAY 4
#define FELES_MINE 5
#define PIES 6
#define KUCING 7

int Main_game::draw() {
	enum {
		ch0,
		ch1,
		ch2
	};

	int ch = 0;//現在のチャプター
	int cursor = 0;//カーソルの位置
	//int c;//文字
	Feild f;

	while (true) {
		clear();
		switch (ch)
		{
		case ch0:
			ch0_story();
			ch++;
			break;
		case ch1:
			ch1_story();
			ch++;
			break;
		case ch2:
			f.map_mgr();
			break;
		default:
			return 0;
			break;
		}
		
		
	}
}

int Main_game::get_key() {
	int c;
	c = _getch();
	if (c == 0xe0) {
		return _getch();
	}
	else {
		return c;
	}
}

int Main_game::get_cursor(int c, int cursor) {
	switch (c)
	{
	case UP:
		return --cursor;
	case DOWN:
		return ++cursor;
	default:
		return cursor;
	}
}

void Main_game::wait_key() {
	rewind(stdin);
	getchar();
}

void Main_game::ch0_story() {
	clear();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|ある日、ピカタんは夢を見た　　　　　　　　　　　　　　　　|" << endl;
	cout << "|それはひどく懐かしく、幸せな夢　　　　　　　　　　　　　　|" << endl;
	cout << "|でも悲しく、冷たい夢　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
	wait_key();
	clear();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|ここではないどこかで暮らした、　　　　　　　　　　　　　　|" << endl;
	cout << "|遠い日の記憶…　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
	wait_key();
	clear();
}

void Main_game::ch1_story() {
	clear();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|「またこの夢か…」　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
	wait_key();
	clear();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|「さて、今日は何をしようかな」　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
	wait_key();
	clear();
}