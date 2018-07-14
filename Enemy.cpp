#include "Enemy.h"

#define STR 1
#define INT 2

float Enemy::set_mag(int id, int skil_id) {
	return 1.0f/*get_enemy_mag()*/;
}

int Enemy::attack(int id, int mag) {
	if (id == STR) {
		return m_atk * mag * m_rand;
	}
	if (id == INT) {
		return m_matk * mag;
	}
	return -1;
}

int Enemy::defence(int id, int mag) {
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