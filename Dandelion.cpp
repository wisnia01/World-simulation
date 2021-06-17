#include <iostream>
#include "Dandelion.h"
using namespace std;

Dandelion::Dandelion()
{
}
Dandelion::Dandelion(Vector2 coordinates, World* world)
{
	this->initiative = 0;
	this->age = 0;
	this->strength = 0;
	this->world = world;
	this->coordinates.SetX(coordinates.GetX());
	this->coordinates.SetY(coordinates.GetY());
	cout << "Dandelion appears at (" << coordinates.GetX() << "," << coordinates.GetY() << ")\n";
}
Dandelion::Dandelion(int x, int y, World* world, int strength, int age)
{
	this->initiative = 0;
	this->age = age;
	this->strength = strength;
	this->world = world;
	this->coordinates.SetX(x);
	this->coordinates.SetY(y);
}
char Dandelion::GetSymbol() const
{
	return symbol;
}
void Dandelion::Breed()
{
	for (int i = 0; i < 3; i++)
	{
		int dandelionTry = rand() % 100;
		if (dandelionTry < 15)
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
				Organism* newOrganism = new Dandelion(newCoordinates, world);
				world->SetField(newOrganism, newOrganism->GetCoordinates().GetX(), newOrganism->GetCoordinates().GetY());
				world->AddOrganism(newOrganism);
			}
		}
	}

}
Dandelion::~Dandelion()
{
	cout << "Dandelion from (" << coordinates.GetX() << "," << coordinates.GetY() << ") dies\n";
}
