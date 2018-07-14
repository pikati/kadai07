#include "Init.h"
#include <windows.h>

void init() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO cci;

	// 出力用ハンドルの取得
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// CONSOLE_CURSOR_INFO構造体の現在の状態を取得する
	GetConsoleCursorInfo(hOut, &cci);

	// メンバ変数であるbVisibleがカーソルの表示・非表示を制御する変数なので、これをFALSEにする事でカーソルを非表示にできる
	cci.bVisible = FALSE;

	// 変更した構造体情報をコンソールWindowにセットする
	SetConsoleCursorInfo(hOut, &cci);
}