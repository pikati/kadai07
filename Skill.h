#pragma once
#include <string>

using namespace std;

class Skill
{
private:
	typedef struct {
		string name;
		int id;
		int mp;
		int elem;
		float mag;
		int effect;
		string dis;//�X�L���̐���
	} skills;

	skills skill[100];
public:
	Skill();
	skills get_skill(int id);
};

