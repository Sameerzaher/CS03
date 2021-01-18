#include"AnimalBasedSuperHero.h"
AnimalBasedSuperHero::AnimalBasedSuperHero():m_animal(NULL)
{

}
AnimalBasedSuperHero::AnimalBasedSuperHero(const char* name, double age, bool radioactive, const char* animal):SuperHero(name,age,radioactive), m_animal(NULL)
{
    setAnimal(animal);
}
AnimalBasedSuperHero::AnimalBasedSuperHero(const char* animal):m_animal(NULL)
{
    setAnimal(animal);
}
AnimalBasedSuperHero::AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero):SuperHero(animalBasedSuperHero.m_name,animalBasedSuperHero.m_age,animalBasedSuperHero.m_radioactive),m_animal(NULL)
{
    setAnimal(animalBasedSuperHero.getAnimal());
}
AnimalBasedSuperHero::~AnimalBasedSuperHero()
{
    delete[] m_animal;
}

void AnimalBasedSuperHero::setAnimal(const char* animal)
{
    if(m_animal != animal)
    {
        if(m_animal != NULL)
            delete[] m_animal;
        if(animal != NULL)
        {
            m_animal = new char[strlen(animal)+1];
            strcpy(m_animal,animal);
        }
        else
        {
            m_animal = NULL;
        }
    }
}
const char* AnimalBasedSuperHero::getAnimal() const
{
    return m_animal;
}

void AnimalBasedSuperHero::load(ifstream & in_file)
{
	SuperHero::load(in_file);
	int size;
	in_file.read((char*)& size, sizeof(size));
	m_animal = new char[size + 1];
	in_file.read(m_animal, size);
	m_animal[size] = '\0';
}

void AnimalBasedSuperHero::save(ofstream & out_file) const
{
	SuperHero::save(out_file);
	int size = strlen(m_animal);
	out_file.write((char*)& size, sizeof(size));
	out_file.write(m_animal, size);
}
