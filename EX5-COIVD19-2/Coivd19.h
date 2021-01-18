#pragma once 
#include <string>
class Covid19
{
private:
    float m_Distribution_coefficient;
    int m_number_molecole_bio;
    bool m_is_vaccine;
    char* m_Virus_serial;
public:
    Covid19();
    Covid19(float Distribution_coefficient, int number_molecole_bio, bool is_vaccine, const char* Virus_serial);
    Covid19(const Covid19& covid19);
    virtual ~Covid19() { delete m_Virus_serial; }
    int setDistributionCoefficient(float Distribution_coefficient);
    int setNumberMolecoleBio(int number_molecole_bio);
    int setIsVaccine(bool is_vaccine);
    int setVirusSerial(char* Virus_serial);
    float getDistributionCoefficient();
    int   getNumberMolecoleBio();
    bool getIsVaccine();
    char* getVirusSerial();
    void print();





};