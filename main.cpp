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
			//save,load��ʂɑJ��
			break;
		case main_game:
			scene = m.draw();
			break;
		case menu:
			//���j���[��ʂɑJ��
			break;
		case battle:
			//�o�g����ʂɑJ��
			break;
		case -1:
			return 0;
		default:
			break;
		}
	}
}