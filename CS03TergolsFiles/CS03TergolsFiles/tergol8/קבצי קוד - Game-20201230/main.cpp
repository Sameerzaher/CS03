#include <iostream>
#include "Entity.h"
#include "Game.h"

using namespace std;

int main()
{
	Entity * e = new Entity();
	e->move(1, 1);
	cout << *e << endl;

	Player* p = new Player("Jony");
	p->move(1, 1);
	cout << *p << endl;

	Warlock* w = new Warlock();
	w->move(1, 1);
	cout << *w << endl;

	Monster* m = new Monster();
	m->move(1, 1);
	cout << *m << endl;

	SpecialPlayer* sp = new SpecialPlayer();
	sp->move(1, 1);
	cout << *sp << endl;

	float x = 5.5f;
	int y = (int)x;


	/*Polymorphism*/
	Entity* e1 = (Entity*)p;
	//Cout just the entity part - Change print to virtual to print player
	cout << *e1 << endl;
	e1->move(4, 4);


	Entity* e2 = dynamic_cast<Warlock*>(e1);
	//cout << *e2 << endl;

	Player* p2 = dynamic_cast<Player*>(e1);
	cout << *p2 << endl;

	//Player* p2 = (Player*)e1;

	/*------------------------------------------------------------*/
	{
		Game game; // Instantiation
		game.addNewEntity((Entity*)p);
		game.addNewEntity((Entity*)w);
		game.addNewEntity((Entity*)m);
		game.addNewEntity((Entity*)sp);
		game.Print();
	}
	///*------------------------------------------------------------*/
	//Position pos(2, 5);
	//game.moveEntity(2, pos);
	//game.Print();

	cin.get();
}