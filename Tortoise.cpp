#include <iostream>
#include "Tortoise.h"
using namespace std;

Tortoise::Tortoise()
{
}
Tortoise::Tortoise(Vector2 coordinates, World* world)
{
	this->initiative = 1;
	this->moveLength = 1;
	this->age = 0;
	this->strength = 2;
	this->world = world;
	this->coordinates.SetX(coordinates.GetX());
	this->coordinates.SetY(coordinates.GetY());
	cout << "Tortoise appears at (" << coordinates.GetX() << "," << coordinates.GetY() << ")\n";
}
Tortoise::Tortoise(int x, int y, World* world, int strength, int age)
{
	this->initiative = 1;
	this->age = age;
	this->moveLength = 1;
	this->strength = strength;
	this->world = world;
	this->coordinates.SetX(x);
	this->coordinates.SetY(y);
}
char Tortoise::GetSymbol() const
{
	return symbol;
}
void Tortoise::Move(int moveLength)
{
	int IamLazy = rand() % 4;
	if (IamLazy == 0)
	{
		world->SetField(nullptr, coordinates.GetX(), coordinates.GetY());

		int newCoordX[4] = {};
		int newCoordY[4] = {};
		int whereGo = 0;
		int possibleMoves = 0;
		if (coordinates.GetX() + moveLength < world->GetMapSize().GetX())
		{
			newCoordX[possibleMoves] = coordinates.GetX() + moveLength;
			newCoordY[possibleMoves] = coordinates.GetY();
			possibleMoves++;
		}
		if (coordinates.GetX() - moveLength >= 0)
		{
			newCoordX[possibleMoves] = coordinates.GetX() - moveLength;
			newCoordY[possibleMoves] = coordinates.GetY();
			possibleMoves++;
		}
		if (coordinates.GetY() + moveLength < world->GetMapSize().GetY())
		{
			newCoordY[possibleMoves] = coordinates.GetY() + moveLength;
			newCoordX[possibleMoves] = coordinates.GetX();
			possibleMoves++;
		}
		if (coordinates.GetY() - moveLength >= 0)
		{
			newCoordY[possibleMoves] = coordinates.GetY() - moveLength;
			newCoordX[possibleMoves] = coordinates.GetX();
			possibleMoves++;
		}
		whereGo = rand() % possibleMoves;
		coordinates.SetX(newCoordX[whereGo]);
		coordinates.SetY(newCoordY[whereGo]);
	}


}
void Tortoise::Breed()
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
		Organism* newOrganism = new Tortoise(newCoordinates, world);
		world->SetField(newOrganism, newOrganism->GetCoordinates().GetX(), newOrganism->GetCoordinates().GetY());
		world->AddOrganism(newOrganism);
	};

}
bool Tortoise::IsDeflected(Organism& attacker)
{
	if (attacker.GetStrength() < 5)
		return true;
	return false;
}
void Tortoise::Collision(Organism* attacker, Vector2 tmp) 
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
			if (IsDeflected(*attacker))
			{
				attacker->SetCoordinates(tmp);
				world->SetField(attacker, tmp.GetX(), tmp.GetY());
				cout << "Turtoise deflecting attack\n";
				return;
			}
			else
			{
				if (attacker->GetStrength() > this->GetStrength())
				{
					world->DelOrganism(this); //tu zamienilem kolejnoscia
					attacker->GetWorld()->SetField(attacker, attacker->GetCoordinates().GetX(), attacker->GetCoordinates().GetY());
				}
				else
				{
					attacker->SetCoordinates(tmp);
					world->DelOrganism(attacker);
				}
			}
		}
}
Tortoise::~Tortoise()
{
	cout << "Tortoise from (" << coordinates.GetX() << "," << coordinates.GetY() << ") dies\n";
}