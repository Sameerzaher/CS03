#include <iostream>
#include "Classes.h"

using namespace std;


int main()
{
	{
		Player p1;
	}
	Player p2("Jony", 100, 0, 0);
	p2.print();
	/*p1.m_rank = 90;
	p1.initPlayer("Jony", 100, 0, 0);
	p1.print();
	
	Player* p2 = new Player;
	p2->initPlayer("Koby", 80, 5, 8);
	p2->print();*/


	cin.get();
	return 0;
}
