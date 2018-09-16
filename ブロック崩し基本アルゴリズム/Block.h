#pragma once
#include<vector>
class Block {
private:
	int x, y;
	int width, height;
	bool Eraseable = false;
public:
	Block(int inx, int iny, int inwidth, int inheight, bool inEraseable);
	void Draw();
	int Check(int inx, int iny);
	bool IfEraseable();
};

class BlockMgr {
private:
	std::vector<Block*> lBlock;
	std::vector<Block*>::iterator itrBlock;
public:
	BlockMgr(int inwidth, int inheight);
	void Draw();
	int Check(int inx, int iny);
};