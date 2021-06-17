#pragma once
#include <iostream>
using namespace std;

class Vector2
{
	int x;
	int y;
public:
	void SetX(int x);
	void SetY(int x);
	int GetX();
	int GetY();
	Vector2();
	Vector2(int x, int y);
};