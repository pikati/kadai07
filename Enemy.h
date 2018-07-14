#pragma once
#include "Charactor.h"
class Enemy :
	public Charactor
{
private:
	float m_mag;
public:
	float set_mag(int,int);
	int attack(int, int) override;
	int defence(int, int) override;
	Enemy();
};

