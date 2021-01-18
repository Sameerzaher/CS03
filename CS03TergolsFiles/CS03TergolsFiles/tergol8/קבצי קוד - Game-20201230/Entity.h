#pragma once
#include <iostream>

using namespace std;


struct Position
{
	float m_x, m_y;
	
	Position(float x = 0.f, float y = 0.f) : m_x(x), m_y(y) {}
	void print(ostream& out) const
	{
		out << "(" << m_x << "," << m_y << ")" << endl;
	}

	void changePos(float offX, float offY)
	{
		m_x += offX;
		m_y += offY;
	}
};
/*------------------------------------------------------------------*/
class Entity
{
public:
	Entity() {};
	virtual ~Entity() {};

public:
	virtual void move(float offX, float offY);
	virtual void print(ostream& out) const;

protected:
	Position	m_pos;
};

ostream& operator << (ostream& out, const Entity& entity);

/*------------------------------------------------------------------*/
class Player : public Entity
{
public:
	Player(const char * name) : m_name(name) {}
	virtual ~Player() {}

public:
	virtual void move(float offX, float offY);
	virtual void print(ostream& out) const;
	

protected:
	const char* m_name;
};

ostream& operator << (ostream& out, const Player& player);
/*------------------------------------------------------------------*/
class Warlock : public Entity
{
public:
	Warlock() {}
	virtual ~Warlock() {}

public:
	virtual void move(float offX, float offY);
	virtual void print(ostream& out) const;

private:

};

ostream& operator << (ostream& out, const Warlock& war);
/*------------------------------------------------------------------*/
class Monster : public Entity
{
public:
	Monster() : m_rank(1000) {}
	virtual ~Monster() {}

public:
	virtual void print(ostream& out) const;

private:
	int m_rank;
};

ostream& operator << (ostream& out, const Monster& mon);
/*------------------------------------------------------------------*/
class SpecialPlayer : public Player
{
public:
	SpecialPlayer() : Player("Special Player"), m_weaponStrength(5) {}
	virtual ~SpecialPlayer() {}

public:
	virtual void print(ostream& out) const;
	void attack() { cout << "Special Player in attack mode!" << endl; }

public:
	int m_weaponStrength;
};

ostream& operator << (ostream& out, const SpecialPlayer& sp);
/*------------------------------------------------------------------*/