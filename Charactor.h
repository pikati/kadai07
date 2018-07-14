#pragma once
class Charactor
{
protected:
	int m_hp;
	int m_mp;
	int m_atk;
	int m_def;
	int m_matk;
	int m_mdef;
	int m_spd;
	int m_exp;
	int m_lev;
	int m_states;

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