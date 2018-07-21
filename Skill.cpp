#include "Skill.h"

#define SKILLMAX 9

//スキルの属性
#define NO 0
#define FIRE 1
#define ICE 2
#define WIND 3
#define SOIL 4
#define LIGHT 5
#define DARK 6


Skill::Skill()
{
	skill[0].name = "フレイム";
	skill[0].id = 1;
	skill[0].mp = 2;
	skill[0].elem = FIRE;
	skill[0].mag = 1.2f;
	skill[0].effect = 1;
	skill[0].dis = "敵1体に火属性のダメージを与える";
	skill[1].name = "フレイマ";
	skill[1].id = 2;
	skill[1].mp = 4;
	skill[1].elem = FIRE;
	skill[1].mag = 1.5f;
	skill[1].effect = 1;
	skill[1].dis = "敵1体に火属性の中ダメージを与える";
	skill[2].name = "フレイミン";
	skill[2].id = 3;
	skill[2].mp = 7;
	skill[2].elem = FIRE;
	skill[2].mag = 2.0f;
	skill[2].effect = 1;
	skill[2].dis = "敵1体に火属性の大ダメージを与える";
	skill[3].name = "アイス";
	skill[3].mp = 3;
	skill[3].id = 4;
	skill[3].elem = ICE;
	skill[3].mag = 0.7f;
	skill[3].effect = 2;
	skill[3].dis = "敵全体に氷属性の小ダメージを与える";
	skill[4].name = "アイサー";
	skill[4].id = 5;
	skill[4].mp = 5;
	skill[4].elem = ICE;
	skill[4].mag = 1.0f;
	skill[4].effect = 2;
	skill[4].dis = "敵全体に氷属性のダメージを与える";
	skill[5].name = "アイシクル";
	skill[5].id = 6;
	skill[5].elem = ICE;
	skill[5].mag = 1.5f;
	skill[5].effect = 2;
	skill[5].dis = "敵全体に氷属性の中ダメージを与える";
	skill[6].name = "ゲイル";
	skill[6].mp = 5;
	skill[6].id = 7;
	skill[6].elem = WIND;
	skill[6].mag = 1.1f;
	skill[6].effect = 2;
	skill[6].dis = "敵全体に風属性のダメージを与える";
	skill[7].name = "ブレイズ";
	skill[7].mp = 11;
	skill[7].id = 8;
	skill[7].elem = WIND;
	skill[7].mag = 1.8f;
	skill[7].effect = 2;
	skill[7].dis = "敵全体に風属性の中ダメージを与える";
	skill[8].name = "サイクロン";
	skill[8].mp = 18;
	skill[8].id = 8;
	skill[8].elem = WIND;
	skill[8].mag = 2.3f;
	skill[8].effect = 2;
	skill[8].dis = "敵全体に風属性の大ダメージを与える";
}

Skill::skills Skill::get_skill(int id) {
	for (int i = 0; i < SKILLMAX; i++) {
		if (id == skill[i].id) {
			return skill[i];
		}
	}
}

