#pragma once
#include "Task.h"
class Start :
	public Task
{
public:
	int draw() override;
	int get_key() override;
	int get_cursor(int, int) override;
	void wait_key() override;
	void dis();//à–¾
};

