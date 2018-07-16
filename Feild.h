#pragma once
#include "Map.h"
#include<algorithm>

class Feild :
	public Map
{
private:
	int m_xy[2];
	int m_map_id;
	int m_map[30][30];
	int m_dir;
public:
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
	void decision(int id, string name) override;
	void space(int length) override;
	int get_value(int id) override;
	int get_cursor(int, int) override;
	void wait_key() override;
	void clear();
	int get_key();
	void init();
};

inline void Feild::clear() {
	system("cls");
}
