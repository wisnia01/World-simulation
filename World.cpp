#include <iostream>
#include <windows.h>
#include "World.h"
#include "Wolf.h"
#include "Organism.h"
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void World::DrawWorld()
{
	//system("cls");
	cout << "Move number: " << moveCount << endl;
	for (int i = 0; i < numberOfOrganisms; i++)
	{
		Vector2 coords = organisms[i]->GetCoordinates();
		field[coords.GetY()][coords.GetX()] = organisms[i];
	}
	for (int i = 0; i < mapSize.GetY(); i++)
	{
		for (int j = 0; j < mapSize.GetX(); j++)
		{
	
			if (field[i][j] == nullptr)
			{
				cout << "-" << " ";
			}
			else
			{
				if (field[i][j]->GetSymbol() == 'W')
					SetConsoleTextAttribute(hConsole, 4);
				else if(field[i][j]->GetSymbol() == 'F')
					SetConsoleTextAttribute(hConsole, 4);
				else if(field[i][j]->GetSymbol() == 'S')
					SetConsoleTextAttribute(hConsole, 4);
				else if(field[i][j]->GetSymbol() == 'T')
					SetConsoleTextAttribute(hConsole, 4);
				else if (field[i][j]->GetSymbol() == 'A')
					SetConsoleTextAttribute(hConsole, 4);
				else if (field[i][j]->GetSymbol() == 'L')
					SetConsoleTextAttribute(hConsole, 2);
				else if (field[i][j]->GetSymbol() == 'D')
					SetConsoleTextAttribute(hConsole, 2);
				else if (field[i][j]->GetSymbol() == 'G')
					SetConsoleTextAttribute(hConsole, 2);
				else if (field[i][j]->GetSymbol() == 'N')
					SetConsoleTextAttribute(hConsole, 2);
				else if (field[i][j]->GetSymbol() == 'H')
					SetConsoleTextAttribute(hConsole, 2);
					
				cout << field[i][j]->GetSymbol() << " ";
				SetConsoleTextAttribute(hConsole, 7);
			}
		}
		cout << endl;
	}
	cout << endl;
}
void World::MakeMove()
{

	Organism *tmp;
	int i, j;
	for (i = 0; i < numberOfOrganisms - 1; i++)

	//	// Last i elements are already in place 
		for (j = 0; j < numberOfOrganisms - i - 1; j++)
		{
			if (organisms[j]->GetInitiative() < organisms[j + 1]->GetInitiative())
			{
				tmp = organisms[j];
				organisms[j] = organisms[j + 1];
				organisms[j + 1] = tmp;

			}
			else if (organisms[j]->GetInitiative() == organisms[j + 1]->GetInitiative())
			for (int k = 0; k + j < numberOfOrganisms - 1; k++)
				{
					for (int l = 0; l < organisms[l+1]->GetInitiative()> organisms[l]->GetInitiative(); l++)
					{
						if (organisms[l]->GetAge() < organisms[l + 1]->GetAge())
						{
							tmp = organisms[l];
							organisms[l] = organisms[l + 1];
							organisms[l + 1] = tmp;
						}
					}
				}
		}
	moveCount++;
	for (int i = 0; i < numberOfOrganisms; i++) //moze do zmiany
	{
		if (organisms[i] != nullptr)
		{
			organisms[i]->SetAge(organisms[i]->GetAge() + 1);
			if (organisms[i]->GetAge() > 0)
				organisms[i]->Action();
		}
		if (deletedOrganism != -1)
		{
			if(deletedOrganism<=i)
				i--;
			deletedOrganism = -1;
		}
	}
	howLongLastPowerSet++;
	if (howLongLastPowerSet == 5)
	{
		isPowerSet = false;
		cout << "ABILITY DISABLED\n";
	}
	humanChoice = 0;
}
World::World()
{

}
World::World(Vector2 *mapSize)
{
	isHumanAlive = true;
	howLongLastPowerSet = 99;
	deletedOrganism = -1;
	moveCount = 0;
	this->mapSize = *mapSize;
	field = new Organism**[this->mapSize.GetY()];
	for (int i = 0; i < this->mapSize.GetY(); i++)
	{
		field[i] = new Organism * [this->mapSize.GetX()];
	}
	organisms = new Organism * [this->mapSize.GetY() * this->mapSize.GetX()];
	for (int i = 0; i < this->mapSize.GetY() * this->mapSize.GetX(); i++)
	{
		organisms[i] = nullptr;
	}
	numberOfOrganisms = 0;
	
	for (int i = 0; i < this->mapSize.GetY(); i++)
	{
		for (int j = 0; j < this->mapSize.GetX(); j++)
		{
			this->field[i][j] = nullptr;
		}
	}
}
void World::AddOrganism(Organism* newOrganism)
{
	if (numberOfOrganisms== this->mapSize.GetY() * this->mapSize.GetX())
		cout << "MAX ORGANISMS, ERROR MAY OCCURE\n";
	organisms[numberOfOrganisms] = newOrganism;
	field[newOrganism->GetCoordinates().GetY()][newOrganism->GetCoordinates().GetX()] = newOrganism;
	numberOfOrganisms++;
	
}
void World::DelOrganism(Organism* organismToDel)
{
	bool start = false;
	field[organismToDel->GetCoordinates().GetY()][organismToDel->GetCoordinates().GetX()] = nullptr;
	for (int i = 0; i < this->mapSize.GetY() * this->mapSize.GetX(); i++)
	{
		if (organisms[i] == organismToDel)
		{
			deletedOrganism = i;
			organisms[i] = nullptr;
			start = true;
		}
		if (start)
		{
			if (i != this->mapSize.GetY() * this->mapSize.GetX() - 1)
				organisms[i] = organisms[i + 1];
			
		}
	}
	organisms[this->mapSize.GetY() * this->mapSize.GetX() - 1] = nullptr;
	numberOfOrganisms--;
	delete organismToDel;

	
}
void World::ReadPosition(Organism* organism)
{

}
void World::SetField(Organism* newField, int x, int y)
{

	field[y][x] = newField;
}
Organism *World::GetField(int x, int y)
{
	return field[y][x];
}
Vector2 World::GetMapSize()
{
	return mapSize;
}
int World::GetMoveCount()
{
	return moveCount;
}
void World::SetHumanChoice(int humanChoice)
{
	this->humanChoice = humanChoice;
}
int World::GetHumanChoice()
{
	return humanChoice;
}
void World::SetPower(bool isset)
{
	this->isPowerSet = isset;
}
bool World::GetPower()
{
	return isPowerSet;
}
void World::ResetHowLong()
{
	howLongLastPowerSet = 0;
}
int World::GetHowLong()
{
	return howLongLastPowerSet;
}
void World::SetHumanAlive(bool dead)
{
	this->isHumanAlive = dead;
}
bool World::GetHumanAlive()
{
	return isHumanAlive;
}
int World::GetNumberOfOrganisms()
{
	return numberOfOrganisms;
}
Organism* World::GetOrganism(int i)
{
	return organisms[i];
}
void World::SetMoveCount(int moveCount)
{
	this->moveCount = moveCount;
}
void World::SetHowLong(int howLong)
{
	this->howLongLastPowerSet = howLong;
}
World::~World()
{
	
	for (int i = 0; i < this->mapSize.GetY(); i++)
	{
		delete field[i];
	}
	delete field;
	delete[] organisms;
}