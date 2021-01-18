#pragma once
#include "Entity.h"

class Game
{
public:
	Game();
	Game(const char* name, int dif, int level);
	Game(const Game& g);
	virtual ~Game();

public:
	Game*		addNewEntity(Entity* e);
	void		moveEntity(int idx, Position pos);
	Entity**	Entities() const;
	void		doubleEntitySpace();

public:
	void		Print() const;
	void		setDifficulty(int dif) { m_difficulty = dif; }

private:
	Entity *	createNewEntity(Entity* e);
	
private:
	const char*		m_name;
	int				m_difficulty;
	int				m_currLevel;
	int				m_maxEntitySpace;
	int				m_currEntityNum;
	Entity**		m_Entities;
};
