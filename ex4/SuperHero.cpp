#include"SuperHero.h"
const char* SuperHero::getName() const
{
    return m_name;
}
double SuperHero::getAge() const
{
    return m_age;
}
bool SuperHero::getRadioactive() const
{
    return m_radioactive;
}
void SuperHero::setName(const char* name)
{
     if(m_name!= name)
     {
         if(m_name != NULL)
            delete []m_name;
            if(name !=NULL)
            {
                m_name = new char[strlen(name)+1];
                strcpy(m_name,name);
            }
            else
            {
                m_name = NULL;
            }
            
     }
}
void SuperHero::setAge(double age)
{
    if(age>=15 && age<=40)
    {
        m_age=age;
    }
}
void SuperHero::setRadioactive(bool radioactive)
{
    m_radioactive=radioactive;
}
SuperHero::SuperHero():m_name(NULL),m_radioactive(false),m_age(0)
{

}
SuperHero::SuperHero(const char* name, double age, bool radioactive=false):m_name(NULL)
{
    setAge(age);
    setName(name);
    setRadioactive(radioactive);
}
SuperHero::SuperHero(const SuperHero& superHero):m_name(NULL)
{
    setAge(superHero.getAge());
    setName(superHero.getName());
    setRadioactive(superHero.getRadioactive());

}
SuperHero::~SuperHero()
{
    if(m_name != NULL)
    delete[]m_name;
}
void SuperHero::load(ifstream& in_file)
{
    int size;
    in_file.read((char*)&size,sizeof(size));
    if(m_name != NULL)
        delete[]m_name;
    m_name= new char[size+1];
    in_file.read(m_name,size);
    m_name[size]='\0';
    in_file.read((char *)&m_age,sizeof(m_age));
    in_file.read((char *)&m_radioactive,sizeof(m_radioactive));

}
void SuperHero::save(ofstream& out_file) const
{
    int size = strlen(m_name);
	out_file.write((char *)&size, sizeof(size));
	out_file.write(m_name, size);
	out_file.write((char *)&m_age, sizeof(m_age));
	out_file.write((char *)& m_radioactive, sizeof(m_radioactive));
}