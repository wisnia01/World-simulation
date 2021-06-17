#include <iostream>
#include "Guarana.h"
using namespace std;

Guarana::Guarana()
{
}
Guarana::Guarana(Vector2 coordinates, World* world)
{
	this->initiative = 0;
	this->age = 0;
	this->strength = 0;
	this->world = world;
	this->coordinates.SetX(coordinates.GetX());
	this->coordinates.SetY(coordinates.GetY());
	cout << "Guarana appears at (" << coordinates.GetX() << "," << coordinates.GetY() << ")\n";
}
Guarana::Guarana(int x, int y, World* world, int strength, int age)
{
	this->initiative = 0;
	this->age = age;
	this->strength = strength;
	this->world = world;
	this->coordinates.SetX(x);
	this->coordinates.SetY(y);
}
char Guarana::GetSymbol() const
{
	return symbol;
}
void Guarana::Breed()
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
			Organism* newOrganism = new Guarana(newCoordinates, world);
			world->SetField(newOrganism, newOrganism->GetCoordinates().GetX(), newOrganism->GetCoordinates().GetY());
			world->AddOrganism(newOrganism);
		}
	}
}
void Guarana::Collision(Organism* attacker, Vector2 tmp)
{
	world->DelOrganism(this);
	attacker->SetStrength(attacker->GetStrength() + 3);
	attacker->GetWorld()->SetField(attacker, attacker->GetCoordinates().GetX(), attacker->GetCoordinates().GetY());
}
Guarana::~Guarana()
{
	cout << "Guarana from (" << coordinates.GetX() << "," << coordinates.GetY() << ") dies\n";
}