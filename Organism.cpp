#include <iostream>
#include "Organism.h"
using namespace std;

Organism::Organism()
{

}
Organism::Organism(World* world)
{
	this->world = world;
}
Organism::Organism(World* world, Vector2 coordinates)
{
	this->world = world;
	this->coordinates = coordinates;
}
Vector2 Organism::GetCoordinates()
{
	return coordinates;
}
World* Organism::GetWorld()
{
	return world;
}
int Organism::GetStrength() const
{
	return strength;
}
void Organism::SetStrength(int newStrength) 
{
	this->strength = newStrength;
}
void Organism::SetCoordinates(Vector2 newCoordinates)
{
	this->coordinates = newCoordinates;
}
int Organism::GetAge() const
{
	return age;
}
void Organism::SetAge(int newAge)
{
	this->age = newAge;
}
int Organism::GetMoveLength() const
{
	return moveLength;
}
int Organism::GetInitiative() const
{
	return initiative;
}
Organism::~Organism()
{
}