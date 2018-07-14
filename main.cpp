#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

/*マップの情報*/
#define NON 0//何もない床
#define PLAYER 1//プレイヤーの位置
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
			//start画面に遷移
			break;
		case file:
			//save,load画面に遷移
			break;
		case main_game:
			//メインゲーム画面に遷移
			break;
		case menu:
			//メニュー画面に遷移
			break;
		case battle:
			//バトル画面に遷移
			break;
		default:
			break;
		}
	}
}