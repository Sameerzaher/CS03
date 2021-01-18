#include "Avengers.h"
int main() {

	SuperHero* superArr[5];
	superArr[0] = new SuperHero("Clark Kent", 25);
	superArr[1] = new ProfessionBasedSuperHero("IronMan",38,false,"entrepreneur",18);
	superArr[2] = new AnimalBasedSuperHero("Scott Lang", 30, false, "Ant");
	superArr[3] = new CaptainAmerica("Steve Rogers", 22, true, "soldier", 75, 89);
	superArr[4] = new Spiderman("Peter Parker", 17, true, "spider", 2.3);

	
	Avengers team("Avengers");
	team.setSuperHeros(superArr, 5);
	cout << team << endl;
	team.addSuperHero(new AnimalBasedSuperHero("Batman", 35, false, "Bat"));//
	team.initiateTeamAttack();//
	team.printAvengersTeam();
	cout << team << endl;
	
	
	Avengers team6In;
	ofstream out_file("output.bin", ios::binary | ios::out);
	team6In.setSuperHeros(superArr, 6);
	team6In.save(out_file);
	out_file.close();


	Avengers team6Out;
	ifstream in_file("output.bin", ios::binary | ios::in);
	team6Out.load(in_file);
	in_file.close();

	//SuperHero
	if (strcmp(team6Out.getSuperHeros()[0]->getName(), "Clark Kent") != 0) {//5
		puts("Error in Avengers, superhero->getName()");
	}
	if (team6Out.getSuperHeros()[0]->getAge() != 25) {//5
		puts("Error in Avengers, superhero->getAge()");
	}
	if (team6Out.getSuperHeros()[0]->getRadioactive() != false) {//5
		puts("Error in Avengers, superhero->getRadioactive()");
	}

	//ProfessionBasedSuperHero
	if (strcmp(team6Out.getSuperHeros()[1]->getName(), "Tony Stark") != 0) {//5
		puts("Error in Avengers, ProfessionBasedSuperhero->getName()");
	}
	ProfessionBasedSuperHero* psh = dynamic_cast<ProfessionBasedSuperHero*>(team6Out.getSuperHeros()[1]);
	if (psh == NULL) {//15
		puts("Error when attempting dynamic cast ProfessionBasedSuperHero");
	}
	else {
		if (strcmp(psh->getProfession(), "entrepreneur") != 0) {//5
			puts("Error in avengers, ProfessionBasedSuperHero->getProfession()");
		}

		if (psh->getYearsExperience() != 18) {//5
			puts("Error in avengers, ProfessionBasedSuperHero->getYearsExperience()");
		}
	}
	//AnimalBasedSuperHero
	if (strcmp(team6Out.getSuperHeros()[2]->getName(), "Scott Lang") != 0) {
		puts("Error in Avengers, AnimalBasedSuperhero->getName()");//5
	}

	AnimalBasedSuperHero* absh = dynamic_cast<AnimalBasedSuperHero*>(team6Out.getSuperHeros()[2]);
	if (absh == NULL) {//10
		puts("Error in attempting dynamic_cast to AnimalBasedSUperHero");
	}
	else {
		if (strcmp(absh->getAnimal(), "Ant") != 0) {//5
			puts("Error in Avengers AnimalBasedSuperHero->getAnimal()");
		}
	}

	//CaptainAmerica
	if (strcmp(team6Out.getSuperHeros()[3]->getName(), "Steve Rogers") != 0) {//5
		puts("Error in Avengers, CaptainAmerica->getName()");
	}

	CaptainAmerica* cA = dynamic_cast<CaptainAmerica*>(team6Out.getSuperHeros()[3]);
	if (cA == NULL)//10
	{
		puts("Error in attempting dynamic cast to captain america");
	}
	else {
		if (cA->getAgeIncludingFreezing() != 89) {//5
			puts("Error in Avengers CaptainAmerica->getAgeIncludingFreezing()");
		}
	}

	//Spiderman
	if (strcmp(team6Out.getSuperHeros()[4]->getName(), "Peter Parker") != 0) {
		puts("Error in Avengers, Spiderman->getName()");//5
	}

	Spiderman* pSD = dynamic_cast<Spiderman*>(team6Out.getSuperHeros()[4]);
	if (pSD == NULL) {
		puts("Error in attempting dynamic cast Spiderman");//10
	}
	else {
		if (pSD->getWebSize() != 2.3) {
			puts("Error in Avengers Spiderman->getWebSize()");//5
		}
	}
	puts("done");

	return 0;
}
