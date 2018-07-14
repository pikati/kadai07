#include "Start.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define UP 72
#define DOWN 80
#define ENTER 13

int Start::draw() {
	enum s {
		start,
		con,//continue
		discription,
		end
	};

	int cursor = 0;//カーソルの位置
	int c;//文字

	while (true) {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		printf("\tピカタんファンタジー\n\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

		if (cursor == start) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			printf("\tはじめから\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			printf("\tはじめから\n\n");
		}

		if (cursor == con) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			printf("\tつづきから\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			printf("\tつづきから\n\n");
		}

		if (cursor == discription) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			printf("\tせつめい\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			printf("\tせつめい\n\n");
		}

		if (cursor == end) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			printf("\t終わる\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			printf("\t終わる\n\n");
		}

		c = get_key();
		cursor = get_cursor(c, cursor);
		switch (c)
		{
		case ENTER:
			if (cursor == start) {
				return 2;
			}
			if (cursor == con) {
				return 1;
			}
			if (cursor == discription) {
				dis();
			}
			if (cursor == end) {
				return -1;
			}
			break;
		default:
			break;
		}
		
		clear();
	}
}

int Start::get_key() {
	return _getch();
}

int Start::get_cursor(int c, int cursor) {
	switch (c)
	{
	case UP:
		cursor--;
		if (cursor < 0) {
			cursor = 0;
		}
		return cursor;
	case DOWN:
		cursor++;
		if (cursor > 3) {
			cursor = 3;
		}
		return cursor;
	default:
		return cursor;
	}
}

void Start::dis() {
	clear();
	cout << "矢印キー ：移動" << endl;
	cout << "enterキー：決定" << endl;
	cout << "escキー　：ゲーム中にメニュー画面を開く" << endl;
	cout << "enterキーで戻る" << endl;
	if (get_key() == ENTER) {
		return;
	}
}