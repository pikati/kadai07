#include "Feild.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

/*マップの情報*/
#define WALL 0       //壁
#define NON 1        //ないもない床
#define WEAPON_SHOP 2//武器屋
#define ARMOR_SHOP 3 //防具屋
#define TOOL_SHOP 4  //道具屋
#define PLAYER 9     //プレイヤーの位置
/*マップのID*/
#define FELES 0
#define FELES_EAST 1
#define FELES_WEST 2
#define FELES_PLATEAU 3
#define FELES_HIGHWAY 4
#define FELES_MINE 5
#define PIES 6
#define KUCING 7
/*プレイヤーの向き管理*/
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

void Feild::map_mgr() {
	int i;
	int j;
	int memory_map_id = FELES;
	int memory_dir = LEFT;
	init();
	while (true) {
		clear();
		set_map(m_map, m_map_id);
		m_map_id = move_map(m_map, m_xy, m_map_id, m_dir);
		if (memory_map_id != m_map_id) {
			memory_map_id = m_map_id;
			continue;
		}
		draw_map(m_map, m_dir, m_xy);

		m_dir = get_key();
		tolk(m_map, m_xy, memory_dir);
		memory_dir = m_dir;

	}
}

void Feild::draw_map(int map[30][30], int dir, int xy[2]) {
	int i;
	int j;
	static int memory_dir = 0;
	map[xy[0]][xy[1]] = PLAYER;

	for (i = 0; i < 30; i++) {
		for (j = 0; j < 30; j++) {
			if (map[i][j] == WALL) {
				cout << "＊";
			}
			else if (map[i][j] == NON) {
				cout << "　";
			}
			else if (map[i][j] == WEAPON_SHOP) {
				cout << "武";
			}
			else if (map[i][j] == ARMOR_SHOP) {
				cout << "防";
			}
			else if (map[i][j] == TOOL_SHOP) {
				cout << "道";
			}
			else if (map[i][j] == PLAYER) {
				switch (dir)
				{
				case UP:
					cout << "∧";
					memory_dir = UP;
					break;
				case DOWN:
					cout << "Ｖ";
					memory_dir = DOWN;
					break;
				case LEFT:
					cout << "＜";
					memory_dir = LEFT;
					break;
				case RIGHT:
					cout << "＞";
					memory_dir = RIGHT;
					break;
				default:
					switch (memory_dir)
					{
					case UP:
						cout << "∧";
						break;
					case DOWN:
						cout << "Ｖ";
						break;
					case LEFT:
						cout << "＜";
						break;
					case RIGHT:
						cout << "＞";
						break;
					default:
						break;
					}
					break;
				}
			}
		}
		cout << endl;
	}
	cout << "X:" << xy[1] << " Y:" << xy[0] << endl;
	cout << "X:" << xy[1] << " Yの1つ上:" << xy[0] - 1 << endl;
	cout << "上:" << map[xy[0]-1][xy[1]];
	cout << " 下:" << map[xy[0]+1][xy[1]];
	cout << " 左:" << map[xy[0]][xy[1]-1];
	cout << " 右:" << map[xy[0]][xy[1]+1] << endl;
}

int Feild::move_map(int map[30][30], int xy[2], int id, int move) {

	switch (move)
	{
	case UP:
		if (map[xy[0] - 1][xy[1]] == NON) {
			xy[0]--;
		}
		break;
	case DOWN:
		if (map[xy[0] + 1][xy[1]] == NON) {
			xy[0]++;
		}
		break;
	case LEFT:
		if (map[xy[0]][xy[1] - 1] == NON) {
			xy[1]--;
		}
		break;
	case RIGHT:
		if (map[xy[0]][xy[1] + 1] == NON) {
			xy[1]++;
		}
		break;
	default:
		break;
	}

	switch (id)
	{
	case FELES:
		if (xy[1] == 13 && xy[0] == 29) {
			return FELES_HIGHWAY;
		}
		else if (xy[1] == 0 && xy[0] == 13) {
			xy[0] = 13;
			xy[1] = 29;
			return FELES_EAST;
		}
		else if (xy[1] == 29 && xy[0] == 13) {
			return FELES_WEST;
		}
		else if (xy[1] == 14 && xy[0] == 0) {
			return FELES_MINE;
		}
		break;
	case FELES_EAST:
		if (xy[1] == 13 && xy[0] == 29) {
			return FELES_HIGHWAY;
		}
		else if (xy[1] == 0 && xy[0] == 13) {
			//return PIES;
		}
		else if (xy[1] == 29 && xy[0] == 13) {
			xy[0] = 13;
			xy[1] = 0;
			return FELES;
		}
		break;
	default:
		break;
	}
	return id;
}

