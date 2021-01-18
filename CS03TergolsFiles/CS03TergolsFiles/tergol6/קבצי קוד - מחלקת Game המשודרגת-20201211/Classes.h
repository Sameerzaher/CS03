#pragma once

#include <iostream>
using namespace std;

struct Position
{
	int m_x;
	int m_y;

	void Print()const
	{
		std::cout << "Player position: (" << m_x << "," << m_y << ")" << std::endl;
	}

	void setPos(int x = 0, int y = 0)
	{
		m_x = x;
		m_y = y;
	}
};


class Player
{
public:
	Player() { ++s_playerCount; }
	Player(const char* name, int rank, int x, int y);
	~Player() { --s_playerCount; }

public:
	void print() const;

	const char* getName()const		{ return m_name;		}
	int getRank()const				{ return m_rank;		}
	Position getPos()const			{ return m_pos;			}
	static int getPlayerCount()		{ return s_playerCount; }

	void setName(const char* name)	{ m_name = name;		}
	void setRank(int rank)			{ m_rank = rank;		}
	void setPos(Position pos)		{ m_pos = pos;			}

private:
	const char* m_name;
	int			m_rank;
	Position	m_pos;
	static int  s_playerCount;

	friend class Game;
	friend ostream& operator << (ostream& out, Player& game);

};

ostream& operator << (ostream& out, Player& player);
