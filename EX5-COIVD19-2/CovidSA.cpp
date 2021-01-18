#include"CovidSA.h"
#include<iostream>

using namespace std;
CovidSA::CovidSA()
{
    m_effect_on_liver_function = 0;
    m_virus_origin = NULL;
}
CovidSA::CovidSA(float Distribution_coefficient, int number_molecole_bio, bool is_vaccine
    , const char* Virus_serial, float effect_on_liver_function, const char* virus_origin)
    :Covid19(Distribution_coefficient, number_molecole_bio, is_vaccine, Virus_serial), m_effect_on_liver_function(effect_on_liver_function)
{
    m_virus_origin = new char[strlen(virus_origin) + 1];
    strcpy(m_virus_origin, virus_origin);
}
CovidSA::CovidSA(const CovidSA& covidSA)
{
    setEffectOnLiverFunction(covidSA.getEffectOnLiverFunction());
    setVirusOrigin(covidSA.getVirusOrigin());
}
int CovidSA::setEffectOnLiverFunction(float effect_on_liver_function)
{
    if (effect_on_liver_function < 0)
        return -1;

    m_effect_on_liver_function = effect_on_liver_function;
    return 1;
}
int CovidSA::setVirusOrigin(const char* virus_origin)
{
    if (virus_origin == NULL)
        return -1;

    m_virus_origin = new char[strlen(virus_origin) + 1];
    strcpy(m_virus_origin, virus_origin);
    return 1;
}
float CovidSA::getEffectOnLiverFunction()
{
    return m_effect_on_liver_function;
}
char* CovidSA::getVirusOrigin()
{
    return m_virus_origin;
}
void CovidSA::print()
{
    Covid19::print();
    cout << " ";
    cout << "liver functions: " << m_effect_on_liver_function << ", " << "country of origin: " << m_virus_origin;
}