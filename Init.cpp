#include "Init.h"
#include <windows.h>

void init() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO cci;

	// �o�͗p�n���h���̎擾
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// CONSOLE_CURSOR_INFO�\���̂̌��݂̏�Ԃ��擾����
	GetConsoleCursorInfo(hOut, &cci);

	// �����o�ϐ��ł���bVisible���J�[�\���̕\���E��\���𐧌䂷��ϐ��Ȃ̂ŁA�����FALSE�ɂ��鎖�ŃJ�[�\�����\���ɂł���
	cci.bVisible = FALSE;

	// �ύX�����\���̏����R���\�[��Window�ɃZ�b�g����
	SetConsoleCursorInfo(hOut, &cci);

	//�E�B���h�E�T�C�Y�ύX
	SMALL_RECT consoleWindow = { 0, 0, 100, 35 };
	SetConsoleWindowInfo(
		hOut, // HANDLE hConsoleOutput
		TRUE,           // BOOL bAbsolute
		&consoleWindow);// CONST SMALL_RECT *lpConsoleWindow

}