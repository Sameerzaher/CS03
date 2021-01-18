#include "Game.h"

/*----------------------------------------------------------------------------------*/
Game::Game()
{
	m_name				= "Main Game";
	m_difficulty		= 5;
	m_currLevel			= 1;
	m_currEntityNum		= 0;
	m_maxEntitySpace	= 3;
	m_Entities			= new Entity*[m_maxEntitySpace];
	memset(m_Entities, 0, sizeof(Entity*) * m_maxEntitySpace);
}
/*----------------------------------------------------------------------------------*/
Game::Game(const char * name, int dif, int level)
	:
	m_name( name ),
	m_difficulty( dif ),
	m_currLevel( level ),
	m_maxEntitySpace(3),
	m_currEntityNum(0)
{
	m_Entities = new Entity*[m_maxEntitySpace];
	memset(m_Entities, 0, sizeof(Entity*) *m_maxEntitySpace);
}
/*----------------------------------------------------------------------------------*/
Game::Game(const Game & g)
{
	m_name				= g.m_name;
	m_difficulty		= g.m_difficulty;
	m_currLevel			= g.m_currLevel;
	m_maxEntitySpace	= g.m_currEntityNum;
	m_currEntityNum		= g.m_currEntityNum;
	m_Entities			= new Entity*[m_currEntityNum];

	memcpy(m_Entities, g.m_Entities, m_currEntityNum * sizeof(Entity*));
}
/*----------------------------------------------------------------------------------*/
Game::~Game()
{
	for (int i = 0; i < m_currEntityNum; ++i)
		delete m_Entities[i];

	delete[] m_Entities;
}
/*----------------------------------------------------------------------------------*/
Game* Game::addNewEntity(Entity* e)
{
	if (m_currEntityNum == m_maxEntitySpace)
		doubleEntitySpace();

	m_Entities[m_currEntityNum] = createNewEntity(e);
	++m_currEntityNum;
	return this;
}
/*----------------------------------------------------------------------------------*/
Entity* Game::createNewEntity(Entity* e)
{
	SpecialPlayer* sp = dynamic_cast<SpecialPlayer*>(e);
	if (nullptr != sp)
	{
		sp->attack();
		return sp;
	}

	Player* p = dynamic_cast<Player*>(e);
	if (nullptr != p)
		return p;
	

	Warlock* w = dynamic_cast<Warlock*>(e);
	if (nullptr != w)
		return static_cast<Entity*>(w);


	Monster* m = dynamic_cast<Monster*>(e);
	if (nullptr != m)
		return m;

	
	return nullptr;
}
/*----------------------------------------------------------------------------------*/
void Game::moveEntity(int idx, Position pos)
{
	if (idx > m_currEntityNum || idx < 0)
		return;

	m_Entities[idx]->move(pos.m_x, pos.m_y);
}
/*----------------------------------------------------------------------------------*/
void Game::Print() const
{
	std::cout << "Game info..." << std::endl;
	std::cout << "Game name:" << m_name << std::endl;
	std::cout << "Game difficulty:" << m_difficulty << std::endl;
	std::cout << "Total Players: " << m_currEntityNum << " printing Entityies info" << std::endl;
	std::cout << "********************************************" << std::endl;
	for (int i = 0; i < m_currEntityNum; ++i)
	{
		m_Entities[i]->print(cout);
		std::cout << "------------------------------" << std::endl;
	}

	std::cout << "********************************************" << std::endl;
}
/*----------------------------------------------------------------------------------*/
Entity** Game::Entities() const
{
	return m_Entities;
}
/*----------------------------------------------------------------------------------*/
void Game::doubleEntitySpace()
{
	m_maxEntitySpace = m_currEntityNum * 2;
	Entity** tempEntity = new Entity*[m_maxEntitySpace];
	memcpy(tempEntity, m_Entities, m_currEntityNum * sizeof(Entity*));
	delete[] m_Entities;
	m_Entities = tempEntity;
}
