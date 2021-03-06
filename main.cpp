#include "Start.h"
#include "Main_game.h"
#include "Init.h"

int main() {
	int scene = 0;
	Start s;
	Main_game m;
	enum {
		start,
		file,
		main_game,
		menu,
		battle
	};

	init();

	while (true) {
		switch (scene)
		{
		case start:
			scene = s.draw();
			break;
		case file:
			//save,load画面に遷移
			break;
		case main_game:
			scene = m.draw();
			break;
		case menu:
			//メニュー画面に遷移
			break;
		case battle:
			//バトル画面に遷移
			break;
		case -1:
			return 0;
		default:
			break;
		}
	}
}