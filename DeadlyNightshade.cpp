#include <iostream>
#include "DeadlyNightshade.h"
using namespace std;

DeadlyNightshade::DeadlyNightshade()
{
}
DeadlyNightshade::DeadlyNightshade(Vector2 coordinates, World* world)
{
	this->initiative = 0;
	this->age = 0;
	this->strength = 99;
	this->world = world;
	this->coordinates.SetX(coordinates.GetX());
	this->coordinates.SetY(coordinates.GetY());
	cout << "DeadlyNightshade appears at (" << coordinates.GetX() << "," << coordinates.GetY() << ")\n";
}
DeadlyNightshade::DeadlyNightshade(int x, int y, World* world, int strength, int age)
{
	this->initiative = 0;
	this->age = age;
	this->strength = strength;
	this->world = world;
	this->coordinates.SetX(x);
	this->coordinates.SetY(y);
}
char DeadlyNightshade::GetSymbol() const
{
	return symbol;
}
void DeadlyNightshade::Breed()
{
	int chance = rand() % 100;
	if (chance < 20)
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
			Organism* newOrganism = new DeadlyNightshade(newCoordinates, world);
			world->SetField(newOrganism, newOrganism->GetCoordinates().GetX(), newOrganism->GetCoordinates().GetY());
			world->AddOrganism(newOrganism);
		}
	}

}
void DeadlyNightshade::Collision(Organism* attacker, Vector2 tmp)
{
	attacker->GetWorld()->DelOrganism(this);
	attacker->GetWorld()->SetField(nullptr, attacker->GetCoordinates().GetX(), attacker->GetCoordinates().GetY());
	attacker->GetWorld()->DelOrganism(attacker);
}
DeadlyNightshade::~DeadlyNightshade()
{
	cout << "DeadlyNightshade from (" << coordinates.GetX() << "," << coordinates.GetY() << ") dies\n";
}