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

	int cursor = 0;//�J�[�\���̈ʒu
	int c;//����

	while (true) {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		printf("\t�s�J�^��t�@���^�W�[\n\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

		if (cursor == start) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			printf("\t�͂��߂���\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			printf("\t�͂��߂���\n\n");
		}

		if (cursor == con) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			printf("\t�Â�����\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			printf("\t�Â�����\n\n");
		}

		if (cursor == discription) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			printf("\t���߂�\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			printf("\t���߂�\n\n");
		}

		if (cursor == end) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			printf("\t�I���\n\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			printf("\t�I���\n\n");
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
	cout << "���L�[ �F�ړ�" << endl;
	cout << "enter�L�[�F����" << endl;
	cout << "esc�L�[�@�F�Q�[�����Ƀ��j���[��ʂ��J��" << endl;
	cout << "enter�L�[�Ŗ߂�" << endl;
	if (get_key() == ENTER) {
		return;
	}
}