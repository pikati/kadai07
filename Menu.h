#pragma once
#include "Task.h"
#include "Feild.h"
#include "Item.h"
class Menu :
	public Task
{
private:
	Item i;
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
		int money;
		int item[99];
		bool is_equip[5] = { false };
	}p_status;

	p_status p_sta_m;

	int status[11];//現在の状態（HPやATKなど）を保存しておくところ
	string p_item_name[99];
	int p_item_id[99];
public:
	int* menu_mgr(string name, int mhp, int hp, int mp, int mmp, int atk, int def, int matk, int mdef, int spd, int exp, int lev, int money, int* item);
	int draw() override;
	int get_key() override;
	int get_cursor(int, int) override;
	void wait_key() override;
	void clear();
	void draw_spell();
	void draw_strength();
	void draw_tool();
	int get_length(int status);
	int get_length(string name);
	void space(int length);
	void hit_cursor();
	void nhit_corsor();
	void equip(int id, int idx);
};

