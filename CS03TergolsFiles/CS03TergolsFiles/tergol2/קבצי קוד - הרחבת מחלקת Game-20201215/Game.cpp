#include "Game.h"
#include "Classes.h"

/*----------------------------------------------------------------------------------*/
Game::Game()
{
	m_name = "Main Game";
	m_difficulty = 5;
	m_currLevel = 1;
	m_currPlayersNum = 0;
	m_maxPlayerNum = 1;
	m_players = new Player[m_maxPlayerNum];
}
/*----------------------------------------------------------------------------------*/
Game::Game(const char * name, int dif, int level)
	:
	m_name(name),
	m_difficulty(dif),
	m_currLevel(level)
{
	m_currPlayersNum = 0;
	m_maxPlayerNum = 1;
	m_players = new Player[m_maxPlayerNum];
}
/*----------------------------------------------------------------------------------*/
Game::~Game()
{
	delete[] m_players;
}
/*----------------------------------------------------------------------------------*/
void Game::addPlayer(const Player& p)
{
	if (m_currPlayersNum == m_maxPlayerNum)
		doublePlayerNum();

	//Copy the fields
	m_players[m_currPlayersNum].setName(p.getName());
	m_players[m_currPlayersNum].setRank(p.getRank());
	m_players[m_currPlayersNum].setPos(p.getPos());

	++m_currPlayersNum;
}
/*----------------------------------------------------------------------------------*/
void Game::movePlayer(int idx, Position& pos)
{
	if (idx > m_currPlayersNum || idx < 0)
		return;

	m_players[idx].m_pos.setPos(pos.m_x, pos.m_y);
}
/*----------------------------------------------------------------------------------*/
void Game::Print() const
{
	std::cout << "Game info..." << std::endl;
	std::cout << "Game name:" << m_name << std::endl;
	std::cout << "Game difficulty:" << m_difficulty << std::endl;
	std::cout << "Total Players: " << m_currPlayersNum << " printing players info" << std::endl;

	for (int i = 0; i < m_currPlayersNum; ++i)
	{
		std::cout << "------------------------------" << std::endl;
		m_players[i].print();
	}
}
/*----------------------------------------------------------------------------------*/
const Player* Game::players() const
{
	return m_players;
}
/*----------------------------------------------------------------------------------*/
void Game::doublePlayerNum()
{
	m_maxPlayerNum = m_maxPlayerNum * 2;
	Player* tempPlyers = new Player[m_maxPlayerNum];
	memcpy(tempPlyers, m_players, m_currPlayersNum * sizeof(Player));
	delete[] m_players;
	m_players = tempPlyers;
}