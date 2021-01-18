#pragma once
#include <iostream>
#include "Classes.h"

using namespace std;

class Game
{
public:
	Game();
	Game(const char* name, int dif, int level);
	Game(const Game& g);
	~Game();

public:
	void			addPlayer(const Player& p);
	void			movePlayer(int idx, Position& pos);
	const Player*	players() const;
	void			doublePlayerNum();

public:
	void			Print(ostream& out) const;
	void			setDifficulty(int dif) { m_difficulty = dif; }


public:
	Game & operator = (const Game& game);

private:
	const char*		m_name;
	int				m_difficulty;
	int				m_currLevel;
	int				m_maxPlayerNum;
	int				m_currPlayersNum;
	Player*			m_players;
};

ostream& operator << (ostream& out, Game& game);