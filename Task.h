#pragma once

using namespace std;

class Task
{
public:
	virtual int draw() = 0;
	virtual int get_key() = 0;
	virtual int get_cursor(int, int) = 0;
	virtual void wait_key() = 0;
	void clear();
};

