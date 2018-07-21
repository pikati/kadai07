#pragma once
#include "Charactor.h"
#include "Enemy.h"

class Enemy :
	public Charactor
{
private:
	int m_drop[2];
	float m_mag;
public:
	float make_rand() override;
	float set_mag(int,int);
	int attack(int, int) override;
	int defence(int, int) override;
	//void set_drop(int id1, int id2);
	//int get_drop();
	void set_enemy(int map_id, int enemy_id);
};

