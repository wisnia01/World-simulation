#pragma once
#include <iostream>
#include "Plant.h"
using namespace std;

class Guarana :public Plant
{
private:

	const char symbol = 'G';

public:
	Guarana();
	~Guarana() override;
	Guarana(Vector2 coordinates, World* world);
	Guarana(int x, int y, World* world, int strength, int age);
	void Collision(Organism* attacker, Vector2 tmp) override;
	void Breed() override;
	char GetSymbol() const override;

};