#pragma once
#include <iostream>
#include "World.h"
using namespace std;

class Generator
{
private:
	World* world;

public:
	Generator(World* world);
	void Generate();
	void GenerateSet();
};