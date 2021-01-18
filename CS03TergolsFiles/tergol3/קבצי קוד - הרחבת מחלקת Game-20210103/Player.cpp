#include <iostream>
#include "Classes.h"

void Player::print() const
{
	std::cout << "Print player info..." << std::endl;
	std::cout << "Player name:" << m_name << std::endl;
	std::cout << "Player rank:" << m_rank << std::endl;
	m_pos.Print();
}


Player::Player(const char* name, int rank, int x, int y)
{
	m_name = name;
	m_rank = rank;
	m_pos.m_x = x;
	m_pos.m_y = y;
}