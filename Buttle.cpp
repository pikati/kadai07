#include "Buttle.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

void Buttle::battle_mgr(int map_id) {
	int c;
	for (int i = 0; i < 5; i++) {
		e[i].set_enemy(map_id, i);
		name[i] = e[i].get_name();
		max_hp[i] = e[i].get_hp();
		max_mp[i] = e[i].get_mp();
		atk[i] = e[i].get_atk();
		def[i] = e[i].get_def();
		matk[i] = e[i].get_matk();
		mdef[i] = e[i].get_mdef();
		spd[i] = e[i].get_spd();
		exp[i] = e[i].get_exp();
		money[i] = e[i].get_money();
	}
	
	draw();
	c = get_key();
}

void encount(int party) {
	
	switch (party)
	{
	case 1:

	default:
		break;
	}
}

int Buttle::draw() {
	enum {
		ch0,
		ch1,
		ch2
	};

	int ch = 0;//現在のチャプター
	int cursor = 0;//カーソルの位置
				   //int c;//文字

	while (true) {
		clear();
		switch (ch)
		{
		case ch0:
			ch++;
			break;
		case ch1:
			ch++;
			break;
		case ch2:
			break;
		default:
			return 1;
			break;
		}
	}
	return 1;
}

int Buttle::get_key() {
	int c;
	c = _getch();
	if (c == 0xe0) {
		return _getch();
	}
	else {
		return c;
	}
}

int Buttle::get_cursor(int c, int cursor) {
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

void Buttle::wait_key() {
	rewind(stdin);
	getchar();
}