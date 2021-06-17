#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class Human :public Animal
{
private:
	const char symbol = '#';

public:
	Human();
	Human(Vector2 coordinates, World* world);
	Human(int x, int y, World* world, int strength, int age);
	~Human() override;
	char GetSymbol() const override;
	void Breed() override;
	void Move(int moveLength) override;
	void Collision(Organism* attacker, Vector2 tmp);
	


};