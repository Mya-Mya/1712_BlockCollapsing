// �u���b�N������{�A���S���Y��.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include"DxLib.h"
#include"Game.h"
#define WIDTH 1280
#define HEIGHT 720
#include <stdlib.h> // rand, srand�֐�
#include <time.h>

int main()
{
	SetGraphMode(WIDTH, HEIGHT, 16);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	Game *pGame = new Game(WIDTH, HEIGHT);
	unsigned int    now = (unsigned int)time(0);
	srand(now);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		pGame->DO();
	}
	DxLib_End();
	return 0;
}

