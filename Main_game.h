#pragma once
#include "Task.h"
class Main_game :
	public Task
{
public:
	int draw() override;
	int get_key() override;
	int get_cursor(int, int) override;
	void key_wait();
	void ch0_story();
	void ch1_story();

};

