#include"Avengers.h"
Avengers::Avengers():m_numSuperHeros(0),m_superHeros(NULL)
{

}
Avengers::Avengers(char* str)
{
	m_teamName=str;
}
Avengers::~Avengers()
{
    if(m_superHeros !=NULL)
    {
        for(int i=0;i<m_numSuperHeros;i++)
        {
            delete m_superHeros[i];
        }
        delete[] m_superHeros;
    }
}
void Avengers::setSuperHeros(SuperHero** superHeros, int size)
{
    
	m_numSuperHeros = size;
	m_superHeros = new SuperHero* [size];
	for (int i = 0; i < size; i++)
	{
		if (typeid(*superHeros[i]) == typeid(SuperHero))
		{
			m_superHeros[i] = new SuperHero(*superHeros[i]);
		}
		else if (typeid(*superHeros[i]) == typeid(ProfessionBasedSuperHero))
		{
			ProfessionBasedSuperHero * PB = dynamic_cast<ProfessionBasedSuperHero *>(superHeros[i]);
			m_superHeros[i] = new ProfessionBasedSuperHero(*PB);
		}

		else if (typeid(*superHeros[i]) == typeid(CaptainAmerica))
		{
			CaptainAmerica * CA = dynamic_cast<CaptainAmerica *>(superHeros[i]);
			m_superHeros[i] = new CaptainAmerica(*CA);
		}
		
		else if (typeid(*superHeros[i]) == typeid(AnimalBasedSuperHero))
		{
			AnimalBasedSuperHero * AB= dynamic_cast<AnimalBasedSuperHero *>(superHeros[i]);
			m_superHeros[i] = new AnimalBasedSuperHero(*AB);
		}

		else if (typeid(*superHeros[i]) == typeid(Spiderman))
		{
			Spiderman * SP = dynamic_cast<Spiderman *>(superHeros[i]);
			m_superHeros[i] = new Spiderman(*SP);
		}
	}
}
void Avengers::addSuperHero(SuperHero* superHero)
{
	int size=m_numSuperHeros;
	m_superHeros = new SuperHero* [size];
	int i=0;
    while(i<size)
	{
		if (typeid(superHero[i])==typeid(SuperHero))
		{
			m_superHeros[i] = new SuperHero(superHero[i]);
			i++;
		}
	else if (typeid(superHero[i]) == typeid(ProfessionBasedSuperHero))
		{
			ProfessionBasedSuperHero * PB = dynamic_cast<ProfessionBasedSuperHero *>(superHero[i]);
			m_superHeros[i] = new ProfessionBasedSuperHero(superHero[i]);
		}
	else if (typeid(superHero[i]) == typeid(CaptainAmerica))
		{
			
		}
	else if (typeid(superHero[i]) == typeid(AnimalBasedSuperHero ))
		{
			
		}
	else if (typeid(superHero[i]) == typeid(Spiderman))
		{
			
		}
	}
}
SuperHero** Avengers::getSuperHeros() const
{
    return m_superHeros;
}
void Avengers::printAvengersTeam()const
{
	for(int i=0;i<=sizeof(m_superHeros);i++)
	{
		if (typeid(m_superHeros[i]) == typeid(SuperHero))
		{
			cout<<"name"<<m_superHeros[i]->getName();
			cout<<"Age"<<m_superHeros[i]->getAge();
			cout<<"radioactive"<<m_superHeros[i]->getRadioactive();
		}
		 else if(typeid(m_superHeros[i]) == typeid(ProfessionBasedSuperHero))
		{
			ProfessionBasedSuperHero * PB = dynamic_cast<ProfessionBasedSuperHero *>(m_superHeros[i]);
			m_superHeros[i] = new ProfessionBasedSuperHero(*PB);
			cout<<"Year Experiance"<<PB->getYearsExperience();
			cout<<"Professional"<<PB->getProfession();
		}

		else if(typeid(m_superHeros[i]) == typeid(CaptainAmerica))
		{
			CaptainAmerica * CA = dynamic_cast<CaptainAmerica *>(m_superHeros[i]);
			m_superHeros[i] = new CaptainAmerica(*CA);
			cout<< "age Including Freezing"<<CA->getAgeIncludingFreezing();
		}
		else if(typeid(m_superHeros[i])==typeid(AnimalBasedSuperHero))
		{
			AnimalBasedSuperHero * AB= dynamic_cast<AnimalBasedSuperHero *>(m_superHeros[i]);
			m_superHeros[i] = new AnimalBasedSuperHero(*AB);
			cout<<"Animal"<<AB->getAnimal();
		}
		else if(typeid(m_superHeros[i])==typeid(Spiderman))
		{
			Spiderman * SP = static_cast<Spiderman *>(m_superHeros[i]);
			m_superHeros[i] = new Spiderman(*SP);
			cout<< "WebSize"<<SP->getWebSize();
		}
		
	}
}
void Avengers::initiateTeamAttack(bool initiate)
{
    
}
void Avengers::saveType(ofstream & out, const SuperHero * hero) const
{
	char type[3]="";
	type[2] = '\0';
	if (typeid(*hero)==typeid(const SuperHero))
		strcpy(type, "SH");
	else if (typeid(*hero) == typeid(const  ProfessionBasedSuperHero))
		strcpy(type, "PB");
	else if (typeid(*hero) == typeid(const  CaptainAmerica))
		strcpy(type, "CA");
	else if (typeid(*hero) == typeid(const  AnimalBasedSuperHero ))
		strcpy(type, "AB");
	else if (typeid(*hero) == typeid(const Spiderman ))
		strcpy(type, "SP");
	
	out.write(type, 2*sizeof(char));

}

void Avengers::save(ofstream & out) const
{
	out.write((char*)&m_numSuperHeros, sizeof(m_numSuperHeros));
	for (int i = 0; i < m_numSuperHeros; i++)
	{
		saveType(out, m_superHeros[i]);
		m_superHeros[i]->save(out);
	}
}

void Avengers::load(ifstream & in)
{
	in.read((char*)& m_numSuperHeros, sizeof(m_numSuperHeros));
	m_superHeros = new SuperHero*[m_numSuperHeros];
	for (int i = 0; i < m_numSuperHeros; i++)
	{
		char type[3];
		type[2] = '\0';
		in.read(type, 2 * sizeof(char));
		if (strcmp(type, "SH") == 0)
			m_superHeros[i] = new SuperHero();
		else if(strcmp(type, "PB") == 0)
			m_superHeros[i] = new ProfessionBasedSuperHero();
		else if (strcmp(type, "CA") == 0)
			m_superHeros[i] = new CaptainAmerica();
		else if (strcmp(type, "AB") == 0)
			m_superHeros[i] = new AnimalBasedSuperHero();
		else if (strcmp(type, "SP") == 0)
			m_superHeros[i] = new Spiderman();
		

	m_superHeros[i]->load(in);

	}

}
ostream& operator<<(std::ostream& out, Avengers avengers)
{
	avengers.printAvengersTeam();
	return out;
}
