#pragma once
class Ball {
private:
	int x, y;
	int vx, vy;
public:
	Ball(int inx, int iny, int invx, int invy);
	void ChangeV(int mode);
	void Update();
	void Draw();
	int X();
	int Y();
};