#include "Ally.h"
#include <random>

#define STR 1
#define INT 2
#define HEAL 1
#define ATTACK 2
#define BUFF 3
#define OTHER 4

Ally::Ally()
{
}

float Ally::make_rand() {
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand(90, 110);
	return rand(mt) / 100;
}

int Ally::select_skill() {
	int select;
	//‚±‚±‚É‹Z‚Æ‚©‚ğ•\¦‚·‚éˆ—‚â‘I‘ğ‚·‚éˆ—‚ğ‚Ô‚¿‚İI
	return select;
}


int Ally::attack(int id, int mag) {
	if (id == STR) {
		return m_atk * mag * m_rand;
	}
	if (id == INT) {
		return m_matk * mag;
	}
	return -1;
}

int Ally::defence(int id, int mag) {
	switch (id)
	{
	case STR:
		return m_def * mag;
	case INT:
		return m_mdef * mag;
	default:
		return -1;
	}
}

int Ally::used_item(int id) {
	switch (id)
	{
	case HEAL:
		return 10/*get_item_effect(id)*/;
	case ATTACK:
		return 5/*get_item_effect(id)*/;
	case BUFF:
		return 1/*get_item_effect(id)*/;
	case OTHER:
		return 0/*get_item_effect(id)*/;
	default:
		return -1;
	}
}