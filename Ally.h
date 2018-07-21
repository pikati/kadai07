#pragma once
#include "Charactor.h"
class Ally :
	public Charactor
{
private:
	int skill_id[100];
	int exp_table[98];
public:
	float make_rand() override;
	int select_skill();
	int attack(int, int) override;
	int defence(int, int) override;
	int used_item(int);
	void set_exp_table();
	void level_up(int id, int lev);
	void lv_up_status(int id, int lev);
};

