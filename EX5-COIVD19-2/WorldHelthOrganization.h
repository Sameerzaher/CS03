#include <iostream>
#include "Coivd19.h"
#include "CovidGB.h"
#include "CovidSA.h"
#include "CovidKZ.h"
using namespace std;

class WorldHealthOrganization
{
private:
    Covid19** m_Pan_Array;
    int m_arr_size;
    char* m_country;
    int m_people_number;
    int m_sick_people;
    int m_virus_counter;

public:
    WorldHealthOrganization();
    WorldHealthOrganization(const char* country, int people_number,int sick_people, int virus_counter, Covid19** PandimicArray, int arraySize);
    WorldHealthOrganization(const WorldHealthOrganization& otherWHO);
    ~WorldHealthOrganization();

    //setters
    int setPandimicArray(Covid19** Pan_Array, int size);
    int setCountry(const char* country);
    int setPeopleNumber(int people_number);
    int setSickPeople(int sick_people);
    int setVirusCounter(int virus_counter);
    int setArrSize(int array_size);


    //getters
    Covid19** getPandimicArray();
    char* getCountry();
    int getPeopleNumber();
    int getSickPeople();
    int getVirusCounter();
    int getArrSize();



    //functions


    Covid19** addCovidtoPandimicArray(Covid19* cov19);

    int VirusCount();

    void operator ==(const WorldHealthOrganization& otherWHO);
    friend ostream& operator<<(ostream& os, WorldHealthOrganization& WHO);
    void print();
    int changeKZGenetic_sequence(int index, const char* Genetic_sequence);
};