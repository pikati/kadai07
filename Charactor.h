#pragma once
#include <string>

using namespace std;

class Charactor
{
protected:
	typedef struct {
		string m_name;
		int m_id;
		int m_maxhp = 0;
		int m_hp = 0;
		int m_maxmp = 0;
		int m_mp = 0;
		int m_atk = 0;
		int m_def = 0;
		int m_matk = 0;
		int m_mdef = 0;
		int m_spd = 0;
		int m_elem = 0;
		int m_exp = 0;
		int m_lev = 0;
		int m_states = 0;
		int m_money = 0;
		float m_rand = 0;
		int m_skill = 0;
		int m_item[99] = { 0 };
	} sta;

	sta status[10];
public:
	string get_name();
	int get_hp();
	int get_mp();
	int get_atk();
	int get_def();
	int get_matk();
	int get_mdef();
	int get_spd();
	int get_exp();
	int get_lev();
	int get_states();
	int get_money();
	void set_name(string name);
	void set_hp(int);
	void set_mp(int);
	void set_atk(int);
	void set_def(int);
	void set_matk(int);
	void set_mdef(int);
	void set_spd(int);
	void set_exp(int);
	void set_lev(int);
	void set_state(int);
	void set_money(int);
	virtual float make_rand() = 0;
	virtual int attack(int, int) = 0;
	virtual int defence(int, int) = 0;
};

inline string Charactor::get_name() {
	return status[0].m_name;
}

inline int Charactor::get_hp() {
	return status[0].m_hp;
}

inline int Charactor::get_mp() {
	return status[0].m_mp;
}

inline int Charactor::get_atk() {
	return status[0].m_atk;
}

inline int Charactor::get_def() {
	return status[0].m_def;
}

inline int Charactor::get_matk() {
	return status[0].m_matk;
}

inline int Charactor::get_mdef() {
	return status[0].m_mdef;
}

inline int Charactor::get_spd() {
	return status[0].m_spd;
}

inline int Charactor::get_exp() {
	return status[0].m_exp;
}

inline int Charactor::get_lev() {
	return status[0].m_lev;
}

inline int Charactor::get_states() {
	return status[0].m_states;
}

inline int Charactor::get_money() {
	return status[0].m_money;
}

inline void Charactor::set_name(string name) {
	status[0].m_name = name;
}
inline void Charactor::set_hp(int n) {
	status[0].m_hp += n;
}

inline void Charactor::set_mp(int n) {
	status[0].m_mp += n;
}

inline void Charactor::set_atk(int n) {
	status[0].m_atk += n;
}

inline void Charactor::set_def(int n) {
	status[0].m_def += n;
}

inline void Charactor::set_matk(int n) {
	status[0].m_matk += n;
}

inline void Charactor::set_mdef(int n) {
	status[0].m_mdef += n;
}

inline void Charactor::set_spd(int n) {
	status[0].m_spd += n;
}

inline void Charactor::set_exp(int n) {
	status[0].m_exp += n;
}

inline void Charactor::set_lev(int n) {
	status[0].m_lev += n;
}

inline void Charactor::set_state(int n) {
	status[0].m_states = n;
}

inline void Charactor::set_money(int n) {
	status[0].m_money += n;
}

