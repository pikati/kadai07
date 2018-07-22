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
	int memory_map_id = FELES;
	int memory_dir = LEFT;
	int *status;
	Menu menu;

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
		cout << p_sta.money << endl;
		m_dir = get_key();
		if (m_dir == 0x1b) {
			status = menu.menu_mgr(p_sta.name[0], p_sta.max_hp[0], p_sta.hp[0], p_sta.max_mp[0], p_sta.mp[0], p_sta.atk[0], 
				p_sta.def[0], p_sta.matk[0], p_sta.mdef[0], p_sta.spd[0], p_sta.exp[0], p_sta.lev[0], p_sta.money, p_sta.item_id);
			p_sta.max_hp[0] = status[0];
			p_sta.hp[0] = status[1];
			p_sta.max_mp[0] = status[2];
			p_sta.mp[0] = status[3];
			p_sta.atk[0] = status[4];
			p_sta.def[0] = status[5];
			p_sta.matk[0] = status[6];
			p_sta.mdef[0] = status[7];
			p_sta.spd[0] = status[8];
			p_sta.exp[0] = status[9];
			p_sta.lev[0] = status[10];
			p_sta.money = status[11];
			continue;
		}
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
		cout << "\n\n";
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

void Feild::buy(int ID) {
	enum g {
		g0, g1, g2, g3, g4, g5, g6, g7, g8
	};

	int cursor = 0;//カーソルの位置
	int c = 0;//文字

	i.set_items();
	
	set_item_infos(0, 1);
	set_item_infos(1, 2);
	set_item_infos(2, 3);

	switch (ID)
	{
	case FELES:
		
		while (true) {
			cout << "\n\n";
			if (cursor == g0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\t" << name[g0];
				if (atk[g0] != 0) {
					cout << "\tこうげき" << atk[g0];
				}
				if (def[g0] != 0) {
					cout << "\tぼうぎょ" << def[g0];
				}
				if (matk[g0] != 0) {
					cout << "\tまほうこうげき" << matk[g0];
				}
				if (mdef[g0] != 0) {
					cout << "\tまほうぼうぎょ" << mdef[g0];
				}
				if (spd[g0] != 0) {
					cout << "\tすばやさ" << spd[g0];
				}
				if (value[g0] != 0) {
					cout << "\tねだん：" << value[g0];
				}
				cout << "\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			}
			else {
				cout << "\t" << name[g0];
				if (atk[g0] != 0) {
					cout << "\tこうげき" << atk[g0];
				}
				if (def[g0] != 0) {
					cout << "\tぼうぎょ" << def[g0];
				}
				if (matk[g0] != 0) {
					cout << "\tまほうこうげき" << matk[g0];
				}
				if (mdef[g0] != 0) {
					cout << "\tまほうぼうぎょ" << mdef[g0];
				}
				if (spd[g0] != 0) {
					cout << "\tすばやさ" << spd[g0];
				}
				if (value[g0] != 0) {
					cout << "\tねだん：" << value[g0];
				}
				cout << "\n\n";
			}

			if (cursor == g1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\t" << name[g1];
				if (atk[g1] != 0) {
					cout << "\tこうげき" << atk[g1];
				}
				if (def[g1] != 0) {
					cout << "\tぼうぎょ" << def[g1];
				}
				if (matk[g1] != 0) {
					cout << "\tまほうこうげき" << matk[g1];
				}
				if (mdef[g1] != 0) {
					cout << "\tまほうぼうぎょ" << mdef[g1];
				}
				if (spd[g1] != 0) {
					cout << "\tすばやさ" << spd[g1];
				}
				if (value[g1] != 0) {
					cout << "\tねだん：" << value[g1];
				}
				cout << "\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			}
			else {
				cout << "\t" + name[g1];
				if (atk[g1] != 0) {
					cout << "\tこうげき" << atk[g1];
				}
				if (def[g1] != 0) {
					cout << "\tぼうぎょ" << def[g1];
				}
				if (matk[g1] != 0) {
					cout << "\tまほうこうげき" << matk[g1];
				}
				if (mdef[g1] != 0) {
					cout << "\tまほうぼうぎょ" << mdef[g1];
				}
				if (spd[g1] != 0) {
					cout << "\tすばやさ" << spd[g1];
				}
				if (value[g1] != 0) {
					cout << "\tねだん：" << value[g1];
				}
				cout << "\n\n";
			}

			if (cursor == g2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				cout << "\t" << name[g2];
				if (atk[g2] != 0) {
					cout << "\tこうげき" << atk[g2];
				}
				if (def[g2] != 0) {
					cout << "\tぼうぎょ" << def[g2];
				}
				if (matk[g2] != 0) {
					cout << "\tまほうこうげき" << matk[g2];
				}
				if (mdef[g2] != 0) {
					cout << "\tまほうぼうぎょ" << mdef[g2];
				}
				if (spd[g2] != 0) {
					cout << "\tすばやさ" << spd[g2];
				}
				if (value[g2] != 0) {
					cout << "\tねだん：" << value[g2];
				}
				cout << "\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
					FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			}
			else {
				cout << "\t" << name[g2];
				if (atk[g2] != 0) {
					cout << "\tこうげき" << atk[g2];
				}
				if (def[g2] != 0) {
					cout << "\tぼうぎょ" << def[g2];
				}
				if (matk[g2] != 0) {
					cout << "\tまほうこうげき" << matk[g2];
				}
				if (mdef[g2] != 0) {
					cout << "\tまほうぼうぎょ" << mdef[g2];
				}
				if (spd[g2] != 0) {
					cout << "\tすばやさ" << spd[g2];
				}
				if (value[g2] != 0) {
					cout << "\tねだん：" << value[g2];
				}
				cout << "\n\n";
			}

			c = get_key();
			cursor = get_cursor(c, cursor);
			switch (c)
			{
			case ENTER:
				if (cursor == g0) {
					clear();
					decision(g0, id[g0], name[g0]);
				}
				if (cursor == g1) {
					clear();
					decision(g1, id[g1], name[g1]);
				}
				if (cursor == g2) {
					clear();
					decision(g2, id[g2], name[g2]);
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

void Feild::decision(int idx, int id, string name) {
	int length_name = 0;
	int length_value = 0;
	int cursor = 0;//カーソルの位置
	int c = 0;//文字

	enum {
		yes,
		no
	};

	length_value = calc_value_length(value[idx]);
	length_name = name.size();

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|" << name << "は　";
	space(length_name);
	cout << "|" << endl;
	cout << "|" << value[idx] << "円だ";
	space(length_value);
	cout << "|" << endl;
	cout << "|これでいいのか？　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "|　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|" << endl;
	cout << "ーーーーーーーーーーーーーーーーーーーーーーーーーーーーーー" << endl;
	
	wait_key();
	clear();

	while (true) {
		cout << "\n\n";
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
				if (!get_item(id)) {
					cout << "\n\n\t持ち物がいっぱいだな" << endl;
					wait_key();
					clear();
					return;
				}
				ally.set_money(-value[idx]);
				p_sta.money = ally.get_money();
				
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
}

void Feild::space(int length) {
	int i;
	for (i = 0; i <= 57 - (length + 4); i++) {
		cout << " ";
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
	set_status(1);
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

//第一引数：アイテム配列の添え字 第二配列：アイテムのID
void Feild::set_item_infos(int n, int ID) {
	name[n] = i.get_item_name(ID);
	id[n] = i.get_item_id(ID);
	value[n] = i.get_item_value(ID);
	atk[n] = i.get_item_atk(ID);
	def[n] = i.get_item_def(ID);
	matk[n] = i.get_item_matk(ID);
	mdef[n] = i.get_item_mdef(ID);
	spd[n] = i.get_item_spd(ID);
	/*
	cout << "名前：" << i.get_item_name(ID);
	cout << "いｄ：" << i.get_item_id(ID);
	cout << "値段：" << i.get_item_value(ID);
	cout << "こう：" << i.get_item_atk(ID);
	cout << "ぼう：" << i.get_item_def(ID);
	cout << "まこ：" << i.get_item_matk(ID);
	cout << "まぼ：" << i.get_item_mdef(ID);
	cout << "はや：" << i.get_item_spd(ID) << endl;
	*/
}

int Feild::calc_value_length(int value) {
	int count = 0;
	while (true) {
		value /= 10;
		count++;
		if (value == 0) {
			return count;
		}
	}
}

void Feild::set_status(int id) {
	switch (id)
	{
	case 4:
	case 3:
	case 2:
	case 1:
		ally.set_name("ピカタん");
		p_sta.name[0] = ally.get_name();
		ally.set_hp(15);
		p_sta.hp[0] = p_sta.max_hp[0] = ally.get_hp();
		ally.set_mp(0);
		p_sta.mp[0] = p_sta.max_mp[0] = ally.get_mp();
		ally.set_atk(5);
		p_sta.atk[0] = ally.get_atk();
		ally.set_def(3);
		p_sta.def[0] = ally.get_def();
		ally.set_matk(2);
		p_sta.matk[0] = ally.get_matk();
		ally.set_mdef(2);
		p_sta.mdef[0] = ally.get_mdef();
		ally.set_spd(2);
		p_sta.spd[0] = ally.get_spd();
		ally.set_exp(0);
		p_sta.exp[0] = ally.get_exp();
		ally.set_lev(1);
		p_sta.lev[0] = ally.get_lev();
		ally.set_money(500);
		p_sta.money = ally.get_money();
	default:
		break;
	}
}

bool Feild::get_item(int id) {
	for (int n = 0; n < 99; n++) {
		if (p_sta.item_id[n] == 0) {
			p_sta.item_id[n] = i.get_item_id(id);
			return true;
		}
	}
	return false;
}