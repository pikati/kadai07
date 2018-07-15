#pragma once
class Map
{
public:
	virtual void draw_map(int map[30][30]) = 0;
	virtual int move_map(int coo[2], int id) = 0;
	//virtual int get_coordinate() = 0;
	virtual void set_map(int map[30][30], int id) = 0;
};

