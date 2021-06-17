#pragma once
#include <iostream>
#include "Vector2.h"
#include "Organism.h"

class Organism;

class World
{
private:
	int moveCount;
	Organism **organisms;
	Vector2 mapSize;
	Organism*** field;
	int numberOfOrganisms;
	int humanChoice;
	int deletedOrganism;
	bool isPowerSet;
	int howLongLastPowerSet;
	bool isHumanAlive;

public:
	void DrawWorld();
	void MakeMove();
	World();
	~World();
	World(Vector2 *mapSize);
	void SetField(Organism *newField, int x, int y);
	Organism *GetField(int x, int y);
	int GetMoveCount();
	void AddOrganism(Organism *newOrganism);
	void DelOrganism(Organism *organismToDel);
	void ReadPosition(Organism *Organism); 
	Vector2 GetMapSize();
	void SetHumanChoice(int humanChoice);
	int GetHumanChoice();
	void SetPower(bool isset);
	bool GetPower();
	void ResetHowLong();
	void SetHowLong(int howLong);
	int GetHowLong();
	void SetHumanAlive(bool dead);
	bool GetHumanAlive();
	int GetNumberOfOrganisms();
	Organism *GetOrganism(int i);
	void SetMoveCount(int moveCount);



};