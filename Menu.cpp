#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

int* Menu::menu_mgr(string name, int mhp, int hp, int mp, int mmp, int atk, int def, int matk, int mdef, int spd, int exp, int lev, int money) {
	int back = 1;
	p_sta_m.name[0] = name;
	status[0] = p_sta_m.max_hp[0] = mhp;
	status[1] = p_sta_m.hp[0] = hp;
	status[2] = p_sta_m.max_mp[0] = mmp;
	status[3] = p_sta_m.mp[0] = mp;
	status[4] = p_sta_m.atk[0] = atk;
	status[5] = p_sta_m.def[0] = def;
	status[6] = p_sta_m.matk[0] = matk;
	status[7] = p_sta_m.mdef[0] = mdef;
	status[8] = p_sta_m.spd[0] = spd;
	status[9] = p_sta_m.exp[0] = exp;
	status[10] = p_sta_m.lev[0] = lev;
	status[11] = p_sta_m.money = money;
	while (back == 1) {
		back = draw();
	}
	return status;
}

int Menu::draw() {
	enum s {
		tolk,//はなす
		strength,//つよさ
		equipment,//そうび
		spell,//じゅもん
		tool,//どうぐ
		check//しらべる
	};

	int cursor = 0;//カーソルの位置
	int c = 0;//文字

	while (true) {
		clear();
		cout << "\n\n";
		if (cursor == tolk) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\tはなす";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			cout << "\tはなす";
		}

		if (cursor == spell) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\tじゅもん\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			cout << "\tじゅもん\n\n";
		}

		if (cursor == strength) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\tつよさ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			cout << "\tつよさ";
		}

		if (cursor == tool) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\tどうぐ\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			cout << "\tどうぐ\n\n";
		}

		if (cursor == equipment) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\tそうび";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			cout << "\tそうび";
		}

		if (cursor == check) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\tしらべる\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			cout << "\tしらべる\n\n";
		}
		c = get_key();
		cursor = get_cursor(c, cursor);
		switch (c)
		{
		case ENTER:
			if (cursor == tolk) {
				//話す処理
			}
			if (cursor == spell) {
				draw_spell();
			}
			if (cursor == strength) {
				draw_strength();
			}
			if (cursor == tool) {
				draw_tool();
			}
			if (cursor == equipment) {
				draw_equ();
			}
			if (cursor == check) {
				//調べる処理
			}
			break;
		case 0x1b:
			return 0;
		default:
			break;
		}
		clear();
	}
}

int Menu::get_key() {
	int c;
	c = _getch();
	if (c == 0xe0) {
		return _getch();
	}
	else {
		return c;
	}
}

int Menu::get_cursor(int c, int cursor) {
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
		if (cursor > 5) {
			cursor = 5;
		}
		return cursor;
	case LEFT:
		cursor -= 3;
		if (cursor < 0) {
			cursor += 3;
		}
		return cursor;
	case RIGHT:
		cursor += 3;
		if (cursor > 5) {
			cursor -= 3;
		}
		return cursor;
	default:
		return cursor;
	}
}

void Menu::wait_key() {
	rewind(stdin);
	getchar();
}

void Menu::clear() {
	system("cls");
}

void Menu::draw_spell() {
	//特技や呪文を表示
}

void Menu::draw_strength() {

	cout << "  ＿＿＿＿＿＿＿＿＿＿＿ " << endl;//全角7文字
	cout << " |なまえ　：" << p_sta_m.name[0];
	space(get_length(p_sta_m.name[0]));
	cout << " |" << endl;
	cout << " |レベル　：" << p_sta_m.lev[0];
	space(get_length(p_sta_m.lev[0]));
	cout << " |" << endl;
	cout << " |HP　　　：" << p_sta_m.hp[0] << "/" << p_sta_m.max_hp[0];
	//space(get_length(p_sta_m.max_hp[0]));
	space(get_length(p_sta_m.hp[0]) + get_length(p_sta_m.max_hp[0]) + 1);
	cout << " |" << endl;
	cout << " |MP　　　：" << p_sta_m.mp[0] << "/" << p_sta_m.max_mp[0];
	//space(get_length(p_sta_m.max_mp[0]));
	space(get_length(p_sta_m.mp[0]) + get_length(p_sta_m.max_mp[0]) + 1);
	cout << " |" << endl;
	cout << " |こうげき：" << p_sta_m.atk[0];
	space(get_length(p_sta_m.atk[0]));
	cout << " |" << endl;
	cout << " |ぼうぎょ：" << p_sta_m.def[0];
	space(get_length(p_sta_m.def[0]));
	cout << " |" << endl;
	cout << " |まほうこ：" << p_sta_m.matk[0];
	space(get_length(p_sta_m.matk[0]));
	cout << " |" << endl;
	cout << " |まほうぼ：" << p_sta_m.mdef[0];
	space(get_length(p_sta_m.mdef[0]));
	cout << " |" << endl;
	cout << " |すばやさ：" << p_sta_m.spd[0];
	space(get_length(p_sta_m.spd[0]));
	cout << " |" << endl;
	cout << " |けいけん：" << p_sta_m.exp[0];
	space(get_length(p_sta_m.exp[0]));
	cout << " |" << endl;
	cout << " |おかね　：" << p_sta_m.money;
	space(get_length(p_sta_m.money));
	cout << " |" << endl;
	cout << "  ーーーーーーーーーーー " << endl;//全角7文字
	wait_key();
}

void Menu::draw_tool() {
	//道具を表示
}

void Menu::draw_equ() {
	//装備画面を表示
}

int Menu::get_length(int status) {
	int count = 0;
	while (true) {
		status /= 10;
		count++;
		if (status == 0) {
			return count;
		}
	}
}

int Menu::get_length(string name) {
	return name.size();
}

void Menu::space(int length) {
	int i;
	for (i = 0; i <= 14 - length - 4; i++) {
		cout << " ";
	}
}