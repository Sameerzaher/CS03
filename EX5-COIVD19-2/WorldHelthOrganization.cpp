#include "WorldHelthOrganization.h"
#include "CovidGB.h"
#include <iostream>

WorldHealthOrganization::WorldHealthOrganization() : m_Pan_Array(NULL),
m_country(NULL),
m_arr_size(0),
m_people_number(0),
m_sick_people(0),
m_virus_counter(0)
{


}
WorldHealthOrganization::WorldHealthOrganization(const char* country,int people_number,
	int sick_people,int virus_counter,Covid19** PandimicArray,int arraySize)
	:m_Pan_Array(PandimicArray),
	m_arr_size(arraySize),
	 m_people_number(people_number),
	 m_sick_people(sick_people),
	 m_virus_counter(virus_counter)
{
	if (country == NULL)
	{
		m_country = NULL;
	}
	else
	{
		m_country = new char[strlen(country) + 1];
		strcpy(m_country, country);

	}
}
WorldHealthOrganization::WorldHealthOrganization(const WorldHealthOrganization& otherWHO)
{
	setPandimicArray(otherWHO.m_Pan_Array,otherWHO.m_arr_size);
	setCountry(otherWHO.m_country);
	setPeopleNumber(otherWHO.m_people_number);
	setSickPeople(otherWHO.m_sick_people);
	setVirusCounter(otherWHO.m_virus_counter);
	setArrSize(otherWHO.m_arr_size);
}
WorldHealthOrganization::~WorldHealthOrganization()
{

}
//setters
int WorldHealthOrganization::setArrSize(int array_size)
{
	m_arr_size = array_size;
	return 1;
}
int WorldHealthOrganization::setPandimicArray(Covid19** Pan_Array, int size)
{
	m_Pan_Array = new Covid19 * [size];
	m_arr_size = size;


	for (int i = 0; i < size; i++)
	{
		if (typeid(*Pan_Array[i]) == typeid(Covid19))
		{
			Covid19* cov19 = dynamic_cast<Covid19*>(Pan_Array[i]);
			m_Pan_Array[i] = new Covid19(*cov19);
		}

		if (typeid(*Pan_Array[i]) == typeid(CovidGB))
		{
			CovidGB* covGB = dynamic_cast<CovidGB*>(Pan_Array[i]);
			m_Pan_Array[i] = new CovidGB(*covGB);
		}

		if (typeid(*Pan_Array[i]) == typeid(CovidSA))
		{
			CovidSA* covSA = dynamic_cast<CovidSA*>(Pan_Array[i]);
			m_Pan_Array[i] = new CovidSA(*covSA);
		}
		if (typeid(*Pan_Array[i]) == typeid(CovidKZ))
		{
			CovidKZ* covKZ = dynamic_cast<CovidKZ*>(Pan_Array[i]);
			m_Pan_Array[i] = new CovidKZ(*covKZ);
		}
	}
}
int WorldHealthOrganization::setCountry(const char* country)
{
	if (country == NULL)
	{
		return -1;
	}
	m_country = new char[strlen(country) + 1];
	strcpy(m_country, country);
	return 1;

}
int WorldHealthOrganization::setPeopleNumber(int people_number)
{
	m_people_number = people_number;
	return 1;
}
int WorldHealthOrganization::setSickPeople(int sick_people)
{
	m_sick_people = sick_people;
	return 1;
}
int WorldHealthOrganization::setVirusCounter(int virus_counter)
{
	m_virus_counter = virus_counter;
	return 1;
}

