#include "Item.h"
#include <windows.h>
#include <iostream>

string Item::get_item_name(int ID) {
	for (int i = 0; i < QUANITITY; i++) {
		OutputDebugString("loop\n");
		if (ID == m_id[i]) {
			OutputDebugString("a\n");
			return m_name[i];
		}
	}
	for (int n = 0; n < 3; n++) {
		cout << "名前：" << m_name[n];
		cout << "いｄ：" << m_id[n];
		cout << "値段：" << m_value[n];
		cout << "こう：" << m_atk[n];
		cout << "ぼう：" << m_def[n];
		cout << "まこ：" << m_matk[n];
		cout << "まぼ：" << m_mdef[n];
		cout << "はや：" << m_spd[n] << endl;
	}
	OutputDebugString("ERROR\n");
	return m_name[QUANITITY];//見つからないとき
}

int Item::get_item_id(int ID) {
	for (int i = 0; i < QUANITITY; i++) {
		if (ID == m_id[i]) {
			return m_id[i];
		}
	}
	return m_id[QUANITITY];//見つからないとき
}

int Item::get_item_value(int ID) {
	for (int i = 0; i < QUANITITY; i++) {
		if (ID == m_id[i]) {
			return m_value[i];
		}
	}
	return m_value[QUANITITY];//見つからないとき
}

int Item::get_item_atk(int ID) {
	for (int i = 0; i < QUANITITY; i++) {
		if (ID == m_id[i]) {
			return m_atk[i];
		}
	}
	return m_atk[QUANITITY];//見つからないとき
}

int Item::get_item_def(int ID) {
	for (int i = 0; i < QUANITITY; i++) {
		if (ID == m_id[i]) {
			return m_def[i];
		}
	}
	return m_def[QUANITITY];//見つからないとき
}

int Item::get_item_matk(int ID) {
	for (int i = 0; i < QUANITITY; i++) {
		if (ID == m_id[i]) {
			return m_matk[i];
		}
	}
	return m_matk[QUANITITY];//見つからないとき
}

int Item::get_item_mdef(int ID) {
	for (int i = 0; i < QUANITITY; i++) {
		if (ID == m_id[i]) {
			return m_mdef[i];
		}
	}
	return m_mdef[QUANITITY];//見つからないとき
}

int Item::get_item_spd(int ID) {
	for (int i = 0; i < QUANITITY; i++) {
		if (ID == m_id[i]) {
			return m_spd[i];
		}
	}
	return m_spd[QUANITITY];//見つからないとき
}

void Item::set_items() {
	m_name[0] = "木の棒　";
	m_id[0] = 1;
	m_value[0] = 10;
	m_atk[0] = 1;
	m_def[0] = 0;
	m_matk[0] = 0;
	m_mdef[0] = 0;
	m_spd[0] = 0;

	m_name[1] = "木のやり";
	m_id[1] = 2;
	m_value[1] = 40;
	m_atk[1] = 2;
	m_def[1] = 0;
	m_matk[1] = 0;
	m_mdef[1] = 0;
	m_spd[1] = 0;

	m_name[2] = "木のナックル";
	m_id[2] = 3;
	m_value[2] = 20;
	m_atk[2] = 1;
	m_def[2] = 0;
	m_matk[2] = 0;
	m_mdef[2] = 0;
	m_spd[2] = 0;

	m_name[QUANITITY] = "era-";
	m_id[QUANITITY] = 0;
	m_value[QUANITITY] = 0;
	m_atk[QUANITITY] = 0;
	m_def[QUANITITY] = 0;
	m_matk[QUANITITY] = 0;
	m_mdef[QUANITITY] = 0;
	m_spd[QUANITITY] = 0;
}
