#include <iostream>
#include "Fox.h"
using namespace std;

Fox::Fox()
{
}
Fox::Fox(Vector2 coordinates, World* world)
{
	this->initiative = 7;
	this->age = 0;
	this->moveLength = 1;
	this->strength = 3;
	this->world = world;
	this->coordinates.SetX(coordinates.GetX());
	this->coordinates.SetY(coordinates.GetY());
	cout << "Fox appears at (" << coordinates.GetX() << "," << coordinates.GetY() << ")\n";
}
Fox::Fox(int x, int y, World* world, int strength, int age)
{
	this->initiative = 7;
	this->age = age;
	this->moveLength = 1;
	this->strength = strength;
	this->world = world;
	this->coordinates.SetX(x);
	this->coordinates.SetY(y);
}
char Fox::GetSymbol() const
{
	return symbol;
}
void Fox::Move(int moveLength)
{
	world->SetField(nullptr, coordinates.GetX(), coordinates.GetY());

	int newCoordX[4] = {};
	int newCoordY[4] = {};
	int whereGo = 0;
	int possibleMoves = 0;
	if (coordinates.GetX() + moveLength < world->GetMapSize().GetX()) 
	{
		if (world->GetField(coordinates.GetX() + moveLength, coordinates.GetY()) == nullptr || world->GetField(coordinates.GetX() + moveLength, coordinates.GetY())->GetStrength() <= strength)
		{
			newCoordX[possibleMoves] = coordinates.GetX() + moveLength;
			newCoordY[possibleMoves] = coordinates.GetY();
			possibleMoves++;
		}

	}
	if (coordinates.GetX() - moveLength >= 0)
	{
		if (world->GetField(coordinates.GetX() - moveLength, coordinates.GetY()) == nullptr || world->GetField(coordinates.GetX() - moveLength, coordinates.GetY())->GetStrength() <= strength)
		{
			newCoordX[possibleMoves] = coordinates.GetX() - moveLength;
			newCoordY[possibleMoves] = coordinates.GetY();
			possibleMoves++;
		}
	}
	if (coordinates.GetY() + moveLength < world->GetMapSize().GetY())
	{
		if (world->GetField(coordinates.GetX(), coordinates.GetY() + moveLength) == nullptr || world->GetField(coordinates.GetX(), coordinates.GetY() + moveLength)->GetStrength() <= strength)
		{
			newCoordY[possibleMoves] = coordinates.GetY() + moveLength;
			newCoordX[possibleMoves] = coordinates.GetX();
			possibleMoves++;
		}
	}
	if (coordinates.GetY() - moveLength >= 0)
	{
		if (world->GetField(coordinates.GetX() , coordinates.GetY() - moveLength) == nullptr || world->GetField(coordinates.GetX(), coordinates.GetY() - moveLength)->GetStrength() <= strength)
		{
			newCoordY[possibleMoves] = coordinates.GetY() - moveLength;
			newCoordX[possibleMoves] = coordinates.GetX();
			possibleMoves++;
		}
	}
	if (possibleMoves != 0)
	{
		whereGo = rand() % possibleMoves;
		coordinates.SetX(newCoordX[whereGo]);
		coordinates.SetY(newCoordY[whereGo]);
	}


}
void Fox::Breed()
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
		Organism* newOrganism = new Fox(newCoordinates, world);
		world->SetField(newOrganism, newOrganism->GetCoordinates().GetX(), newOrganism->GetCoordinates().GetY());
		world->AddOrganism(newOrganism);
	};

}
Fox::~Fox()
{
	cout << "Fox from (" << coordinates.GetX() << "," << coordinates.GetY() << ") dies\n";
}