#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

int* Menu::menu_mgr(string name, int mhp, int hp, int mp, int mmp, int atk, int def, int matk, int mdef, int spd, int exp, int lev, int money, int item[99]) {
	int back = 1;
	i.set_items();
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
	for (int i = 0; i < 99; i++) {
		p_item[i] = item[i];
		cout << "p_item" << p_item[i] << endl << "item" << item[i] << endl;
	}
	wait_key();
	
	while (back == 1) {
		back = draw();
	}
	for (int i = 0; i < 99; i++) {
		item[i] = p_item[i];
	}
	return status;
}

int Menu::draw() {
	enum s {
		tolk,//‚Í‚È‚·
		strength,//‚Â‚æ‚³
		equipment,//‚»‚¤‚Ñ
		spell,//‚¶‚ã‚à‚ñ
		tool,//‚Ç‚¤‚®
		check//‚µ‚ç‚×‚é
	};

	int cursor = 0;//ƒJ[ƒ\ƒ‹‚ÌˆÊ’u
	int c = 0;//•¶Žš

	while (true) {
		clear();
		cout << "\n\n";
		if (cursor == tolk) {
			hit_cursor();
			cout << "\t‚Í‚È‚·";
			nhit_corsor();
		}
		else {
			cout << "\t‚Í‚È‚·";
		}

		if (cursor == spell) {
			hit_cursor();
			cout << "\t‚¶‚ã‚à‚ñ\n\n";
			nhit_corsor();
		}
		else {
			cout << "\t‚¶‚ã‚à‚ñ\n\n";
		}

		if (cursor == strength) {
			hit_cursor();
			cout << "\t‚Â‚æ‚³";
			nhit_corsor();
		}
		else {
			cout << "\t‚Â‚æ‚³";
		}

		if (cursor == tool) {
			hit_cursor();
			cout << "\t‚Ç‚¤‚®\n\n";
			nhit_corsor();
		}
		else {
			cout << "\t‚Ç‚¤‚®\n\n";
		}

		if (cursor == equipment) {
			hit_cursor();
			cout << "\t‚»‚¤‚Ñ";
			nhit_corsor();
		}
		else {
			cout << "\t‚»‚¤‚Ñ";
		}

		if (cursor == check) {
			hit_cursor();
			cout << "\t‚µ‚ç‚×‚é\n\n";
			nhit_corsor();
		}
		else {
			cout << "\t‚µ‚ç‚×‚é\n\n";
		}
		c = get_key();
		cursor = get_cursor(c, cursor);
		switch (c)
		{
		case ENTER:
			if (cursor == tolk) {
				//˜b‚·ˆ—
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
				//’²‚×‚éˆ—
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
	//“Á‹Z‚âŽô•¶‚ð•\Ž¦
}

void Menu::draw_strength() {

	cout << "  QQQQQQQQQQQ " << endl;//‘SŠp7•¶Žš
	cout << " |‚È‚Ü‚¦@F" << p_sta_m.name[0];
	space(get_length(p_sta_m.name[0]));
	cout << " |" << endl;
	cout << " |ƒŒƒxƒ‹@F" << p_sta_m.lev[0];
	space(get_length(p_sta_m.lev[0]));
	cout << " |" << endl;
	cout << " |HP@@@F" << p_sta_m.hp[0] << "/" << p_sta_m.max_hp[0];
	//space(get_length(p_sta_m.max_hp[0]));
	space(get_length(p_sta_m.hp[0]) + get_length(p_sta_m.max_hp[0]) + 1);
	cout << " |" << endl;
	cout << " |MP@@@F" << p_sta_m.mp[0] << "/" << p_sta_m.max_mp[0];
	//space(get_length(p_sta_m.max_mp[0]));
	space(get_length(p_sta_m.mp[0]) + get_length(p_sta_m.max_mp[0]) + 1);
	cout << " |" << endl;
	cout << " |‚±‚¤‚°‚«F" << p_sta_m.atk[0];
	space(get_length(p_sta_m.atk[0]));
	cout << " |" << endl;
	cout << " |‚Ú‚¤‚¬‚åF" << p_sta_m.def[0];
	space(get_length(p_sta_m.def[0]));
	cout << " |" << endl;
	cout << " |‚Ü‚Ù‚¤‚±F" << p_sta_m.matk[0];
	space(get_length(p_sta_m.matk[0]));
	cout << " |" << endl;
	cout << " |‚Ü‚Ù‚¤‚ÚF" << p_sta_m.mdef[0];
	space(get_length(p_sta_m.mdef[0]));
	cout << " |" << endl;
	cout << " |‚·‚Î‚â‚³F" << p_sta_m.spd[0];
	space(get_length(p_sta_m.spd[0]));
	cout << " |" << endl;
	cout << " |‚¯‚¢‚¯‚ñF" << p_sta_m.exp[0];
	space(get_length(p_sta_m.exp[0]));
	cout << " |" << endl;
	cout << " |‚¨‚©‚Ë@F" << p_sta_m.money;
	space(get_length(p_sta_m.money));
	cout << " |" << endl;
	cout << "  [[[[[[[[[[[ " << endl;//‘SŠp7•¶Žš
	wait_key();
}

void Menu::draw_tool() {
	enum s {
		i1, i2, i3,	i4, i5, i6
	};

	int cursor = 0;//ƒJ[ƒ\ƒ‹‚ÌˆÊ’u
	int c = 0;//•¶Žš

	while (true) {
		clear();
		cout << "\n\n";

		cout << "\n\n";
		cout << "  QQQQQQQQQQ " << endl;
		if (cursor == i1) {
			hit_cursor();
			cout << "|" << i.get_item_name(p_item[i1]);
			space(i.get_item_name(p_item[i1]).size());
			cout << "|" << endl;
			nhit_corsor();
		}
		else {
			cout << "|" << i.get_item_name(p_item[i1]);
			space(i.get_item_name(p_item[i1]).size());
			cout << "|" << endl;
		}

		if (cursor == i2) {
			hit_cursor();
			cout << "|" << i.get_item_name(p_item[i2]);
			space(i.get_item_name(p_item[i2]).size());
			cout << "|" << endl;
			nhit_corsor();
		}
		else {
			cout << "|" << i.get_item_name(p_item[i2]);
			space(i.get_item_name(p_item[i2]).size());
			cout << "|" << endl;
		}

		if (cursor == i3) {
			hit_cursor();
			cout << "|" << i.get_item_name(p_item[i3]);
			space(i.get_item_name(p_item[i3]).size());
			cout << "|" << endl;
			nhit_corsor();
		}
		else {
			cout << "|" << i.get_item_name(p_item[i3]);
			space(i.get_item_name(p_item[i3]).size());
			cout << "|" << endl;
		}

		if (cursor == i4) {
			hit_cursor();
			cout << "|" << i.get_item_name(p_item[i4]);
			space(i.get_item_name(p_item[i4]).size());
			cout << "|" << endl;
			nhit_corsor();
		}
		else {
			cout << "|" << i.get_item_name(p_item[i4]);
			space(i.get_item_name(p_item[i4]).size());
			cout << "|" << endl;
		}

		if(cursor == i5) {
			hit_cursor();
			cout << "|" << i.get_item_name(p_item[i5]);
			space(i.get_item_name(p_item[i5]).size());
			cout << "|" << endl;
			nhit_corsor();
		}
		else {
			cout << "|" << i.get_item_name(p_item[i5]);
			space(i.get_item_name(p_item[i5]).size());
			cout << "|" << endl;
		}

		if (cursor == i6) {
			hit_cursor();
			cout << "|" << i.get_item_name(p_item[i6]);
			space(i.get_item_name(p_item[i6]).size());
			cout << "|" << endl;
			nhit_corsor();
		}
		else {
			cout << "|" << i.get_item_name(p_item[i6]);
			space(i.get_item_name(p_item[i6]).size());
			cout << "|" << endl;
		}
		c = get_key();
		cursor = get_cursor(c, cursor);
		switch (c)
		{
		case ENTER:
			if (cursor == i1) {
				//˜b‚·ˆ—
			}
			if (cursor == i2) {
				draw_spell();
			}
			if (cursor == i3) {
				draw_strength();
			}
			if (cursor == i4) {
				draw_tool();
			}
			if (cursor == i5) {
				draw_equ();
			}
			if (cursor == i6) {
				//’²‚×‚éˆ—
			}
			break;
		case 0x1b:
			return;
		default:
			break;
		}
		clear();
	} 
}

void Menu::draw_equ() {
	
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

void Menu::hit_cursor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}

void Menu::nhit_corsor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
}