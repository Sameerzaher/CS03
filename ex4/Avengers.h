#pragma once

#include "SuperHero.h"
#include "Spiderman.h"
#include "AnimalBasedSuperHero.h"
#include "ProfessionBasedSuperHero.h"
#include "CaptainAmerica.h"

class Avengers
{
public:
	Avengers();
	~Avengers();
	Avengers(char* str);
public:
	void setSuperHeros(SuperHero** superHeros, int size);
	void addSuperHero(SuperHero* superHero);
	SuperHero** getSuperHeros() const;
	void printAvengersTeam()const;
	void initiateTeamAttack(bool initiate);

	void saveType(ofstream& out, const SuperHero* hero) const;
	void save(ofstream& out) const;
	void load(ifstream& in);

private:
	SuperHero** m_superHeros;
	int			m_numSuperHeros;
	string		m_teamName;
};
ostream& operator<<(std::ostream& out, Avengers avengers);
