#pragma once
#include "Map.h"
#include<algorithm>

class Feild :
	public Map
{
public:
	void draw_map(int map[30][30]) override;
	int move_map(int coo[2], int id) override;
	//int get_coordinate() override;
	void set_map(int map[30][30], int id) override;
	void clear();
};

inline void Feild::clear() {
	system("cls");
}
