#pragma once
#include "Classes.h"

class Game
{
public:
	Game();
	Game(const char* name, int dif, int level);
	~Game();

public:
	void			addPlayer(const Player& p);
	void			movePlayer(int idx, Position& pos);
	const Player*	players() const;
	void			doublePlayerNum();

public:
	void	Print() const;
	void	setDifficulty(int dif) { m_difficulty = dif; }


private:
	const char*		m_name;
	int				m_difficulty;
	int				m_currLevel;
	int				m_maxPlayerNum;
	int				m_currPlayersNum;
	Player*			m_players;
};