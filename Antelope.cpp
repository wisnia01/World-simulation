#include <iostream>
#include <windows.h>
#include "Antelope.h"
using namespace std;
HANDLE hConsole2 = GetStdHandle(STD_OUTPUT_HANDLE);
Antelope::Antelope()
{
}
Antelope::Antelope(Vector2 coordinates, World* world)
{
	this->initiative = 4;
	this->moveLength = 2;
	this->age = 0;
	this->strength = 4;
	this->world = world;
	this->coordinates.SetX(coordinates.GetX());
	this->coordinates.SetY(coordinates.GetY());
	cout << "Antelope appears at (" << coordinates.GetX() << "," << coordinates.GetY() << ")\n";
}
Antelope::Antelope(int x, int y, World* world, int strength, int age)
{
	this->initiative = 4;
	this->moveLength = 2;
	this->age = age;
	this->strength = strength;
	this->world = world;
	this->coordinates.SetX(x);
	this->coordinates.SetY(y);
}
char Antelope::GetSymbol() const
{
	return symbol;
}
void Antelope::Breed()
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
		Organism* newOrganism = new Antelope(newCoordinates, world);
		world->SetField(newOrganism, newOrganism->GetCoordinates().GetX(), newOrganism->GetCoordinates().GetY());
		world->AddOrganism(newOrganism);
	}

}
void Antelope::Collision(Organism* attacker, Vector2 tmp)
{
	if (typeid(*this) == typeid(*attacker))
	{
		attacker->SetCoordinates(tmp);
		world->SetField(attacker, attacker->GetCoordinates().GetX(), attacker->GetCoordinates().GetY());
		if (this->age >= 5)
			Breed();
	}
	else
	{
		bool runaway = rand() % 2;
		if (runaway == 0)
		{

			if (attacker->GetStrength() > this->GetStrength())
			{
				world->DelOrganism(this); 
				attacker->GetWorld()->SetField(attacker, attacker->GetCoordinates().GetX(), attacker->GetCoordinates().GetY());
			}
			else
			{
				attacker->SetCoordinates(tmp);
				world->DelOrganism(attacker);
			}
		}
		else
		{
			world->SetField(attacker, attacker->GetCoordinates().GetX(), attacker->GetCoordinates().GetY());
			int newCoordX[4] = {};
			int newCoordY[4] = {};
			int whereGo = 0;
			int possibleMoves = 0;
			if (coordinates.GetX() + 1 < world->GetMapSize().GetX())
			{
				if (world->GetField(coordinates.GetX() + 1, coordinates.GetY()) == nullptr)
				{
					newCoordX[possibleMoves] = coordinates.GetX() + 1;
					newCoordY[possibleMoves] = coordinates.GetY();
					possibleMoves++;
				}

			}
			if (coordinates.GetX() - 1 >= 0)
			{
				if (world->GetField(coordinates.GetX() - 1, coordinates.GetY()) == nullptr)
				{
					newCoordX[possibleMoves] = coordinates.GetX() - 1;
					newCoordY[possibleMoves] = coordinates.GetY();
					possibleMoves++;
				}
			}
			if (coordinates.GetY() + 1 < world->GetMapSize().GetY())
			{
				if (world->GetField(coordinates.GetX(), coordinates.GetY() + 1) == nullptr)
				{
					newCoordY[possibleMoves] = coordinates.GetY() + 1;
					newCoordX[possibleMoves] = coordinates.GetX();
					possibleMoves++;
				}
			}
			if (coordinates.GetY() - 1 >= 0)
			{
				if (world->GetField(coordinates.GetX(), coordinates.GetY() - 1) == nullptr)
				{
					newCoordY[possibleMoves] = coordinates.GetY() - 1;
					newCoordX[possibleMoves] = coordinates.GetX();
					possibleMoves++;
				}
			}
			if (possibleMoves != 0)
			{
				whereGo = rand() % possibleMoves;
				coordinates.SetX(newCoordX[whereGo]);
				coordinates.SetY(newCoordY[whereGo]);
				world->SetField(this, coordinates.GetX(), coordinates.GetY());
			}
			else
				world->DelOrganism(this);
			

		}
	}
}
Antelope::~Antelope()
{
	cout << "Antelope from (" << coordinates.GetX() << "," << coordinates.GetY() << ") dies\n";
}