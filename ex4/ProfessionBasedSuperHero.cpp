#include"ProfessionBasedSuperHero.h"
ProfessionBasedSuperHero::ProfessionBasedSuperHero():m_profession(0),m_yearsExperience(0)
{

}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* name, double age, bool radioactive, const char* profession, int yearsExperience):SuperHero(name,age,radioactive),m_profession(NULL),m_yearsExperience(0)
{
    setProfession(profession);
    setYearsExperience(yearsExperience);
}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* profession, int yearsExperience):m_profession(NULL),m_yearsExperience(0)
{
    setProfession(profession);
    setYearsExperience(yearsExperience);
}
ProfessionBasedSuperHero::ProfessionBasedSuperHero(const ProfessionBasedSuperHero & professionBasedSuperHero) :SuperHero(professionBasedSuperHero),m_profession(NULL), m_yearsExperience(0)
{
    setProfession(professionBasedSuperHero.getProfession());
	setYearsExperience(professionBasedSuperHero.getYearsExperience());
}
ProfessionBasedSuperHero::~ProfessionBasedSuperHero()
{
    delete[] m_profession;
}
void ProfessionBasedSuperHero::setProfession(const char* profession)
{
    if (m_profession != profession)
	{
		if (m_profession != NULL)
			delete[]m_profession;
		if (profession != NULL)
		{
			m_profession = new char[strlen(profession) + 1];
			strcpy(m_profession, profession);
		}
		else
			m_profession = NULL;
	}
}
void ProfessionBasedSuperHero::setYearsExperience(int yearsExperience)
{
    if(yearsExperience>=0)
       m_yearsExperience=yearsExperience;
}
int	ProfessionBasedSuperHero::getYearsExperience() const
{
    return m_yearsExperience;
}
void ProfessionBasedSuperHero::load(ifstream & in_file)
{
	SuperHero::load(in_file);
	int size;
	in_file.read((char*)& size, sizeof(size));
	if (m_profession != NULL)
		delete[] m_profession;
	m_profession = new char[size + 1];
	in_file.read(m_profession, size);
	_profession[size] = '\0';
	in_file.read((char*)& m_yearsExperience, sizeof(m_yearsExperience));
}
void ProfessionBasedSuperHero::save(ofstream & out_file) const
{
	SuperHero::save(out_file);
	int size = strlen(m_profession);
	out_file.write((char*)& size, sizeof(size));
	out_file.write(m_profession, size);
	out_file.write((char*)& m_yearsExperience, sizeof(m_yearsExperience));
}