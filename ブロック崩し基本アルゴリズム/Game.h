#pragma once

#include"Block.h"
#include"Ball.h"
#include<vector>

class Game {
private:
	BlockMgr *pBlock;
	std::vector<Ball*> lBall;
	std::vector<Ball*>::iterator itrB;
	int width, height;
public:
	Game(int inwidth, int inheight);
	void DO();
};