//getters
int WorldHealthOrganization::getArrSize()
{
	return m_arr_size;
}
Covid19** WorldHealthOrganization::getPandimicArray()
{
	return m_Pan_Array;
}
char* WorldHealthOrganization::getCountry()
{
	return m_country;
}
int WorldHealthOrganization::getPeopleNumber()
{
	return m_people_number;
}
int WorldHealthOrganization::getSickPeople()
{
	return m_sick_people;
}
int WorldHealthOrganization::getVirusCounter()
{
	return m_virus_counter;
}
//functions
Covid19** WorldHealthOrganization::addCovidtoPandimicArray(Covid19* cov19)
{
	int size = sizeof(m_Pan_Array);
	Covid19** cov19;
	cov19 = new Covid19 [size+1];
	for(int i=0;i<size;i++)
	{
		if (typeid(cov19[i]) == typeid(Covid19))
		{
			m_Pan_Array[i];
		}
		else if (typeid(m_Pan_Array[i]) == typeid(CovidGB))
		{
			CovidGB* CovGB = dynamic_cast<CovidGB*>(m_Pan_Array[i]);
			m_Pan_Array[i] = new CovidGB(*CovGB);
		}
		else if (typeid(m_Pan_Array[i]) == typeid(CovidSA))
		{
			CovidSA* CovSA = dynamic_cast<CovidSA*>(m_Pan_Array[i]);
			m_Pan_Array[i] = new CovidSA(*CovSA);
		}
		else if (typeid(m_Pan_Array[i]) == typeid(CovidKZ))
		{
			CovidKZ* CovKZ = dynamic_cast<CovidKZ*>(m_Pan_Array[i]);
			m_Pan_Array[i] = new CovidKZ(*CovKZ);
		}
	}

}
int WorldHealthOrganization::VirusCount()
{
	if (m_arr_size == 0)
		return -1;

	int count = 0;
	for (int i = 0; i < m_arr_size; i++)
	{
		if (strcmp(m_Pan_Array[i]->getVirusSerial(), m_Pan_Array[i + 1]->getVirusSerial()) != 0)
			count++;
	}
	this->setVirusCounter(count);
	return 1;
}
void WorldHealthOrganization::operator ==(const WorldHealthOrganization& otherWHO)
{
	setPandimicArray(otherWHO.m_Pan_Array,otherWHO.m_arr_size);
	setCountry(otherWHO.m_country);
	setPeopleNumber(otherWHO.m_people_number);
	setSickPeople(otherWHO.m_sick_people);
	setVirusCounter(otherWHO.m_virus_counter);
	setArrSize(otherWHO.m_arr_size);
}
void WorldHealthOrganization::print()
{
	for (int i = 0; i <= getArrSize(); i++)
	{
		if (typeid(m_Pan_Array[i]) == typeid(Covid19))
		{
			m_Pan_Array[i]->print();
		}

		if (typeid(m_Pan_Array[i]) == typeid(CovidGB))
		{
			CovidGB* covGB = dynamic_cast<CovidGB*>(m_Pan_Array[i]);
			covGB->print();
		}
		if (typeid(m_Pan_Array[i]) == typeid(CovidSA))
		{
			CovidSA* covSA = dynamic_cast<CovidSA*>(m_Pan_Array[i]);
			covSA->print();
		}
		if (typeid(m_Pan_Array[i]) == typeid(CovidKZ))
		{
			CovidKZ* covKZ = dynamic_cast<CovidKZ*>(m_Pan_Array[i]);
			covKZ->print();
		}
		
	}
}
ostream& operator<<(ostream& os, WorldHealthOrganization& WHO)
{
	WHO.print();
	return os;
}
int WorldHealthOrganization::changeKZGenetic_sequence(int index, const char* Genetic_sequence) throw( const char*)
{
	if (typeid(m_Pan_Array[index]) == typeid(CovidGB))
	{
		 throw "unable to change code CovidGB does not support";
	}

	if (typeid(m_Pan_Array[index]) == typeid(CovidSA))
	{
		throw "unable to change code CovidSA does not support";
		return -1;
	}

	else if (typeid(m_Pan_Array[index]) == typeid(CovidKZ))
	{
		CovidKZ* covKZ = dynamic_cast<CovidKZ*>(m_Pan_Array[index]);
		covKZ->setGenetic_sequence(Genetic_sequence);
		m_Pan_Array[index] = new CovidKZ(*covKZ);
	}
	return 1;


}
