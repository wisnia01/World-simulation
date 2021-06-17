#include <iostream>
#include "Human.h"
using namespace std;

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

Human::Human()
{
}
Human::Human(Vector2 coordinates, World* world)
{
	this->initiative = 4;
	this->age = 0;
	this->moveLength = 1;
	this->strength = 5;
	this->world = world;
	this->coordinates.SetX(coordinates.GetX());
	this->coordinates.SetY(coordinates.GetY());
}
Human::Human(int x, int y, World* world, int strength, int age)
{
	this->initiative = 4;
	this->age = age;
	this->moveLength = 1;
	this->strength = strength;
	this->world = world;
	this->coordinates.SetX(x);
	this->coordinates.SetY(y);
}
char Human::GetSymbol() const
{
	return symbol;
}
void Human::Breed()
{
	//human cannot breed
	cout << "How did it happen?\n";
	return;
}

void Human::Move(int moveLength)
{
	world->SetField(nullptr, coordinates.GetX(), coordinates.GetY());
	switch (world->GetHumanChoice())
	{
		case UP:
		{
			if (coordinates.GetY() - 1 >= 0)
			{
				coordinates.SetY(coordinates.GetY() - 1);
			}
			else
			{
				cout << "Wrong action, move losed.\n";
			}
			break;
		}
		case DOWN:
		{
			if (coordinates.GetY() + 1 < world->GetMapSize().GetY())
			{
				coordinates.SetY(coordinates.GetY() + 1);
			}
			else
			{
				cout << "Wrong action, move losed.\n";
			}
			break;
		}
		case LEFT:
		{
			if (coordinates.GetX() - 1 >= 0)
			{
				coordinates.SetX(coordinates.GetX() - 1);
			}
			
			else
			{
				cout << "Wrong action, move losed.\n";
			}
			break;
		}
		case RIGHT:
		{
			if (coordinates.GetX() + 1 < world->GetMapSize().GetX())
			{
				coordinates.SetX(coordinates.GetX() + 1);
			}
			
			else
			{
				cout << "Wrong action, move losed.\n";
			}
			break;
		}
		default:
		{
			cout << "Wrong action, no arrow clicked, move losed.\n";
		}
	}
}
void Human::Collision(Organism* attacker, Vector2 tmp)
{
	if (world->GetPower())
	{
		attacker->SetCoordinates(tmp);
		world->SetField(attacker, tmp.GetX(), tmp.GetY());
		cout << "SUPER ABILITY\n";
	}
	else
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
Human::~Human()
{
	world->SetHumanAlive(false);
	cout << "Human from (" << coordinates.GetX() << "," << coordinates.GetY() << ") dies\n";
}