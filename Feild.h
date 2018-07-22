#pragma once
#include "Map.h"
#include<algorithm>
#include "Item.h"
#include "Ally.h"
#include "Menu.h"
#include "Enemy.h"

class Feild :
	public Map
{
private:
	Item i;
	Enemy e;
	int m_xy[2];
	int m_map_id;
	int m_map[30][30];
	int m_dir;

	string name[10];
	int id[10];
	int value[10];
	int atk[10];
	int def[10];
	int matk[10];
	int mdef[10];
	int spd[10];
	int money;

	typedef struct {
		string name[4];
		int max_hp[4];
		int hp[4];
		int max_mp[4];
		int mp[4];
		int atk[4];
		int def[4];
		int matk[4];
		int mdef[4];
		int spd[4];
		int exp[4];
		int lev[4];
		int item_id[99] = { 0 };
		int status[4];
		int money;
	}p_status;


	p_status p_sta;

public:
	Ally ally;

	void map_mgr();
	void draw_map(int map[30][30], int dir, int xy[2]) override;
	int move_map(int map[30][30], int XY[2], int id, int move) override;
	//int get_xy() override;
	void set_map(int map[30][30], int id) override;
	void tolk(int map[30][30], int xy[2], int dir) override;
	void weapon() override;
	//void armor() override;
	//void tool() override;
	int select_trading() override;
	void buy(int id) override;
	//void sell() override;
	void decision(int idx, int id, string name) override;
	void space(int length) override;
	int get_cursor(int, int) override;
	void wait_key() override;
	void clear();
	int get_key();
	void init();
	void set_item_infos(int n, int id);
	int calc_value_length(int value);
	void set_status(int id);
	bool get_item(int id);
};

inline void Feild::clear() {
	system("cls");
}
