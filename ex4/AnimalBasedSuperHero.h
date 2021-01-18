#pragma once

#include "SuperHero.h"
class AnimalBasedSuperHero : public SuperHero
{
public:
	AnimalBasedSuperHero();
	AnimalBasedSuperHero(const char* name, double age, bool radioactive, const char* animal);
	AnimalBasedSuperHero(const char* animal);
	AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero);
	virtual ~AnimalBasedSuperHero();
	virtual void load(ifstream& in_file);
	virtual void save(ofstream& out_file) const;

public:
	void setAnimal(const char* animal);
	const char* getAnimal() const;


protected:
	char*	m_animal;
};
