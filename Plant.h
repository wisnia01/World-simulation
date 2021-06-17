#pragma once
#include <iostream>
#include "Organism.h"
using namespace std;

class Plant : public Organism {
private:

public:
	Plant();
	virtual void Action() override;
	virtual void Collision(Organism* attacker, Vector2 tmp) override;
	virtual void Breed() = 0;
	virtual char GetSymbol() const = 0;
	virtual ~Plant() override;
};
