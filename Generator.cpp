#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include "Generator.h"
#include "World.h"
#include "Grass.h"
#include "Wolf.h"
#include "Fox.h"
#include "Antelope.h"
#include "Hogweed.h"
#include "Human.h"
#include "Guarana.h"
#include "DeadlyNightshade.h"
#include "Tortoise.h"
#include "Dandelion.h"
#include "Sheep.h"
#include "Vector2.h"
using namespace std;

Generator::Generator(World* world)
{
	this->world = world;
}
void Generator::Generate() //minimum 2 animals each race, 2 plant each race + human. for every 40 fields add +1 each animal and plant
{
	int additionalOrganisms = (world->GetMapSize().GetX()* world->GetMapSize().GetY()) / 40;
	int numberOfAllOrganisms = 1 + (2 + additionalOrganisms) * 5 + (2 + additionalOrganisms) * 5;
	int eachRace = additionalOrganisms + 2;
	int newX, newY; 
	Vector2 coordinates;
	Organism* newOrganism;
	for(int i = 0; i<numberOfAllOrganisms; i++)
	{
		newX = rand() % world->GetMapSize().GetX();
		newY = rand() % world->GetMapSize().GetY();
		coordinates.SetX(newX);
		coordinates.SetY(newY);
		if (i < eachRace)
		{
			if (world->GetField(newX, newY) == nullptr)
			{
				newOrganism = new Antelope(coordinates, world);
				world->AddOrganism(newOrganism);
			}
			else
				i--;
		}
		if (i >= eachRace && i < 2 * eachRace)
		{
			if (world->GetField(newX, newY) == nullptr)
			{
				newOrganism = new Fox(coordinates, world);
				world->AddOrganism(newOrganism);
			}
			else
				i--;
		}
		if (i >= 2*eachRace && i < 3 * eachRace)
		{
			if (world->GetField(newX, newY) == nullptr)
			{
				newOrganism = new Sheep(coordinates, world);
				world->AddOrganism(newOrganism);
			}
			else
				i--;
		}
		if (i >= 3*eachRace && i < 4 * eachRace)
		{
			if (world->GetField(newX, newY) == nullptr)
			{
				newOrganism = new Tortoise(coordinates, world);
				world->AddOrganism(newOrganism);
			}
			else
				i--;
		}
		if (i >= 4*eachRace && i < 5 * eachRace)
		{
			if (world->GetField(newX, newY) == nullptr)
			{
				newOrganism = new Wolf(coordinates, world);
				world->AddOrganism(newOrganism);
			}
			else
				i--;
		}
		if (i >= 5*eachRace && i < 6 * eachRace)
		{
			if (world->GetField(newX, newY) == nullptr)
			{
				newOrganism = new Dandelion(coordinates, world);
				world->AddOrganism(newOrganism);
			}
			else
				i--;
		}
		if (i >= 6*eachRace && i < 7 * eachRace)
		{
			if (world->GetField(newX, newY) == nullptr)
			{
				newOrganism = new DeadlyNightshade(coordinates, world);
				world->AddOrganism(newOrganism);
			}
			else
				i--;
		}
		if (i >= 7*eachRace && i < 8* eachRace)
		{
			if (world->GetField(newX, newY) == nullptr)
			{
				newOrganism = new Grass(coordinates, world);
				world->AddOrganism(newOrganism);
			}
			else
				i--;
		}
		if (i >= 8*eachRace && i < 9 * eachRace)
		{
			if (world->GetField(newX, newY) == nullptr)
			{
				newOrganism = new Guarana(coordinates, world);
				world->AddOrganism(newOrganism);
			}
			else
				i--;
		}
		if (i >= 9*eachRace && i < 10 * eachRace)
		{
			if (world->GetField(newX, newY) == nullptr)
			{
				newOrganism = new Hogweed(coordinates, world);
				world->AddOrganism(newOrganism);
			}
			else
				i--;
		}
		if (i == numberOfAllOrganisms - 1)
		{
			if (world->GetField(newX, newY) == nullptr)
			{
				newOrganism = new Human(coordinates, world);
				world->AddOrganism(newOrganism);
			}
			else
				i--;
		}
			
	}
	
}
void Generator::GenerateSet()
{
	Organism* newOrganism;
	fstream file;
	file.open("gamefile.txt", ios::in);
	string fromFile;
	string s[5];
	getline(file, fromFile); // skipping first line
	while (!file.eof())
	{
		getline(file, fromFile);
		istringstream divide(fromFile);


		int i = 0;
		while (getline(divide, s[i], ' ')) {
			i++;
		}
		if (s[0] == "A")
		{
			newOrganism = new Antelope(stoi(s[1]), stoi(s[2]), world, stoi(s[3]), stoi(s[4]));
			world->AddOrganism(newOrganism);
		}
		else if (s[0] == "F")
		{
			newOrganism = new Fox(stoi(s[1]), stoi(s[2]), world, stoi(s[3]), stoi(s[4]));
			world->AddOrganism(newOrganism);
		}
		else if (s[0] == "S")
		{
			newOrganism = new Sheep(stoi(s[1]), stoi(s[2]), world, stoi(s[3]), stoi(s[4]));
			world->AddOrganism(newOrganism);
		}
		else if (s[0] == "T")
		{
			newOrganism = new Tortoise(stoi(s[1]), stoi(s[2]), world, stoi(s[3]), stoi(s[4]));
			world->AddOrganism(newOrganism);
		}
		else if (s[0] == "W")
		{
			newOrganism = new Wolf(stoi(s[1]), stoi(s[2]), world, stoi(s[3]), stoi(s[4]));
			world->AddOrganism(newOrganism);
		}
		else if (s[0] == "D")
		{
			newOrganism = new Dandelion(stoi(s[1]), stoi(s[2]), world, stoi(s[3]), stoi(s[4]));
			world->AddOrganism(newOrganism);
		}
		else if (s[0] == "N")
		{
			newOrganism = new DeadlyNightshade(stoi(s[1]), stoi(s[2]), world, stoi(s[3]), stoi(s[4]));
			world->AddOrganism(newOrganism);
		}
		else if (s[0] == "L")
		{
			newOrganism = new Grass(stoi(s[1]), stoi(s[2]), world, stoi(s[3]), stoi(s[4]));
			world->AddOrganism(newOrganism);
		}
		else if (s[0] == "G")
		{
			newOrganism = new Guarana(stoi(s[1]), stoi(s[2]), world, stoi(s[3]), stoi(s[4]));
			world->AddOrganism(newOrganism);
		}
		else if (s[0] == "H")
		{
			newOrganism = new Hogweed(stoi(s[1]), stoi(s[2]), world, stoi(s[3]), stoi(s[4]));
			world->AddOrganism(newOrganism);
		}
		else if (s[0] == "#")
		{
			newOrganism = new Human(stoi(s[1]), stoi(s[2]), world, stoi(s[3]), stoi(s[4]));
			world->AddOrganism(newOrganism);
		}
	}
	file.close();
}