#pragma once
#include"Coivd19.h"
class CovidGB : virtual public Covid19
{
private:
    float m_effect_on_lung_function;
    char* m_virus_origin;
public:
    CovidGB();
    CovidGB(float Distribution_coefficient, int number_molecole_bio, bool is_vaccine, const char* Virus_serial, float effect_on_lung_function, const char* virus_origin);
    CovidGB(const CovidGB& covidGB);
    ~CovidGB() { delete[] m_virus_origin; }


    int setEffectOnLungFunction(float effect_on_lung_function);
    int setVirusOrigin(const char* virus_origin);

    float getEffectOnLungFunction();
    char* getVirusOrigin();
    void print();

};