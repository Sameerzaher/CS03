#include <iostream>
#include "Classes.h"
#include "Game.h"

using namespace std;


int main()
{
	cout << Player::getPlayerCount() << endl;

	Player p1("Jony", 100, 1, 1);
	Player* p2 = new Player("James", 55, 10, 15);
	cout << p1.getPlayerCount() << endl;
	cout << p2->getPlayerCount() << endl;

	p1.print();
	p2->print();

	cout << p1 << endl;
	cout << *p2 << endl;

	/*------------------------------------------------------------*/
	Game game; // Instantiation
	game.addPlayer(p1);
	game.addPlayer(*p2);
	game.addPlayer(*p2);
	game.Print(cout);
	cout << game << endl;

	//Calls Copy constructor
	Game gameCopy = game;
	Game gameCopy1(game);

	//Create new object defualt constructor
	Game game1;

	//Calls assignment operator and performs deep copy
	//Without assignment operator performs shallow copy like using
	//memset to copy the whole object into another one
	game1 = game;
	game1.Print(cout);
	cout << game1 << endl;
	/*------------------------------------------------------------*/

	delete p2;

	cin.get();
	return 0;
}
