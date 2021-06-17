#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <time.h>
#include "Plant.h"
using namespace std;

Plant::Plant()
{

}
void Plant::Collision(Organism* attacker, Vector2 tmp)
{
	world->DelOrganism(this);
	attacker->GetWorld()->SetField(attacker, attacker->GetCoordinates().GetX(), attacker->GetCoordinates().GetY());
}
void Plant::Action()
{
	if(age>2)
		Breed();
}
Plant::~Plant()
{
}