void Feild::tolk(int map[30][30], int xy[2], int dir) {

	if (m_dir == ENTER) {
		switch (dir)
		{
		case UP:
			switch (map[xy[0] - 1][xy[1]])//上
			{
			case WEAPON_SHOP:
				OutputDebugString("enter\n");
				weapon();
				break;
			case ARMOR_SHOP:
				//armor();
				break;
			case TOOL_SHOP:
				//tool();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void Feild::set_map(int map[30][30], int id) {
	int i;
	int j;

	switch (id)
	{
	case FELES:
	{
		int m[30][30] = {
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		    { 0,0,0,0,0,0,3,0,0,0,0,0,0,1,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0 },
		    { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
		    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		};
		for (i = 0; i < 30; i++) {
			for (j = 0; j < 30; j++) {
				map[i][j] = m[i][j];
			}
		}
	}
	break;
	case FELES_EAST:
	{
		int m[30][30] = {
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0 },
			{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
			{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
			{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
			{ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0 },
			{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
			{ 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0 },
			{ 0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0 },
			{ 0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		};
		for (i = 0; i < 30; i++) {
			for (j = 0; j < 30; j++) {
				map[i][j] = m[i][j];
			}
		}
	}
	break;
	default:
		break;
	}
}

void Feild::weapon() {
	clear();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|ここは武器屋だ　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|何の用だ　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
	wait_key();
	clear();
	select_trading();
}

int Feild::select_trading() {
	enum s {
		purchase,//購入
		sale,
		end
	};

	int cursor = 0;//カーソルの位置
	int c = 0;//文字

	while (true) {

		if (cursor == purchase) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\t買う\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			cout << "\t買う\n\n";
		}

		if (cursor == sale) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\t売る\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			cout << "\t売る\n\n";
		}

		if (cursor == end) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			cout << "\t終わる\n\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		}
		else {
			cout << "\t終わる\n\n";
		}

		c = get_key();
		cursor = get_cursor(c, cursor);
		switch (c)
		{
		case ENTER:
			if (cursor == purchase) {
				clear();
				buy(m_map_id);
			}
			if (cursor == sale) {
				clear();
				return 1;
			}
			if (cursor == end) {
				clear();
				return 0;
			}
			break;
		default:
			break;
		}
		clear();
	}
}

void Feild::buy(int id) {
	enum g {
		g0, g1, g2, g3, g4, g5, g6, g7,g8
	};

	string name[10];

	int cursor = 0;//カーソルの位置
	int c = 0;//文字
	switch (id)
	{
	case FELES:
		name[0] = "木の棒";
		name[1] = "木のやり";
		name[2] = "木のナックル";
		while (true) {

			if (cursor == g0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\t木の棒\tこうげき＋1\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			}
			else {
				cout << "\t木の棒\n\n";
			}

			if (cursor == g1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\t木のやり\tこうげき＋2\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			}
			else {
				cout << "\t木のやり\n\n";
			}

			if (cursor == g2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\t木のナックル\tこうげき＋1　\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			}
			else {
				cout << "\t木のナックル\n\n";
			}

			c = get_key();
			cursor = get_cursor(c, cursor);
			switch (c)
			{
			case ENTER:
				if (cursor == g0) {
					clear();
					decision(m_map_id, name[0]);
				}
				if (cursor == g1) {
					clear();
					decision(m_map_id, name[1]);
				}
				if (cursor == g2) {
					clear();
					decision(m_map_id, name[2]);
				}
				break;
			case 0x1b:
				return;
			default:
				break;
			}
			clear();
		}
		break;
	default:
		break;
	}
}

void Feild::decision(int id, string name) {
	int length = 0;
	int value = 0;
	int cursor = 0;//カーソルの位置
	int c = 0;//文字

	enum {
		yes,
		no
	};

	value = get_value(id);

	length = name.size();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|" << name << "は";
	space(length);
	cout << "|" << endl;
	cout << "|" << value << "円だ　　　　　　　　　　　　　　　　　　　　　　　 |" << endl;
	cout << "|これでいいのか？　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
	
	wait_key();
	
	switch (id)
	{
	case FELES:

		while (true) {

			if (cursor == yes) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\tはい\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			}
			else {
				cout << "\tはい\n\n";
			}

			if (cursor == no) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\tいいえ\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			}
			else {
				cout << "\tいいえ\n\n";
			}
			c = get_key();
			cursor = get_cursor(c, cursor);
			switch (c)
			{
			case ENTER:
				if (cursor == yes) {
					//買う処理
					clear();
					return;
				}
				if (cursor == no) {
					clear();
					return;
				}
				break;
			default:
				break;
			}
			clear();
		}
		break;
	default:
		break;
	}
}

int Feild::get_value(int id) {
	int value;
	//IDから売値や買値を設定だけど今は仮
	value = 100;
	return value;
}
void Feild::space(int length) {
	int i;
	for (i = 0; i <= 58 - (length + 4); i += 2) {
		cout << "　";
	}
}
int Feild::get_cursor(int c, int cursor) {
	switch (c)
	{
	case UP:
		cursor--;
		if (cursor < 0) {
			cursor = 0;
		}
		break;
	case DOWN:
		cursor++;
		if (cursor > 3) {
			cursor = 3;
		}
		break;
	default:
		break;
	}
	return cursor;
}

void Feild::init() {
	m_map_id = FELES;
	m_dir = LEFT;
	m_xy[0] = 14;
	m_xy[1] = 13;
}

int Feild::get_key() {
	int c;
	c = _getch();
	if (c == 0xe0) {
		return _getch();
	}
	else {
		return c;
	}
}

void Feild::wait_key() {
	rewind(stdin);
	getchar();
}