#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class Sheep :public Animal
{
private:
	const char symbol = 'S';

public:
	Sheep();
	~Sheep() override;
	Sheep(Vector2 coordinates, World* world);
	Sheep(int x, int y, World* world, int strength, int age);
	//void Collision() override;
	void Breed() override;
	char GetSymbol() const override;
};