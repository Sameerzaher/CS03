#pragma once

#include "ProfessionBasedSuperHero.h"
#include "SuperHero.h"

class CaptainAmerica : public ProfessionBasedSuperHero
{
public:
	CaptainAmerica();
	CaptainAmerica(const char* name, double age, bool radioactive, const char* profession, int yearsExperience, double ageIncludingFreezing);
	CaptainAmerica(const char* profession, int yearsExperience, double ageIncludingFreezing);
	CaptainAmerica(double ageIncludingFreezing);
	CaptainAmerica(const CaptainAmerica& captainAmerica);
	virtual ~CaptainAmerica();

public:
	double getAgeIncludingFreezing() const;
	void setAgeIncludingFreezing(double ageIncludingFreezing);


	virtual void load(ifstream& in_file);
	virtual void save(ofstream& out_file) const;

protected:
	double m_ageIncludingFreezing;
};
