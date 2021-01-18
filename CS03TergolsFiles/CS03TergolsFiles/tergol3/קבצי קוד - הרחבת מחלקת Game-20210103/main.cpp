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

	/*------------------------------------------------------------*/

	delete p2;


	cin.get();
	return 0;
}
