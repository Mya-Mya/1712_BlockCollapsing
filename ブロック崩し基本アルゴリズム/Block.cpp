#include "Block.h"
#include"DxLib.h"
#define v 10//���x�ɑ΂��鉼�z�{�b�N�X��臒l

Block::Block(int inx, int iny, int inwidth, int inheight, bool inEraseable)
{
	x = inx, y = iny, width = inwidth, height = inheight, Eraseable = inEraseable;
}

void Block::Draw() 
{
	DrawBox(x, y, x + width, y + height,GetColor(200,200,200),TRUE);
}


int Block::Check(int inx, int iny)
{
	if (x < inx && inx < x + width && y < iny && iny < y + height) {
		//Top
		if (x + v < inx && inx < x + width - v && y < iny && iny < y+v) return 1;
		//Buttom
		if (x + v < inx && inx < x + width - v && y + height - v < iny && iny < y + height) return 1;
		//Left
		if (x < inx && inx < x + v && y + v < iny && iny < y + height - v) return 2;
		//Right
		if (x + width - v < inx && inx < x + width && y + v < iny && iny < y + height - v) return 2;
		//Middle
		return 3;
	}
	//Other
	return 0;
}

bool Block::IfEraseable()
{
	return Eraseable;
}


BlockMgr::BlockMgr(int inwidth, int inheight)
{
	/*�E�B���h�E�[*/
	lBlock.push_back(new Block(-20,0,20,inheight,false));//����
	lBlock.push_back(new Block(0,-20,inwidth,20,false));//���
	lBlock.push_back(new Block(inwidth,0,20,inheight,false));//�E��
	lBlock.push_back(new Block(0,inheight,inwidth,20,false));//���

	/*���R�ɍ���Ă���*/
	for (int i = 0; i < 50; i++) {
		lBlock.push_back(new Block(rand() % 1600, rand() % 400,rand() % 200, rand() % 200,true));
	}
}

void BlockMgr::Draw()
{
	itrBlock = lBlock.begin();
	while (itrBlock != lBlock.end()) {
		(*itrBlock)->Draw();
		++itrBlock;
	}
}

int BlockMgr::Check(int inx, int iny)
{
	int re = 0;

	itrBlock = lBlock.begin();
	while (itrBlock != lBlock.end()) {
		re = ((*itrBlock)->Check(inx, iny));
		if (re != 0) {
			if((*itrBlock)->IfEraseable()==true) itrBlock=lBlock.erase(itrBlock);
			return re;
		}
		++itrBlock;
	}
	return 0;
}


