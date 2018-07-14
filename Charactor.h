#pragma once
#include "Task.h"

class Charactor:
	public Task
{
protected:
	int m_maxhp;
	int m_hp;
	int m_maxmp;
	int m_mp;
	int m_atk;
	int m_def;
	int m_matk;
	int m_mdef;
	int m_spd;
	int m_exp;
	int m_lev;
	int m_states;
	float m_rand;

public:
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
	virtual float make_rand() = 0;
	virtual int attack(int, int) = 0;
	virtual int defence(int, int) = 0;
};

inline int Charactor::get_hp() {
	return m_hp;
}

inline int Charactor::get_mp() {
	return m_mp;
}

inline int Charactor::get_atk() {
	return m_atk;
}

inline int Charactor::get_def() {
	return m_def;
}

inline int Charactor::get_matk() {
	return m_matk;
}

inline int Charactor::get_mdef() {
	return m_mdef;
}

inline int Charactor::get_spd() {
	return m_spd;
}

inline int Charactor::get_exp() {
	return m_exp;
}

inline int Charactor::get_lev() {
	return m_lev;
}

inline int Charactor::get_states() {
	return m_states;
}

inline void Charactor::set_hp(int n) {
	m_hp += n;
}

inline void Charactor::set_mp(int n) {
	m_mp += n;
}

inline void Charactor::set_atk(int n) {
	m_atk += n;
}

inline void Charactor::set_def(int n) {
	m_def += n;
}

inline void Charactor::set_matk(int n) {
	m_matk += n;
}

inline void Charactor::set_mdef(int n) {
	m_mdef += n;
}

inline void Charactor::set_spd(int n) {
	m_spd += n;
}

inline void Charactor::set_exp(int n) {
	m_exp += n;
}

inline void Charactor::set_lev(int n) {
	m_lev += n;
}

inline void Charactor::set_state(int n) {
	m_states = n;
}