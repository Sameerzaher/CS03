#pragma once
#include "CovidGB.h"
#include "CovidSA.h"

class CovidKZ : public CovidGB, public CovidSA
{
public:
	CovidKZ();
	CovidKZ(float Distribution_coefficient, int number_molecole_bio, bool is_vaccine, const char* Virus_serial,
		float effect_on_lung_function, const char* virus_origin_GB,
		float effect_on_liver_function, const char* virus_origin_SA,
		char* Genetic_sequence);
	CovidKZ(const CovidKZ& covidKZ);
	~CovidKZ() { delete[] m_Genetic_sequence; }

	int setGenetic_sequence(const char* Genetic_sequence);

	char* getGenetic_sequence();

	void print();

private:
	char* m_Genetic_sequence;
};