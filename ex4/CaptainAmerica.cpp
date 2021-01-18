#include"CaptainAmerica.h"
CaptainAmerica::CaptainAmerica()
{

}
CaptainAmerica::CaptainAmerica(const char* name, double age, bool radioactive, const char* profession, int yearsExperience, double ageIncludingFreezing):ProfessionBasedSuperHero (name, age, radioactive,profession,yearsExperience),m_ageIncludingFreezing(0)
{
    setAgeIncludingFreezing(ageIncludingFreezing);
}
CaptainAmerica::CaptainAmerica(const char* profession, int yearsExperience, double ageIncludingFreezing):ProfessionBasedSuperHero(profession,yearsExperience),m_ageIncludingFreezing(0)
{
    setAgeIncludingFreezing(ageIncludingFreezing);
}
CaptainAmerica::CaptainAmerica(double ageIncludingFreezing):m_ageIncludingFreezing(0)
{
    setAgeIncludingFreezing(ageIncludingFreezing);
}
CaptainAmerica::CaptainAmerica(const CaptainAmerica& captainAmerica) :ProfessionBasedSuperHero(captainAmerica.m_name,captainAmerica.m_age,captainAmerica.m_radioactive,captainAmerica.m_profession, captainAmerica.m_yearsExperience), m_ageIncludingFreezing(0)
{
    setAgeIncludingFreezing(captainAmerica.getAgeIncludingFreezing());
}
CaptainAmerica::~CaptainAmerica()
{

}
double CaptainAmerica::getAgeIncludingFreezing() const
{
    return m_ageIncludingFreezing;
}
void CaptainAmerica::setAgeIncludingFreezing(double ageIncludingFreezing)
{
    if(ageIncludingFreezing>m_age)
        m_ageIncludingFreezing=ageIncludingFreezing;
}
void CaptainAmerica::load(ifstream & in_file)
{
	ProfessionBasedSuperHero::load(in_file);
	in_file.read((char*)&m_ageIncludingFreezing, sizeof(m_ageIncludingFreezing));
}

void CaptainAmerica::save(ofstream & out_file) const
{
	ProfessionBasedSuperHero::save(out_file);
	out_file.write((char*)&m_ageIncludingFreezing, sizeof(m_ageIncludingFreezing));
}