#include "Ally.h"
#include <random>

#define STR 1
#define INT 2
#define HEAL 1
#define ATTACK 2
#define BUFF 3
#define OTHER 4

float Ally::make_rand() {
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand(90, 110);
	return (float)rand(mt) / 100.0f;
}

int Ally::select_skill() {
	int select = 0;
	//‚±‚±‚É‹Z‚Æ‚©‚ğ•\¦‚·‚éˆ—‚â‘I‘ğ‚·‚éˆ—‚ğ‚Ô‚¿‚İI
	return select;
}


int Ally::attack(int id, int mag) {
	if (id == STR) {
		return status[0].m_atk * mag * status[0].m_rand;
	}
	if (id == INT) {
		return status[0].m_matk * mag;
	}
	return -1;
}

int Ally::defence(int id, int mag) {
	switch (id)
	{
	case STR:
		return status[0].m_def * mag;
	case INT:
		return status[0].m_mdef * mag;
	default:
		return -1;
	}
}

int Ally::used_item(int id) {
	switch (id)
	{
	case HEAL:
		return 10/*get_itestatus[0].m_effect(id)*/;
	case ATTACK:
		return 5/*get_itestatus[0].m_effect(id)*/;
	case BUFF:
		return 1/*get_itestatus[0].m_effect(id)*/;
	case OTHER:
		return 0/*get_itestatus[0].m_effect(id)*/;
	default:
		return -1;
	}
}

void Ally::set_exp_table() {
	for (int i = 0; i < 98; i++) {
		exp_table[i] = 10 + (i * i) * 10;
	}
}

void Ally::level_up(int id, int lev) {
	switch (id)
	{
	case 1:
		for (int i = 0; i < 98; i++) {
			if (i == lev) {
				if (exp_table[i] > status[0].m_exp) {
					status[0].m_lev++;
					lv_up_status(id, lev);
				}
			}
		}
	default:
		break;
	}
}

void Ally::lv_up_status(int id, int lev) {
	switch (id)
	{
	case 1:
		switch (lev)
		{
		case 2:
			set_hp(2);
			set_mp(0);
			set_atk(2);
			set_def(1);
			set_matk(0);
			set_mdef(0);
			set_spd(1);
			break;
		case 3:
			set_hp(3);
			set_mp(2);
			set_atk(2);
			set_def(1);
			set_matk(1);
			set_mdef(1);
			set_spd(1);
			break;
		case 4:
			set_hp(2);
			set_mp(3);
			set_atk(3);
			set_def(2);
			set_matk(3);
			set_mdef(1);
			set_spd(2);
			break;
		case 5:
			set_hp(3);
			set_mp(2);
			set_atk(2);
			set_def(2);
			set_matk(2);
			set_mdef(2);
			set_spd(1);
			break;
		case 6:
			set_hp(2);
			set_mp(1);
			set_atk(1);
			set_def(2);
			set_matk(2);
			set_mdef(2);
			set_spd(1);
			break;
		case 7:
			set_hp(3);
			set_mp(1);
			set_atk(2);
			set_def(2);
			set_matk(3);
			set_mdef(2);
			set_spd(2);
			break;
		case 8:
			set_hp(2);
			set_mp(2);
			set_atk(3);
			set_def(3);
			set_matk(2);
			set_mdef(2);
			set_spd(1);
			break;
		case 9:
			set_hp(4);
			set_mp(3);
			set_atk(3);
			set_def(1);
			set_matk(3);
			set_mdef(2);
			set_spd(2);
			break;
		case 10:
			set_hp(3);
			set_mp(1);
			set_atk(4);
			set_def(2);
			set_matk(3);
			set_mdef(1);
			set_spd(1);
			break;
		default:
			break;
		}
	default:
		break;
	}
}