#pragma once

#include <iostream>

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
	Player() {}
	Player(const char* name, int rank, int x, int y);
	~Player() {}

public:
	void print() const;

	const char* getName()const		{ return m_name; }
	int getRank()const				{ return m_rank; }
	Position getPos()const			{ return m_pos;	 }

	void setName(const char* name)	{ m_name = name; }
	void setRank(int rank)			{ m_rank = rank; }
	void setPos(Position pos)		{ m_pos = pos;	 }

public:
	const char* m_name;
	int			m_rank;
	Position	m_pos;
};


