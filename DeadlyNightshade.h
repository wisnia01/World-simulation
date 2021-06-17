#pragma once
#include <iostream>
#include "Plant.h"
using namespace std;

class DeadlyNightshade :public Plant
{
private:

	const char symbol = 'N';

public:
	DeadlyNightshade();
	~DeadlyNightshade() override;
	DeadlyNightshade(Vector2 coordinates, World* world);
	DeadlyNightshade(int x, int y, World* world, int strength, int age);
	void Collision(Organism* attacker, Vector2 tmp) override;
	void Breed() override;
	char GetSymbol() const override;

};
