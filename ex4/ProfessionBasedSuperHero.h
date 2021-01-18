#pragma once

#include "SuperHero.h"

class ProfessionBasedSuperHero : public SuperHero
{
public:
	ProfessionBasedSuperHero();
	ProfessionBasedSuperHero(const char* name, double age, bool radioactive, const char* profession, int yearsExperience);
	ProfessionBasedSuperHero(const char* profession, int yearsExperience);
	ProfessionBasedSuperHero(const ProfessionBasedSuperHero& professionBasedSuperHero);
	virtual ~ProfessionBasedSuperHero();


public:
	void setProfession(const char* profession);
	const char* getProfession() const { return m_profession; }
	void setYearsExperience(int yearsExperience);
	int	getYearsExperience() const;
	virtual void load(ifstream& in_file);
	virtual void save(ofstream& out_file) const;

protected:
	int		m_yearsExperience;
	char*	m_profession;
};
