#include <iostream>

#include "ManagerDecorator.h"
#include "DesignerDecorator.h"
#include "CoderDecorator.h"
#include "TesterDecorator.h"


using namespace std;

/*
	Situacija:
		Turime įmone su darbuotojais, įvairūs darbuotojai gali atlikti
		skirtingus darbus, tarkime, kad tai IT įmonė, tad darbuotojas
		gali atlikti šiuos veiksmus; "Design, Code, Test". Tai yra tarsi
		mūsų Rolė. Kartais darbuotojai gali atlikti kelius veiksmus vienam projektui
		pvz gali projektuoti ir programuoti ar pan. Projektuotojai turi. Kiekvienas darbuotojas
		turi savybę "atlyginimas" ir speciali rolė "manager" gali ją sau keisti
		Taip pat "manager" rolė turi specialią funkciją kuri leidžia pakeisti
		atlyginimą kitam darbuotojui.
*/

int main(void)
{
	//Signle Decorator example
	cout << "Single decorator example...\n";
	Worker w0("Darbuotojas0", 3000);
	CoderDecorator cd0(&w0);
	cd0.work();
	cout << "\n\n";

	//Multiple Decorator example
	cout << "Multiple decorator example...\n";
	Worker w1("Darbuotojas1", 2500);
	CoderDecorator cd1(&w1);
	DesignerDecorator cddd1(&cd1);
	TesterDecorator cdddtd1(&cddd1);
	cdddtd1.work();
	cout << "\n\n";

	//Specific interface example
	cout << "Specific interface example...\n";
	Worker w2("Darbuotojas2", 4000);
	ManagerDecorator md2(&w2);
	DesignerDecorator dd2(&md2);
	WorkerDecorator *pmd2 = dd2.getRole("ManagerDecorator");
	if(pmd2 != NULL){
		cout << "This is manager, so giving a raise to " << w0.getName() << "...\n";
		((ManagerDecorator *)pmd2)->raiseWage(300, &w0);
	} else {
		cout << "ManagerDecorator not found...\n";
	}
	cout << "\n\n";

	return 0;
}
