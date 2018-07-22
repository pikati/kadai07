#pragma once
#include <string>

#define QUANITITY 180

using namespace std;

class Item
{
private:
	string m_name[10] = { "" };
	int m_id[10] = { 0 };
	int m_value[10] = { 0 };
	int m_atk[10] = { 0 };
	int m_def[10] = { 0 };
	int m_matk[10] = { 0 };
	int m_mdef[10] = { 0 };
	int m_spd[10] = { 0 };
public:
	string get_item_name(int id);
	int get_item_id(int id);
	int get_item_value(int id);
	int get_item_atk(int id);
	int get_item_def(int id);
	int get_item_matk(int id);
	int get_item_mdef(int id);
	int get_item_spd(int id);
	void set_items();
};

