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
Game::Game(const Game & g)
{
	m_name = g.m_name;
	m_difficulty = g.m_difficulty;
	m_currLevel = g.m_currLevel;
	m_maxPlayerNum = g.m_maxPlayerNum;
	m_currPlayersNum = g.m_currPlayersNum;
	m_players = new Player[m_currPlayersNum];

	memcpy(m_players, g.m_players, m_currPlayersNum * sizeof(Player));
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
void Game::Print(ostream& out) const
{
	out << "Game info..." << std::endl;
	out << "Game name:" << m_name << std::endl;
	out << "Game difficulty:" << m_difficulty << std::endl;
	out << "Total Players: " << m_currPlayersNum << " printing players info" << std::endl;

	for (int i = 0; i < m_currPlayersNum; ++i)
	{
		out << "------------------------------" << std::endl;
		m_players[i].print();
	}
}
/*----------------------------------------------------------------------------------*/
Game & Game::operator=(const Game & game)
{
	m_name = game.m_name;
	m_difficulty = game.m_difficulty;
	m_currLevel = game.m_currLevel;
	m_currPlayersNum = game.m_currPlayersNum;
	m_maxPlayerNum = m_currPlayersNum;
	
	delete[] m_players;
	m_players = new Player[m_currPlayersNum];

	memcpy(m_players, game.m_players, m_currPlayersNum * sizeof(Player));

	return *this;
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
/*----------------------------------------------------------------------------------*/
ostream & operator<<(ostream & out, Game & game)
{
	game.Print(out);
	return out;
}
/*----------------------------------------------------------------------------------*/