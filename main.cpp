#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "World.h"
#include "Human.h"
#include "Vector2.h"
#include "Generator.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Vector2* mapSize = new Vector2;
	World* world = nullptr;
	Generator* generator = nullptr;
	bool askAgain = true;
	int mapWidth, mapHeight;
	bool newGame, goodOption = true;
	char option;
	int tmp, arrow;
	bool isArrow = true;
	while (goodOption)
	{
		cout << "Jakub Wasniewski s184943\n";
		cout << "Hello, choose you option:\nNew game: n\nLoad game: l\n";
		option = _getch();
		if (option == 'n')
		{
			newGame = true;
			goodOption = false;
		}
		else if (option == 'l')
			newGame = goodOption = false;
		else
		{
			system("cls");
			cout << "Choose valid option!\n";
			Sleep(1000);
			system("cls");
		}
	}

	if (newGame)
	{
		while (askAgain)
		{
			cout << "Set game width and height:";
			cin >> mapWidth >> mapHeight;
			if (mapWidth * mapHeight >= 25)
				askAgain = false;
			else
			{
				system("cls");
				cout << "Wrong values, there should be enough place for all organisms\nMin amount of fields is 25\n";
			}
		}

		mapSize->SetX(mapWidth);
		mapSize->SetY(mapHeight);
		world = new World(mapSize);
		generator = new Generator(world);
		generator->Generate();

	}
	else
	{
		system("cls");
		fstream file;
		file.open("gamefile.txt", ios::in);
		if (!file)
		{
			cout << "Problems with opening file, exiting program";
		}
		else
		{
			cout << "File opened\n";
			string fromFile;
			getline(file, fromFile);
			istringstream divide(fromFile);

			string s[5];
			int i = 0;
			while (getline(divide, s[i], ' ')) {
				i++;
			}
			mapWidth = stoi(s[0]);
			mapHeight = stoi(s[1]);
			mapSize->SetX(mapWidth);
			mapSize->SetY(mapHeight);
			world = new World(mapSize);
			world->SetMoveCount(stoi(s[2]));
			world->SetHowLong(stoi(s[3]));
			world->SetPower(stoi(s[4]));
			file.close();
			generator = new Generator(world);
			generator->GenerateSet();
			
		}
	}

		system("cls");
		while (world->GetHumanAlive())
		{
			isArrow = true;
			world->DrawWorld();
			tmp = arrow = 0;
			cout << "p for superpower, s for save\n";

			while (isArrow)
			{
				tmp = arrow = 0;
				tmp = _getch();

				if (tmp == 224)
				{
					arrow = _getch();
					world->SetHumanChoice(arrow);
					isArrow = false;
				}
				else if (tmp == 'p' && world->GetHowLong() > 10)
				{
					world->SetPower(true);
					world->ResetHowLong();
					cout << "ABILITY SET\n";
				}
				else if (tmp == 's')
				{
					fstream file;
					cout << "saved\n";
					file.open("gamefile.txt", ios::out);
					file << mapWidth << " " << mapHeight << " " << world->GetMoveCount() << " " << world->GetHowLong() << " " << world->GetPower()<< "\n";
					for (int i = 0; i < world->GetNumberOfOrganisms(); i++)
					{
						file << world->GetOrganism(i)->GetSymbol() << " " << world->GetOrganism(i)->GetCoordinates().GetX() << " " << world->GetOrganism(i)->GetCoordinates().GetY() << " " << world->GetOrganism(i)->GetStrength() << " " << world->GetOrganism(i)->GetAge() << "\n";
					}

					file.close();
				}
			}
			system("cls");
			world->MakeMove();
		}
		world->DrawWorld();
		cout << "YOU DIED\nGAME OVER\n";
		delete world;
		delete generator;
		delete mapSize;
		return 0;
	



}
