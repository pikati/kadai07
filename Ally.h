#pragma once
#include "Charactor.h"
class Ally :
	public Charactor
{
public:
	Ally();
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
	int select_skill();

};

inline void Ally::set_hp(int n) {
	m_hp += n;
}

inline void Ally::set_mp(int n) {
	m_mp += n;
}

inline void Ally::set_atk(int n) {
	m_atk += n;
}

inline void Ally::set_def(int n) {
	m_def += n;
}

inline void Ally::set_matk(int n) {
	m_matk += n;
}

inline void Ally::set_mdef(int n) {
	m_mdef += n;
}

inline void Ally::set_spd(int n) {
	m_spd += n;
}

inline void Ally::set_exp(int n) {
	m_exp += n;
}

inline void Ally::set_lev(int n) {
	m_lev += n;
}

inline void Ally::set_state(int n) {
	m_states = n;
}