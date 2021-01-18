#include "CovidGB.h"
#include<iostream>
using namespace std;

CoivdGB::CovidGB()
{
    m_effect_on_lung_function = 0;
    m_virus_origin = 0;
}
CoivdGB::CovidGB(float Distribution_coefficient, int number_molecole_bio, bool is_vaccine
    , const char* Virus_serial, float effect_on_lung_function, const char* virus_origin)
    :Covid19(Distribution_coefficient, number_molecole_bio, is_vaccine, Virus_serial)
    , m_effect_on_lung_function(effect_on_lung_function)
{
    m_virus_origin = new char[strlen(virus_origin) + 1];
    strcpy(m_virus_origin, virus_origin);

}
CoivdGB::CovidGB(const CovidGB& covidGB)
{
    setEffectOnLungFunction(covidGB.getEffectOnLungFunction());
    setVirusOrigin(covidGB.getVirusOrigin());
}
int CoivdGB::setEffectOnLungFunction(float effect_on_lung_function)
{
    if (effect_on_lung_function < 0)
        return -1;

    m_effect_on_lung_function = effect_on_lung_function;
    return 1;
}
int CoivdGB::::setVirusOrigin(const char* virus_origin)
{
    if (virus_origin == NULL)
        return -1;

    m_virus_origin = new char[strlen(virus_origin) + 1];
    strcpy(m_virus_origin, virus_origin);
    return 1;
}
float CoivdGB::getEffectOnLungFunction()
{
    return m_effect_on_lung_function;
}
char* CoivdGB::getVirusOrigin()
{
    return m_virus_origin;
}
void CoivdGB::print()
{
    Covid19::print();
    cout << " ";
    cout << "lung functions: " << m_effect_on_lung_function << ", " << "country of origin: " << m_virus_origin;
}
