#pragma once
#include "Task.h"
#include "Ally.h"
#include "Enemy.h"
class Buttle :
	public Task
{
private:
	Enemy e[5];
	string name[5];
	int max_hp[5];
	int hp[5];
	int max_mp[5];
	int mp[5];
	int atk[5];
	int def[5];
	int matk[5];
	int mdef[5];
	int spd[5];
	int exp[5];
	int money[5];
public:
	void battle_mgr(int map_id);
	void encount(int party);
	void set_enmy(int map_id, int n);
	int draw() override;
	int get_key() override;
	int get_cursor(int, int) override;
	void wait_key() override;
};

