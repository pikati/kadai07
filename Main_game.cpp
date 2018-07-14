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

	int ch = 0;//���݂̃`���v�^�[
	int cursor = 0;//�J�[�\���̈ʒu
	int c;//����

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
	cout << "�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|������A�s�J�^��͖��������@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|����͂Ђǂ����������A�K���Ȗ��@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�ł��߂����A�₽�����@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[" << endl;
	key_wait();
	clear();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�����ł͂Ȃ��ǂ����ŕ�炵���A�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�������̋L���c�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[" << endl;
	key_wait();
	clear();
}

void Main_game::ch1_story() {
	clear();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�u�܂����̖����c�v�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[" << endl;
	key_wait();
	clear();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�u���āA�����͉������悤���ȁv�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "|�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@|" << endl;
	cout << "�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[" << endl;
	key_wait();
	clear();
}