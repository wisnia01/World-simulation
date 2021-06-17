#include <iostream>
#include "Animal.h"
using namespace std;

class Antelope :public Animal
{
private:

	const char symbol = 'A';

public:
	Antelope();
	~Antelope() override;
	Antelope(Vector2 coordinates, World* world);
	Antelope(int x, int y, World* world, int strength, int age);
	void Breed() override;
	char GetSymbol() const override;
	void Collision(Organism* attacker, Vector2 tmp) override;

};
