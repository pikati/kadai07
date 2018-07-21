#include "Enemy.h"
#include "Feild.h"
#include <random>

/*攻撃の属性*/
#define STR 1//物理
#define INT 2//魔法

/*マップのID*/
#define FELES 0
#define FELES_EAST 1
#define FELES_WEST 2
#define FELES_PLATEAU 3
#define FELES_HIGHWAY 4
#define FELES_MINE 5
#define PIES 6
#define KUCING 7

float Enemy::make_rand() {
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand(90, 110);
	return (float)rand(mt) / 100.0f;
}

float Enemy::set_mag(int id, int skil_id) {
	return 1.0f/*get_enemy_mag()*/;
}

int Enemy::attack(int id, int mag) {
	if (id == STR) {
		return status[9].m_atk * mag * status[9].m_rand;
	}
	if (id == INT) {
		return status[9].m_matk * mag;
	}
	return -1;
}

int Enemy::defence(int id, int mag) {
	switch (id)
	{
	case STR:
		return status[9].m_def * mag;
	case INT:
		return status[9].m_mdef * mag;
	default:
		return -1;
	}
}

void Enemy::set_enemy(int map_id, int enemy_id){
	
	switch (map_id)
	{
	case FELES_EAST:
		switch (enemy_id) {
		case 0:
			set_name("ごろごろわんこ");
			set_hp(5);
			set_mp(0);
			set_atk(5);
			set_def(3);
			set_matk(0);
			set_mdef(0);
			set_spd(100);
			set_exp(2);
			set_lev(1);
			set_state(0);
			set_money(2);
			//set_drop(1, 2);
			break;
		case 1:
			set_name("いっぬ");
			set_hp(12);
			set_mp(0);
			set_atk(3);
			set_def(2);
			set_matk(0);
			set_mdef(2);
			set_spd(0);
			set_exp(3);
			set_lev(1);
			set_state(0);
			set_money(3);
			//e2.set_drop(1, 2);
			break;
		case 2:
			set_name("いぬのまもの");
			set_hp(20);
			set_mp(3);
			set_atk(7);
			set_def(5);
			set_matk(10);
			set_mdef(3);
			set_spd(8);
			set_exp(7);
			set_lev(2);
			set_state(0);
			set_money(10);
			//set_drop(1, 2);
			break;
		case 3:
			set_name("はっぱのようせい");
			set_hp(5);
			set_mp(12);
			set_atk(1);
			set_def(20);
			set_matk(5);
			set_mdef(20);
			set_spd(15);
			set_exp(7);
			set_lev(2);
			set_state(0);
			set_money(10);
			//set_drop(1, 2);
			break;
		case 4:
			set_name("くちびるおばけ");
			set_hp(20);
			set_mp(0);
			set_atk(8);
			set_def(6);
			set_matk(0);
			set_mdef(2);
			set_spd(8);
			set_exp(10);
			set_lev(3);
			set_state(0);
			set_money(1);
			//set_drop(1, 2);
			break;
		}
		break;
	case INT:
		break;
	default:
		break;
	}
}
