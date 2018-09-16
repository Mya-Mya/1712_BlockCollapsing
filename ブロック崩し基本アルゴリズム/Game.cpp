#include"Game.h"
#include"DxLib.h"
#include"Ball.h"
#include"Block.h"

#define NumberOfBalls 5
#define MaxVelocity 9 //注意：Blockの当たり判定での仮想ボックスを超えないように

Game::Game(int inwidth, int inheight) 
{
	width = inwidth;
	height = inheight;
	pBlock = new BlockMgr(width, height);

	for (int i = 0; i < NumberOfBalls; i++) {
		lBall.push_back(new Ball(rand()%1280, rand()%720, (-1)*MaxVelocity + rand() % (MaxVelocity * 2), (-1)*MaxVelocity + rand() % (MaxVelocity*2)));
	}
}

void Game::DO()
{
	int re;
	int outx, outy;

	itrB = lBall.begin();
	while (itrB != lBall.end()) {
		outx = (*itrB)->X();
		outy = (*itrB)->Y();
		re=pBlock->Check(outx, outy);

		if (re != 0) {
			(*itrB)->ChangeV(re);
		}

		(*itrB)->Update();
		(*itrB)->Draw();
		++itrB;
	}

	pBlock->Draw();
}
