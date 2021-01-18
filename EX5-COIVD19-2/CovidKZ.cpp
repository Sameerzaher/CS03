#include"CovidKZ.h"
#include<iostream>
using namespace std;
CovidKZ::CovidKZ()
{
    m_Genetic_sequence = NULL;
}
CovidKZ::CovidKZ(float Distribution_coefficient, int number_molecole_bio, bool is_vaccine, const char* Virus_serial,
    float effect_on_lung_function, const char* virus_origin_GB,
    float effect_on_liver_function, const char* virus_origin_SA,
    char* Genetic_sequence)
    :Covid19(Distribution_coefficient, number_molecole_bio, is_vaccine, Virus_serial),
    CovidGB(Distribution_coefficient, number_molecole_bio, is_vaccine, Virus_serial, effect_on_lung_function, virus_origin_GB),
    CovidSA(Distribution_coefficient, number_molecole_bio, is_vaccine, Virus_serial, effect_on_liver_function, virus_origin_SA),
    m_Genetic_sequence(Genetic_sequence)
{
    m_Genetic_sequence = new char[strlen(Genetic_sequence) + 1];
    strcpy(m_Genetic_sequence, Genetic_sequence);
}
CovidKZ::CovidKZ(const CovidKZ& covidKZ)
{
    setGenetic_sequence(covidKZ.getGenetic_sequence());

}
int CovidKZ::setGenetic_sequence(const char* Genetic_sequence)
{
    if (Genetic_sequence == NULL)
        return -1;

    m_Genetic_sequence = new char[strlen(Genetic_sequence) + 1];
    strcpy(m_Genetic_sequence, Genetic_sequence);
    return 1;
}
char* CovidKZ::getGenetic_sequence()
{
    return m_Genetic_sequence;
}
void CovidKZ::print()
{
    Covid19::print();
    cout << ", ";
    cout << "Lung Function " << CovidGB::getEffectOnLungFunction() <<
        ", country of origin GB virus: " << CovidGB::getVirusOrigin() <<
        ", liver function: " << CovidSA::getEffectOnLiverFunction() <<
        ", Country Of Origin SA Virus: " << CovidSA::getVirusOrigin();
    cout << ", Genetic sequence: " << m_Genetic_sequence << endl;
}
