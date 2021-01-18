#include <iostream>
#include "Classes.h"


int Player::s_playerCount = 0;

void Player::print() const
{
	std::cout << "Print player info..." << std::endl;
	std::cout << "Player name:" << m_name << std::endl;
	std::cout << "Player rank:" << m_rank << std::endl;
	m_pos.Print();
}
/*----------------------------------------------------------------------------------*/
Player::Player(const char* name, int rank, int x, int y)
{
	++s_playerCount;
	m_name = name;
	m_rank = rank;
	m_pos.m_x = x;
	m_pos.m_y = y;
}
/*----------------------------------------------------------------------------------*/
ostream & operator<<(ostream & out, Player & player)
{
	out << "Print player info..." << std::endl;
	out << "Player name:" << player.m_name << std::endl;
	out << "Player rank:" << player.m_rank << std::endl;
	player.m_pos.Print();

	return out;
}