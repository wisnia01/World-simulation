#pragma once
#include <iostream>
#include "Organism.h"
using namespace std;

class Animal : public Organism {
private:

public:
	Animal();
	virtual void Action() override;
	virtual void Move(int moveLength);
	virtual void Collision(Organism *attacker, Vector2 tmp) override;
	virtual void Breed() = 0;
	virtual char GetSymbol() const = 0;
	virtual ~Animal() override;
};
