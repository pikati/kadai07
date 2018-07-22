#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

int* Menu::menu_mgr(string name, int mhp, int hp, int mp, int mmp, int atk, int def, int matk, int mdef, int spd, int exp, int lev, int money, int item_id[99]) {
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
	for (int n = 0; n < 99; n++) {
		p_item_id[n] = item_id[n];
		p_item_name[n] = i.get_item_name(p_item_id[n]);
	}
	while (back == 1) {
		back = draw();
	}
	for (int i = 0; i < 99; i++) {
		item_id[i] = p_item_id[i];
	}
	status[0] = p_sta_m.max_hp[0];
	status[1] = p_sta_m.hp[0];
	status[2] = p_sta_m.max_mp[0];
	status[3] = p_sta_m.mp[0];
	status[4] = p_sta_m.atk[0];
	status[5] = p_sta_m.def[0];
	status[6] = p_sta_m.matk[0];
	status[7] = p_sta_m.mdef[0];
	status[8] = p_sta_m.spd[0];
	status[9] = p_sta_m.exp[0];
	status[10] = p_sta_m.lev[0];
	status[11] = p_sta_m.money;
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
	int c = 0;//•¶š

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
	//“Á‹Z‚âô•¶‚ğ•\¦
}

void Menu::draw_strength() {

	cout << "  QQQQQQQQQQQ " << endl;//‘SŠp7•¶š
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
	cout << "  [[[[[[[[[[[ " << endl;//‘SŠp7•¶š
	wait_key();
}

