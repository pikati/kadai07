#pragma once
#include <string>

using namespace std;

class Map
{
public:
	virtual void draw_map(int map[30][30], int dir, int xy[2]) = 0;
	virtual int move_map(int map[30][30], int XY[2], int id, int move) = 0;
	virtual void set_map(int map[30][30], int id) = 0;
	virtual void tolk(int map[30][30], int xy[2], int dir) = 0;
	virtual void weapon() = 0;
	//virtual void armor() = 0;
	//virtual void tool() = 0;
	virtual int select_trading() = 0;
	virtual int get_cursor(int, int) = 0;
	virtual void buy(int id) = 0;
	//virtual void sell() = 0;
	virtual void decision(int id, string name) = 0;
	virtual void space(int length) = 0;
	virtual void wait_key() = 0;

};

