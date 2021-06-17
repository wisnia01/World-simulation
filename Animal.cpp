#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <time.h>
#include "Animal.h"
using namespace std;

Animal::Animal()
{

}
void Animal::Move(int moveLength)
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
void Animal::Collision(Organism *attacker, Vector2 tmp)
{
	if (typeid(*this) == typeid(*attacker))
	{
		attacker->SetCoordinates(tmp);
		world->SetField(attacker, attacker->GetCoordinates().GetX(), attacker->GetCoordinates().GetY());
		if(this->age>=5)
			Breed();
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
void Animal::Action()
{
	Vector2 tmp = this->GetCoordinates();
	this->Move(this->GetMoveLength());
	if (tmp.GetX() == this->GetCoordinates().GetX() && tmp.GetY() == this->GetCoordinates().GetY())
		world->SetField(this, coordinates.GetX(), coordinates.GetY());
	else
	{
		if (world->GetField(coordinates.GetX(), coordinates.GetY()) != nullptr)
		{
			world->GetField(coordinates.GetX(), coordinates.GetY())->Collision(this, tmp);
		}
		else
		{
			world->SetField(this, coordinates.GetX(), coordinates.GetY());
		}
	}
		
}
Animal::~Animal()
{
}