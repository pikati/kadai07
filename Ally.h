#pragma once
#include "Charactor.h"
class Ally :
	public Charactor
{
public:
	Ally();
	float make_rand() override;
	
	int select_skill();
	int attack(int, int) override;
	int defence(int, int) override;
	int used_item(int);
};

