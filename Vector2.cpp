#include <iostream>
#include "Vector2.h"
using namespace std;

Vector2::Vector2()
{

}
Vector2::Vector2(int x, int y) : x(x), y(y)
{

}
void Vector2::SetX(int x)
{
	this->x = x;
}
void Vector2::SetY(int y)
{
	this->y = y;
}
int Vector2::GetX()
{
	return x;
}
int Vector2::GetY()
{
	return y;
}
