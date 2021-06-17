#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class Fox :public Animal
{
private:
	const char symbol = 'F';

public:
	Fox();
	~Fox() override;
	Fox(Vector2 coordinates, World* world);
	Fox(int x, int y, World* world, int strength, int age);
	//void Collision() override;
	void Move(int moveLength) override;
	void Breed() override;
	char GetSymbol() const override;
};
