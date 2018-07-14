#include "Start.h"
#include "Main_game.h"
#include "Init.h"

/*�}�b�v�̏��*/
#define NON 0//�����Ȃ���
#define PLAYER 1//�v���C���[�̈ʒu
#define ENEMY1 2
#define ENEMY_POP 7
#define WALL_VER 8
#define WALL_HOL 9
#define DOT 10
#define POWER 11
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

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