#pragma once
#include "Coivd19.h"

class CovidSA : virtual public Covid19
{
private:
    float m_effect_on_liver_function;
    char* m_virus_origin;
public:
    CovidSA();
    CovidSA(float Distribution_coefficient, int number_molecole_bio, bool is_vaccine
        , const char* Virus_serial, float effect_on_liver_function, const char* virus_origin);
    CovidSA(const CovidSA& covidSA);
    ~CovidSA() { delete[] m_virus_origin;}

    int setEffectOnLiverFunction(float effect_on_liver_function);
    int setVirusOrigin(const char* virus_origin);
    float getEffectOnLiverFunction();
    char* getVirusOrigin();
    void print();

};

