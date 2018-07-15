#include "Main_game.h"
#include "Feild.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

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

	int ch = 0;//���݂̃`���v�^�[
	int cursor = 0;//�J�[�\���̈ʒu
	//int c;//����
	int map_id = FELES_EAST;
	int map[30][30] = { 0 };
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
			//cout << "a";
			f.set_map(map, map_id);
			//cout << "a";
			f.draw_map(map);
			
			//cout << "a";
			key_wait();
			break;
		default:
			return 0;
			break;
		}
		
		
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