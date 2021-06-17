#pragma once
#include <iostream>
#include "Plant.h"
using namespace std;

class Grass :public Plant
{
private:

	const char symbol = 'L';

public:
	Grass();
	~Grass() override;
	Grass(Vector2 coordinates, World* world);
	Grass(int x, int y, World* world, int strength, int age);
	void Breed() override;
	char GetSymbol() const override;

};