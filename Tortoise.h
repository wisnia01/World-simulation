#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class Tortoise :public Animal
{
private:
	const char symbol = 'T';
	bool IsDeflected(Organism& attacker);
public:
	Tortoise();
	~Tortoise() override;
	Tortoise(Vector2 coordinates, World* world);
	Tortoise(int x, int y, World* world, int strength, int age);
	void Move(int moveLength) override;
	void Collision(Organism* attacker, Vector2 tmp) override;
	void Breed() override;
	char GetSymbol() const override;
	
};