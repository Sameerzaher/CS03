#include <iostream>
#include "Classes.h"
#include "Game.h"

using namespace std;


int main()
{
	Player p1("Jony", 100, 1, 1);
	Player* p2 = new Player("James", 55, 10, 15);

	p1.print();
	p2->print();

	/*------------------------------------------------------------*/
	Game game; // Instantiation
	game.addPlayer(p1);
	game.addPlayer(*p2);
	game.addPlayer(*p2);
	game.Print();

	//Calls Copy constructor
	Game gameCopy = game;
	Game gameCopy1(game);

	//Create new object defualt constructor
	Game game1;

	//Calls assignment operator and performs deep copy
	//Without assignment operator performs shallow copy like using
	//memset to copy the whole object into another one
	game1 = game;
	game1.Print();
	/*------------------------------------------------------------*/

	delete p2;

	cin.get();
	return 0;
}
