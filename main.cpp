#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

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
	typedef enum {
		start,
		file,
		main_game,
		menu,
		battle
	};

	while (true) {
		switch (scene)
		{
		case start:
			//start��ʂɑJ��
			break;
		case file:
			//save,load��ʂɑJ��
			break;
		case main_game:
			//���C���Q�[����ʂɑJ��
			break;
		case menu:
			//���j���[��ʂɑJ��
			break;
		case battle:
			//�o�g����ʂɑJ��
			break;
		default:
			break;
		}
	}
}