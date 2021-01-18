#include"Coivd19.h"
#include<iostream>
#include<string>

using namespace std;
Covid19::Covid19()
{
    m_Distribution_coefficient = 0;
    m_number_molecole_bio = 0;
    m_is_vaccine = false;
    m_virus_serial = NULL;

}
Covid19::Covid19(float Distribution_coefficient, int number_molecole_bio, bool is_vaccine, const char* Virus_serial)
{
    m_Distriburion_coefficient = Distribution_coefficient;
    m_number_molecole_bio = number_molecole_bio;
    m_is_vsccine = is_vaccine;
    m_virus_serial = new char[strlen(Virus_serial) + 1];
}
Covid19::Covid19(const Covid19& covid19)
{
    setDistributionCoefficient(covid19.getDistributionCoefficient());
    setNumberMolecoleBio(covid19.getNumberMolecoleBio());
    setIsVaccine(covid19.getIsVaccine());
    setVirusSerial(covid19.getVirusSerial());
}
int Covid19::setDistributionCoefficient(float Distribution_coefficient)
{
    if (Distribution_coefficient)
        return -1;
    m_Distribution_coefficient = Distribution_coefficient;
    return 1;

}
int Covid19::setNumberMolecoleBio(int number_molecole_bio)
{
    if (number_molecole_bio == 0)
        return -1;
    m_number_molecole_bio = number_molecole_bio;
    return 1;
}
int Covid19::setIsVaccine(bool is_vaccine)
{
    m_is_vaccine = is_vaccine;
    return 1;
}
int Covid19::setVirusSerial(char* Virus_serial)
{
    if (Virus_serial == NULL)
        return -1;
    m_serial = new char[strlen(Virus_serial + 1)];
    strcpy(m_Virus_serial, Virus_serial);
    return 1;
}
float Covid19::getDistributionCoefficient()
{
    return m_Distribution_coefficient;
}
int Covid19::getNumberMolecoleBio()
{
    return m_number_molecole_bio;
}
bool Covid19::getIsVaccine()
{
    return m_is_vaccine;
}
char* Covid19::getVirusSerial()
{
    return m_virus_serial;
}
void Covid19::print()
{
    cout << "R is: " << m_Distribution_coefficient << ", " << "Virus serial is:" << m_virus_serial << ", " << "vaccine?: " << m_is_vaccine << ", " << "Molecule Number: " << m_number_molecole_bio;
}