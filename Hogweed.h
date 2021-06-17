#pragma once
#include <iostream>
#include "Plant.h"
using namespace std;

class Hogweed :public Plant
{
private:

	const char symbol = 'H';

public:
	Hogweed();
	~Hogweed() override;
	Hogweed(Vector2 coordinates, World* world);
	Hogweed(int x, int y, World* world, int strength, int age);
	void Collision(Organism* attacker, Vector2 tmp) override;
	void Action() override;
	void Breed() override;
	char GetSymbol() const override;

};