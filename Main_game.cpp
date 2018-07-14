#include "Main_game.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

int Main_game::draw() {
	enum {
		ch0,
		ch1
	};

	int ch = 0;//現在のチャプター
	int cursor = 0;//カーソルの位置
	int c;//文字

	while (true) {

		switch (ch)
		{
		case ch0:
			ch0_story();
			ch++;
			break;
		case ch1:
			ch1_story();
			ch++;
		default:
			return 0;
			break;
		}
	
		c = get_key();
		cursor = get_cursor(c, cursor);
		
		clear();
	}
}

int Main_game::get_key() {
	return _getch();
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

void Main_game::key_wait() {
	if (get_key() == ENTER) {
		return;
	}
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
	key_wait();
	clear();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|ここではないどこかで暮らした、　　　　　　　　　　　　　　|" << endl;
	cout << "|遠い日の記憶…　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
	key_wait();
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
	key_wait();
	clear();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|「さて、今日は何をしようかな」　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
	key_wait();
	clear();
}