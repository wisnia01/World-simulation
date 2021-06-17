#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class Wolf :public Animal
{
private:

	const char symbol ='W';

public:
	Wolf();
	~Wolf() override;
	Wolf(Vector2 coordinates, World* world);
	Wolf(int x, int y, World* world, int strength, int age);
	void Breed() override;
	char GetSymbol() const override;
	
};