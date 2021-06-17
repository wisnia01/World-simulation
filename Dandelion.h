#pragma once
#include <iostream>
#include "Plant.h"
using namespace std;

class Dandelion :public Plant
{
private:

	const char symbol = 'D';

public:
	Dandelion();
	~Dandelion() override;
	Dandelion(Vector2 coordinates, World* world);
	Dandelion(int x, int y, World* world, int strength, int age);
	void Breed() override;
	char GetSymbol() const override;

};