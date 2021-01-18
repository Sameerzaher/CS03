#include"Spiderman.h"
Spiderman::Spiderman():m_webSize(0)
{
    
}
Spiderman::Spiderman(const char* name, double age, bool radioactive, const char* animal, double webSize):AnimalBasedSuperHero(name,age,radioactive,animal),m_webSize(0)
{
    setWebSize(webSize);
}
Spiderman::Spiderman(const char* animal, double webSize):AnimalBasedSuperHero(animal),m_webSize(0)
{
    setWebSize(webSize);
}
Spiderman::Spiderman(double webSize):m_webSize(0)
{
    setWebSize(webSize);
}
Spiderman::Spiderman(const Spiderman & spiderman) :AnimalBasedSuperHero(spiderman.m_name, spiderman.m_age , spiderman.m_radioactive,spiderman.m_animal), m_webSize(0)
{
    setWebSize(spiderman.getWebSize());
}
Spiderman::~Spiderman()
{

}
double Spiderman::getWebSize() const
{
    return m_webSize;
}
void Spiderman::setWebSize(double webSize)
{
    if(webSize>=0)
        m_webSize=webSize;
}
void Spiderman::load(ifstream & in_file)
{
	AnimalBasedSuperHero::load(in_file);
	in_file.read((char *)&m_webSize, sizeof(m_webSize));
}

void Spiderman::save(ofstream & out_file) const
{
	AnimalBasedSuperHero::save(out_file);
	out_file.write((char*)&m_webSize, sizeof(m_webSize));
}