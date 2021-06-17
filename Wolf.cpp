#include <iostream>
#include "Wolf.h"
using namespace std;

Wolf::Wolf()
{
}
Wolf::Wolf(Vector2 coordinates, World* world)
{
	this->initiative = 5;
	this->moveLength = 1;
	this->age = 0;
	this->strength = 9;
	this->world = world;
	this->coordinates.SetX(coordinates.GetX());
	this->coordinates.SetY(coordinates.GetY());
	cout << "Wolf appears at (" << coordinates.GetX() << "," << coordinates.GetY() << ")\n";
}
Wolf::Wolf (int x, int y, World* world, int strength, int age)
{
	this->initiative = 5;
	this->age = age;
	this->moveLength = 1;
	this->strength = strength;
	this->world = world;
	this->coordinates.SetX(x);
	this->coordinates.SetY(y);
}
char Wolf::GetSymbol() const
{
	return symbol;
}
void Wolf::Breed()
{
	
	int newCoordX[4] = {};
	int newCoordY[4] = {};
	int whereGo = 0;
	int possibleMoves = 0;
	if (coordinates.GetX() + 1 < world->GetMapSize().GetX() && world->GetField(coordinates.GetX() + 1, coordinates.GetY()) == nullptr)
	{
		newCoordX[possibleMoves] = coordinates.GetX() + 1;
		newCoordY[possibleMoves] = coordinates.GetY();
		possibleMoves++;
	}
	if (coordinates.GetX() - 1 >= 0 && world->GetField(coordinates.GetX() - 1, coordinates.GetY()) == nullptr)
	{
		newCoordX[possibleMoves] = coordinates.GetX() - 1;
		newCoordY[possibleMoves] = coordinates.GetY();
		possibleMoves++;
	}
	if (coordinates.GetY() + 1 < world->GetMapSize().GetY() && world->GetField(coordinates.GetX(), coordinates.GetY() + 1) == nullptr)
	{
		newCoordY[possibleMoves] = coordinates.GetY() + 1;
		newCoordX[possibleMoves] = coordinates.GetX();
		possibleMoves++;
	}
	if (coordinates.GetY() - 1 >= 0 && world->GetField(coordinates.GetX(), coordinates.GetY() - 1) == nullptr)
	{
		newCoordY[possibleMoves] = coordinates.GetY() - 1;
		newCoordX[possibleMoves] = coordinates.GetX();
		possibleMoves++;
	}
	if (possibleMoves != 0)
	{
		whereGo = rand() % possibleMoves;
		Vector2 newCoordinates;
		newCoordinates.SetX(newCoordX[whereGo]);
		newCoordinates.SetY(newCoordY[whereGo]);
		Organism* newOrganism = new Wolf(newCoordinates, world);
		world->SetField(newOrganism, newOrganism->GetCoordinates().GetX(), newOrganism->GetCoordinates().GetY());
		world->AddOrganism(newOrganism);
	}
	
}
Wolf::~Wolf()
{
	cout << "Wolf from (" << coordinates.GetX() << "," << coordinates.GetY() << ") dies\n";
}