void Menu::draw_tool() {
	int c_num[99];
	for (int i = 0; i < 99; i++) {
		c_num[i] = i;
	}

	int cursor = 0;//ƒJ[ƒ\ƒ‹‚ÌˆÊ’u
	int c = 0;//•¶š

	while (true) {
		clear();
		cout << "\n\n";
		cout << "  QQQQQQQQQQ " << endl;
		if (cursor == c_num[0]) {
			cout << "|";
			hit_cursor();
			cout << p_item_name[c_num[0]];
			space(p_item_name[c_num[0]].size());
			nhit_corsor();
			cout << "|" << endl;
		}
		else {
			cout << "|" << p_item_name[c_num[0]];
			space(p_item_name[c_num[0]].size());
			cout << "|" << endl;
		}

		if (cursor == c_num[1]) {
			cout << "|";
			hit_cursor();
			cout << p_item_name[c_num[1]];
			space(p_item_name[c_num[1]].size());
			nhit_corsor();
			cout << "|" << endl;
		}
		else {
			cout << "|" << p_item_name[c_num[1]];
			space(p_item_name[c_num[1]].size());
			cout << "|" << endl;
		}

		if (cursor == c_num[2]) {
			cout << "|";
			hit_cursor(); 
			cout << p_item_name[c_num[2]];
			space(p_item_name[c_num[2]].size());
			nhit_corsor();
			cout << "|" << endl;
		}
		else {
			cout << "|" << p_item_name[c_num[2]];
			space(p_item_name[c_num[2]].size());
			cout << "|" << endl;
		}

		if (cursor == c_num[3]) {
			cout << "|";
			hit_cursor(); 
			cout << p_item_name[c_num[3]];
			space(p_item_name[c_num[3]].size());
			nhit_corsor();
			cout << "|" << endl;
		}
		else {
			cout << "|" << p_item_name[c_num[3]];
			space(p_item_name[c_num[3]].size());
			cout << "|" << endl;
		}

		if(cursor == c_num[4]) {
			cout << "|";
			hit_cursor(); 
			cout << p_item_name[c_num[4]];
			space(p_item_name[c_num[4]].size());
			nhit_corsor();
			cout << "|" << endl;
		}
		else {
			cout << "|" << p_item_name[c_num[4]];
			space(p_item_name[c_num[4]].size());
			cout << "|" << endl;
		}

		if (cursor == c_num[5]) {
			cout << "|" << p_item_name[c_num[5]];
			hit_cursor();
			space(p_item_name[c_num[5]].size());
			nhit_corsor();
			cout << "|" << endl;
		}
		else {
			cout << "|" << p_item_name[c_num[5]];
			space(p_item_name[c_num[5]].size());
			cout << "|" << endl;
		}

		if (cursor == c_num[6]) {
			cout << "|";
			hit_cursor(); 
			cout << p_item_name[c_num[6]];
			space(p_item_name[c_num[6]].size());
			nhit_corsor();
			cout << "|" << endl;
		}
		else {
			cout << "|" << p_item_name[c_num[6]];
			space(p_item_name[c_num[6]].size());
			cout << "|" << endl;
		}

		if (cursor == c_num[7]) {
			cout << "|";
			hit_cursor(); 
			cout << p_item_name[c_num[7]];
			space(p_item_name[c_num[7]].size());
			nhit_corsor();
			cout << "|" << endl;
		}
		else {
			cout << "|" << p_item_name[c_num[7]];
			space(p_item_name[c_num[7]].size());
			cout << "|" << endl;
		}

		if (cursor == c_num[8]) {
			cout << "|";
			hit_cursor(); 
			cout << p_item_name[c_num[8]];
			space(p_item_name[c_num[8]].size());
			nhit_corsor();
			cout << "|" << endl;
		}
		else {
			cout << "|" << p_item_name[c_num[8]];
			space(p_item_name[c_num[8]].size());
			cout << "|" << endl;
		}

		if (cursor == c_num[9]) {
			cout << "|";
			hit_cursor(); 
			cout << p_item_name[c_num[9]];
			space(p_item_name[c_num[9]].size());
			nhit_corsor();
			cout << "|" << endl;
		}
		else {
			cout << "|" << p_item_name[c_num[9]];
			space(p_item_name[c_num[9]].size());
			cout << "|" << endl;
		}

		if (cursor == c_num[10]) {
			cout << "|";
			hit_cursor(); 
			cout << p_item_name[c_num[10]];
			space(p_item_name[c_num[10]].size());
			nhit_corsor();
			cout << "|" << endl;
		}
		else {
			cout << "|" << p_item_name[c_num[10]];
			space(p_item_name[c_num[10]].size());
			cout << "|" << endl;
		}
		c = get_key();
		cursor = get_cursor(c, cursor);
		switch (c)
		{
		case ENTER:
			if (cursor == c_num[0]) {
				if (p_item_id[c_num[0]] > 0 && p_item_id[c_num[0]] < 160){
					equip(p_item_id[c_num[0]], c_num[0]);
				}
			}
			if (cursor == c_num[1]) {
				if (p_item_id[c_num[1]] > 0 && p_item_id[c_num[1]] < 160) {
					equip(p_item_id[c_num[1]], c_num[1]);
				}
			}
			if (cursor == c_num[2]) {
				if (p_item_id[c_num[2]] > 0 && p_item_id[c_num[2]] < 160) {
					equip(p_item_id[c_num[2]], c_num[2]);
				}
			}
			if (cursor == c_num[3]) {
				if (p_item_id[c_num[3]] > 0 && p_item_id[c_num[3]] < 160) {
					equip(p_item_id[c_num[3]], c_num[3]);
				}
			}
			if (cursor == c_num[4]) {
				if (p_item_id[c_num[4]] > 0 && p_item_id[c_num[4]] < 160) {
					equip(p_item_id[c_num[4]], c_num[4]);
				}
			}
			if (cursor == c_num[5]) {
				if (p_item_id[c_num[5]] > 0 && p_item_id[c_num[5]] < 160) {
					equip(p_item_id[c_num[5]], c_num[5]);
				}
			}
			if (cursor == c_num[6]) {
				if (p_item_id[c_num[6]] > 0 && p_item_id[c_num[6]] < 160) {
					equip(p_item_id[c_num[6]], c_num[6]);
				}
			}
			if (cursor == c_num[7]) {
				if (p_item_id[c_num[7]] > 0 && p_item_id[c_num[7]] < 160) {
					equip(p_item_id[c_num[7]], c_num[7]);
				}
			}
			if (cursor == c_num[8]) {
				if (p_item_id[c_num[8]] > 0 && p_item_id[c_num[8]] < 160) {
					equip(p_item_id[c_num[8]], c_num[8]);
				}
			}
			if (cursor == c_num[9]) {
				if (p_item_id[c_num[9]] > 0 && p_item_id[c_num[9]] < 160) {
					equip(p_item_id[c_num[9]], c_num[9]);
				}
			}
			if (cursor == c_num[10]) {
				if (p_item_id[c_num[10]] > 0 && p_item_id[c_num[10]] < 160) {
					equip(p_item_id[c_num[10]], c_num[10]);
				}
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
	for (i = 0; i <= 14 - length; i++) {
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

void Menu::equip(int id,int idx) {
	static int index[5] = { 0 };
	if (id > 0 && id < 40) {
		if (!p_sta_m.is_equip[0]) {
			p_item_name[idx] += "E";
			p_sta_m.atk[0] += i.get_item_atk(id);
			p_sta_m.is_equip[0] = true;
			index[0] = idx;
		}
		else {
			if (!p_item_name[index[0]].empty()) {
				p_item_name[index[0]].pop_back();
				p_sta_m.atk[0] -= i.get_item_atk(p_item_id[index[0]]);
				p_sta_m.is_equip[0] = false;
			}
		}
	}
}