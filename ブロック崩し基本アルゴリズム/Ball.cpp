#include"Ball.h"
#include"DxLib.h"

Ball::Ball(int inx, int iny, int invx, int invy)
{
	x = inx;
	y = iny;
	vx = invx;
	vy = invy;
}

void Ball::ChangeV(int mode)
{
	switch (mode)
	{
	case 1://Top or Buttom
		vy *= -1;
		break;
	case 2://Left or Light
		vx *= -1;
		break;
	case 3://Middle
		vx *= -1;
		vy *= -1;
		break;
	}
	
}

void Ball::Update()
{
	x += vx;
	y += vy;
}

void Ball::Draw()
{
	DrawCircle(x, y, 4, GetColor(150, 150, 150), TRUE);
}

int Ball :: X() {
	return x;
}

int Ball::Y() {
	return y;
}