#pragma once
#include <iostream>
#include "Vector2.h"
#include "World.h"
using namespace std;
class World;
class Organism
{
private:

protected:
	int initiative;
	int moveLength;
	int age;
	int strength;
	World* world;
	Vector2 coordinates;
	char symbol;
public:
	Organism();
	Organism(World* world);
	Organism(World* world, Vector2 coordinates);
	Organism(const char symbol, int strength, int initiative, Vector2 coordinates, World* world);
	Vector2 GetCoordinates();
	void SetCoordinates(Vector2 newCoordinates);
	virtual void Action() =0;
	virtual void Collision(Organism* attacker, Vector2 tmp)=0;
	virtual void Breed()=0;
	virtual char GetSymbol() const = 0;
	int GetStrength() const;
	void SetStrength(int newStrength);
	World* GetWorld();
	int GetAge() const;
	void SetAge(int newAge);
	int GetMoveLength() const;
	int GetInitiative() const;
	virtual ~Organism();



};
